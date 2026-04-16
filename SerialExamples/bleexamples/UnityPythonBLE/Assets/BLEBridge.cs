// BLEBridge.cs
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Net.Sockets;
using System.Text;
using System.Threading;

public class BLEBridge : MonoBehaviour
{
    [Header("Bridge Settings")]
    public string host = "127.0.0.1";
    public int port = 5005;

    [Header("UI References")]
    public Button connectButton;
    public TMP_Text connectButtonText;
    public TMP_Text proximityText;
    public TMP_Text bleStatusText;   // new — e.g. "Board: Connected"
    public Button ledOnButton;
    public Button ledOffButton;

    [Header("Live Data")]
    public int proximityValue = 0;

    private TcpClient client;
    private NetworkStream stream;
    private Thread receiveThread;
    private string latestMessage = "";
    private readonly object msgLock = new object();
    private bool running   = false;
    private bool connected = false;
    private bool bleReady  = false;  // true only when board is connected

    void Start()
    {
        connectButton.onClick.AddListener(OnConnectPressed);
        ledOnButton.onClick.AddListener(SendLEDOn);
        ledOffButton.onClick.AddListener(SendLEDOff);

        ledOnButton.interactable  = false;
        ledOffButton.interactable = false;

        UpdateConnectButton(false);
        UpdateBLEStatus(false);
    }

    // ── Connect / Disconnect ──────────────────────────────────
    void OnConnectPressed()
    {
        if (!connected) Connect();
        else Disconnect();
    }

    void Connect()
    {
        try
        {
            client  = new TcpClient(host, port);
            stream  = client.GetStream();
            running = true;
            receiveThread = new Thread(ReceiveLoop) { IsBackground = true };
            receiveThread.Start();
            connected = true;
            UpdateConnectButton(true);
            proximityText.text = "Connected to bridge — waiting for board...";
            Debug.Log("Connected to Python bridge!");
        }
        catch (System.Exception e)
        {
            proximityText.text = $"Bridge not found: {e.Message}\nIs the Python bridge running?";
        }
    }

    void Disconnect()
    {
        running   = false;
        connected = false;
        bleReady  = false;
        stream?.Close();
        client?.Close();
        UpdateConnectButton(false);
        UpdateBLEStatus(false);
        ledOnButton.interactable  = false;
        ledOffButton.interactable = false;
        proximityText.text = "Disconnected.";
    }

    void UpdateConnectButton(bool isConnected)
    {
        connectButtonText.text = isConnected ? "Disconnect" : "Connect to Bridge";
    }

    void UpdateBLEStatus(bool isReady)
    {
        bleReady = isReady;
        ledOnButton.interactable  = isReady;
        ledOffButton.interactable = isReady;

        if (bleStatusText != null)
            bleStatusText.text = isReady ? "Board: Connected" : "Board: Not connected";
    }

    // ── Receive loop ──────────────────────────────────────────
    void ReceiveLoop()
    {
        byte[] buffer  = new byte[256];
        string partial = "";
        while (running)
        {
            try
            {
                int count = stream.Read(buffer, 0, buffer.Length);
                if (count > 0)
                {
                    partial += Encoding.UTF8.GetString(buffer, 0, count);
                    int nl;
                    while ((nl = partial.IndexOf('\n')) >= 0)
                    {
                        string line = partial.Substring(0, nl).Trim();
                        partial     = partial.Substring(nl + 1);
                        lock (msgLock) { latestMessage = line; }
                    }
                }
            }
            catch { break; }
        }
    }

    // ── Main thread update ────────────────────────────────────
    void Update()
    {
        string msg;
        lock (msgLock)
        {
            msg = latestMessage;
            latestMessage = "";
        }

        if (string.IsNullOrEmpty(msg)) return;

        // Handle status messages from the bridge
        if (msg.StartsWith("STATUS:"))
        {
            if (msg == "STATUS:BLE_CONNECTED")
                UpdateBLEStatus(true);
            else if (msg == "STATUS:BLE_DISCONNECTED")
                UpdateBLEStatus(false);
            return;
        }

        // Handle proximity data
        if (int.TryParse(msg, out int val))
        {
            proximityValue     = val;
            proximityText.text = $"Proximity: {val}";
            OnProximityChanged(val);
        }
    }

    void OnProximityChanged(int value)
    {
        // 🔧 Your game logic here
    }

    // ── LED commands ──────────────────────────────────────────
    public void SendLEDOn()  => SendCommand("LED_ON");
    public void SendLEDOff() => SendCommand("LED_OFF");

    void SendCommand(string cmd)
    {
        if (stream == null || !bleReady) return;  // blocks if board not connected
        byte[] data = Encoding.UTF8.GetBytes(cmd + "\n");
        stream.Write(data, 0, data.length);
    }

    void OnDestroy()
    {
        running = false;
        stream?.Close();
        client?.Close();
    }
}