# ble_bridge_ui.py
# Install deps: pip install bleak

import asyncio
import threading
import socket
import tkinter as tk
from tkinter import scrolledtext
from datetime import datetime
from bleak import BleakScanner, BleakClient

# top of ble_bridge_ui.py — update these three lines
DEFAULT_SERVICE = "6e400001-b5a3-f393-e0a9-e50e24dcca9e"
DEFAULT_TX      = "6e400003-b5a3-f393-e0a9-e50e24dcca9e"
DEFAULT_RX      = "6e400002-b5a3-f393-e0a9-e50e24dcca9e"

class BLEBridgeApp:
    def __init__(self, root):
        self.root = root
        self.root.title("BLE Bridge")
        self.root.geometry("580x640")
        self.root.resizable(False, False)

        self.ble_client  = None
        self.unity_conn  = None
        self.tcp_server  = None
        self.loop        = None
        self.running     = False
        self.msg_count   = 0

        self._build_ui()

    def _build_ui(self):
        pad = dict(padx=10, pady=3)

        # ── Connection ───────────────────────────────────────
        tk.Label(self.root, text="Connection", font=("", 9, "bold"), anchor="w").pack(fill="x", padx=10, pady=(10,2))

        row1 = tk.Frame(self.root); row1.pack(fill="x", **pad)
        tk.Label(row1, text="Device name:", width=14, anchor="w").pack(side="left")
        self.device_name_var = tk.StringVar(value="CIRCUITPY")
        tk.Entry(row1, textvariable=self.device_name_var, width=18).pack(side="left", padx=4)
        tk.Label(row1, text="TCP port:", anchor="w").pack(side="left", padx=(12,0))
        self.port_var = tk.StringVar(value="5005")
        tk.Entry(row1, textvariable=self.port_var, width=6).pack(side="left", padx=4)
        self.status_label = tk.Label(row1, text="Disconnected", fg="red", width=14)
        self.status_label.pack(side="right")

        # ── UUIDs ────────────────────────────────────────────
        tk.Frame(self.root, height=1, bg="#ccc").pack(fill="x", padx=10, pady=6)
        tk.Label(self.root, text="UUIDs", font=("", 9, "bold"), anchor="w").pack(fill="x", padx=10, pady=(0,2))

        def uuid_row(label, default):
            f = tk.Frame(self.root); f.pack(fill="x", **pad)
            tk.Label(f, text=label, width=18, anchor="w").pack(side="left")
            var = tk.StringVar(value=default)
            tk.Entry(f, textvariable=var, width=40, font=("Courier", 11)).pack(side="left", padx=4)
            return var

        self.service_uuid_var = uuid_row("UART service:",   DEFAULT_SERVICE)
        self.tx_uuid_var      = uuid_row("TX (board→you):", DEFAULT_TX)
        self.rx_uuid_var      = uuid_row("RX (you→board):", DEFAULT_RX)

        btn_row = tk.Frame(self.root); btn_row.pack(fill="x", padx=10, pady=6)
        tk.Button(btn_row, text="Reset to NUS defaults", command=self._reset_uuids).pack(side="left")
        self.connect_btn = tk.Button(btn_row, text="Scan & Connect", command=self.start_connect,
                                     bg="#378ADD", fg="white", width=16)
        self.connect_btn.pack(side="right", padx=(6,0))
        self.disconnect_btn = tk.Button(btn_row, text="Disconnect", command=self.disconnect,
                                        state="disabled", width=12)
        self.disconnect_btn.pack(side="right")

        # ── Stats ────────────────────────────────────────────
        tk.Frame(self.root, height=1, bg="#ccc").pack(fill="x", padx=10, pady=4)
        stats = tk.Frame(self.root); stats.pack(fill="x", padx=10)
        self.last_val_label  = tk.Label(stats, text="Last value: —",       font=("Courier", 11))
        self.msg_count_label = tk.Label(stats, text="Messages: 0",         font=("Courier", 11))
        self.unity_label     = tk.Label(stats, text="Unity: not connected", font=("Courier", 11))
        self.last_val_label.pack(side="left", expand=True)
        self.msg_count_label.pack(side="left", expand=True)
        self.unity_label.pack(side="left", expand=True)

        # ── Log ──────────────────────────────────────────────
        tk.Frame(self.root, height=1, bg="#ccc").pack(fill="x", padx=10, pady=6)
        tk.Label(self.root, text="Message log", font=("", 9, "bold"), anchor="w").pack(fill="x", padx=10)
        self.log = scrolledtext.ScrolledText(self.root, height=14, font=("Courier", 11), state="disabled")
        self.log.pack(fill="both", expand=True, padx=10, pady=4)
        self.log.tag_config("sys", foreground="gray")
        self.log.tag_config("in",  foreground="#185FA5")
        self.log.tag_config("out", foreground="#3B6D11")
        self.log.tag_config("err", foreground="red")

        # ── Send commands ─────────────────────────────────────
        tk.Frame(self.root, height=1, bg="#ccc").pack(fill="x", padx=10, pady=4)
        cmd_row = tk.Frame(self.root); cmd_row.pack(fill="x", padx=10, pady=(0,10))
        tk.Button(cmd_row, text="LED on",  command=lambda: self.send_command("LED_ON"),  width=8).pack(side="left", padx=(0,4))
        tk.Button(cmd_row, text="LED off", command=lambda: self.send_command("LED_OFF"), width=8).pack(side="left", padx=(0,10))
        self.cmd_entry = tk.Entry(cmd_row, font=("Courier", 11))
        self.cmd_entry.pack(side="left", fill="x", expand=True, padx=(0,6))
        self.cmd_entry.bind("<Return>", lambda e: self.send_custom())
        tk.Button(cmd_row, text="Send", command=self.send_custom).pack(side="left")

    def _reset_uuids(self):
        self.service_uuid_var.set(DEFAULT_SERVICE)
        self.tx_uuid_var.set(DEFAULT_TX)
        self.rx_uuid_var.set(DEFAULT_RX)
        self.log_msg("UUIDs reset to NUS defaults.", "sys")

    # ── Logging ───────────────────────────────────────────────
    def log_msg(self, text, tag="sys"):
        ts     = datetime.now().strftime("%H:%M:%S")
        prefix = {"sys": "   ", "in": "IN ", "out": "OUT", "err": "ERR"}[tag]
        self.log.config(state="normal")
        self.log.insert("end", f"{ts}  {prefix}  {text}\n", tag)
        self.log.see("end")
        self.log.config(state="disabled")

    def set_status(self, text, color):
        self.status_label.config(text=text, fg=color)

    # ── Connect / Disconnect ──────────────────────────────────
    def start_connect(self):
        self.connect_btn.config(state="disabled")
        self.set_status("Scanning...", "orange")
        self.log_msg("Starting BLE scan...", "sys")
        threading.Thread(target=self._run_async_loop, daemon=True).start()

    def _run_async_loop(self):
        self.loop = asyncio.new_event_loop()
        asyncio.set_event_loop(self.loop)
        self.loop.run_until_complete(self._bridge_main())

    def disconnect(self):
        self.running = False
        if self.ble_client:
            asyncio.run_coroutine_threadsafe(self.ble_client.disconnect(), self.loop)
        self.root.after(0, self._on_disconnect)

    def _on_disconnect(self):
        self.set_status("Disconnected", "red")
        self.connect_btn.config(state="normal")
        self.disconnect_btn.config(state="disabled")
        self.unity_label.config(text="Unity: not connected")
        self.log_msg("Disconnected.", "sys")

    # ── BLE + TCP bridge ──────────────────────────────────────
    async def _bridge_main(self):
        name         = self.device_name_var.get()
        port         = int(self.port_var.get())
        service_uuid = self.service_uuid_var.get().strip()
        tx_uuid      = self.tx_uuid_var.get().strip()
        rx_uuid      = self.rx_uuid_var.get().strip()

        self.tcp_server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.tcp_server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.tcp_server.bind(("127.0.0.1", port))
        self.tcp_server.listen(1)
        self.tcp_server.setblocking(False)
        self.root.after(0, lambda: self.log_msg(f"TCP server listening on port {port}", "sys"))

        self.root.after(0, lambda: self.log_msg(f"Looking for '{name}'...", "sys"))
        device = await BleakScanner.find_device_by_name(name, timeout=10)
        if not device:
            self.root.after(0, lambda: self.log_msg(f"Device '{name}' not found.", "err"))
            self.root.after(0, lambda: self.connect_btn.config(state="normal"))
            self.root.after(0, lambda: self.set_status("Not found", "red"))
            return

        self.root.after(0, lambda: self.log_msg(f"Found: {device.name} ({device.address})", "sys"))
        self.root.after(0, lambda: self.log_msg(f"Using service: {service_uuid}", "sys"))
        self.root.after(0, lambda: self.log_msg(f"TX: {tx_uuid}", "sys"))
        self.root.after(0, lambda: self.log_msg(f"RX: {rx_uuid}", "sys"))

        async with BleakClient(device) as client:
            self.ble_client = client
            self.running = True

            def handle_rx(sender, data):
                msg = data.decode().strip()
                self.root.after(0, lambda m=msg: self._on_ble_message(m))

            await client.start_notify(tx_uuid, handle_rx)
            self.root.after(0, lambda: self.set_status("Connected", "green"))
            self.root.after(0, lambda: self.disconnect_btn.config(state="normal"))
            self.root.after(0, lambda: self.log_msg("BLE connected! Waiting for Unity...", "sys"))

            while self.running:
                if self.unity_conn is None:
                    try:
                        conn, addr = await asyncio.get_event_loop().run_in_executor(
                            None, self.tcp_server.accept)
                        conn.setblocking(False)
                        self.unity_conn = conn
                        self.root.after(0, lambda: self.unity_label.config(text="Unity: connected"))
                        self.root.after(0, lambda: self.log_msg("Unity connected", "sys"))
                    except BlockingIOError:
                        pass

                if self.unity_conn:
                    try:
                        data = await asyncio.get_event_loop().run_in_executor(
                            None, self.unity_conn.recv, 64)
                        if data:
                            cmd = data.decode().strip()
                            self.root.after(0, lambda c=cmd: self.log_msg(c, "out"))
                            await client.write_gatt_char(rx_uuid, (cmd + "\n").encode())
                    except (BlockingIOError, OSError):
                        pass

                await asyncio.sleep(0.05)

        self.root.after(0, self._on_disconnect)

    def _on_ble_message(self, msg):
        self.msg_count += 1
        self.last_val_label.config(text=f"Last value: {msg}")
        self.msg_count_label.config(text=f"Messages: {self.msg_count}")
        self.log_msg(msg, "in")
        if self.unity_conn:
            try:
                self.unity_conn.sendall((msg + "\n").encode())
            except OSError:
                self.unity_conn = None
                self.root.after(0, lambda: self.unity_label.config(text="Unity: disconnected"))

    # ── Send commands ─────────────────────────────────────────
    def send_command(self, cmd):
        if not self.ble_client or not self.running:
            self.log_msg("Not connected.", "err"); return
        rx_uuid = self.rx_uuid_var.get().strip()
        self.log_msg(cmd, "out")
        asyncio.run_coroutine_threadsafe(
            self.ble_client.write_gatt_char(rx_uuid, (cmd + "\n").encode()), self.loop)

    def send_custom(self):
        cmd = self.cmd_entry.get().strip()
        if cmd:
            self.cmd_entry.delete(0, "end")
            self.send_command(cmd)

if __name__ == "__main__":
    root = tk.Tk()
    app = BLEBridgeApp(root)
    root.mainloop()