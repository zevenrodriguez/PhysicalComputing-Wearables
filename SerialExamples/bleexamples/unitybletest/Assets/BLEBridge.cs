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
    public Button ledOnButton;
    public Button ledOffButton;

    [Header("Live Data")]
    public int proximityValue = 0;

    private TcpClient client;
    private NetworkStream stream;
    private Thread receiveThread;
    private string latestMessage = "";
    private readonly object msgLock = new object();
    private bool running = false;
    private bool connected = false;

    void Start()
    {
        // Wire up buttons
        connectButton.onClick.AddListener(OnConnectPressed);
        ledOnButton.onClick.AddListener(SendLEDOn);
        ledOffButton.onClick.AddListener(SendLEDOff);

        // LED buttons disabled until connected
        ledOnButton.interactable  = false;
        ledOffButton.interactable = false;

        UpdateConnectButton(false);
    }

    // ── Connect / Disconnect ──────────────────────────────────
    void OnConnectPressed()
    {
        if (!connected)
            Connect();
        else
            Disconnect();
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
            ledOnButton.interactable  = true;
            ledOffButton.interactable = true;
            proximityText.text = "Connected — waiting for data...";
            Debug.Log("Connected to BLE bridge!");
        }
        catch (System.Exception e)
        {
            proximityText.text = $"Failed to connect: {e.Message}\nIs the Python bridge running?";
            Debug.LogWarning($"Bridge connection failed: {e.Message}");
        }
    }

    void Disconnect()
    {
        running   = false;
        connected = false;
        stream?.Close();
        client?.Close();
        UpdateConnectButton(false);
        ledOnButton.interactable  = false;
        ledOffButton.interactable = false;
        proximityText.text = "Disconnected.";
    }

    void UpdateConnectButton(bool isConnected)
    {
        connectButtonText.text = isConnected ? "Disconnect" : "Connect";
    }

    // ── Receive loop (background thread) ─────────────────────
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

        if (!string.IsNullOrEmpty(msg) && int.TryParse(msg, out int val))
        {
            proximityValue     = val;
            proximityText.text = $"Proximity: {val}";
            OnProximityChanged(val);
        }
    }

    void OnProximityChanged(int value)
    {
        // 🔧 Add your game logic here later
    }

    // ── LED commands ──────────────────────────────────────────
    public void SendLEDOn()  => SendCommand("LED_ON");
    public void SendLEDOff() => SendCommand("LED_OFF");

    void SendCommand(string cmd)
    {
        if (stream == null || !connected) return;
        byte[] data = Encoding.UTF8.GetBytes(cmd + "\n");
        stream.Write(data, 0, data.Length);
    }

    void OnDestroy()
    {
        running = false;
        stream?.Close();
        client?.Close();
    }
}