// WindowsBLEManager.cs
// Requires: Unity 2019+, Build Target = PC, IL2CPP scripting backend
// Player Settings → Capabilities: enable "Bluetooth"

using UnityEngine;
using UnityEngine.UI;
using TMPro;

#if WINDOWS_UWP
using Windows.Devices.Bluetooth;
using Windows.Devices.Bluetooth.Advertisement;
using Windows.Devices.Bluetooth.GenericAttributeProfile;
using Windows.Storage.Streams;
using System;
#endif

public class WindowsBLEManager : MonoBehaviour
{
    [Header("UI")]
    [SerializeField] private Button ledOnButton;
    [SerializeField] private Button ledOffButton;
    [SerializeField] private Button connectToggleButton;
    [SerializeField] private TMP_Text bleMessageText;

    [Header("Live Data")]
    public int proximityValue = 0;

#if WINDOWS_UWP
    private BluetoothLEAdvertisementWatcher watcher;
    private GattCharacteristic txCharacteristic; // board → Unity
    private GattCharacteristic rxCharacteristic; // Unity → board
    private bool connected = false;

    private static readonly Guid SERVICE_UUID =
        new Guid("6e400001-b5b4-f393-e0a9-e50e24dcca9e");
    private static readonly Guid TX_UUID =
        new Guid("6e400003-b5b4-f393-e0a9-e50e24dcca9e");
    private static readonly Guid RX_UUID =
        new Guid("6e400002-b5b4-f393-e0a9-e50e24dcca9e");

    private int pendingValue = -1;
    private string pendingMessage = null;
    private readonly object valueLock = new object();

    void Start()
    {
        if (ledOnButton)        ledOnButton.onClick.AddListener(SendLEDOn);
        if (ledOffButton)       ledOffButton.onClick.AddListener(SendLEDOff);
        if (connectToggleButton) connectToggleButton.onClick.AddListener(ToggleConnection);
        UpdateConnectButtonLabel();
    }

    private void UpdateConnectButtonLabel()
    {
        if (connectToggleButton == null) return;
        var label = connectToggleButton.GetComponentInChildren<TMP_Text>();
        if (label) label.text = connected ? "Disconnect" : "Connect";
    }

    public void ToggleConnection()
    {
        if (connected) Disconnect();
        else Connect();
    }

    public void Connect()
    {
        if (!connected)
        {
            StartScanning();
            UpdateConnectButtonLabel();
        }
    }

    public void Disconnect()
    {
        if (!connected) return;
        watcher?.Stop();
        txCharacteristic = null;
        rxCharacteristic = null;
        connected = false;
        Debug.Log("BLE Disconnected.");
        UpdateConnectButtonLabel();
    }

    void StartScanning()
    {
        Debug.Log("Scanning for BLE devices...");
        watcher = new BluetoothLEAdvertisementWatcher();
        watcher.Received += OnAdvertisementReceived;
        watcher.Start();
    }

    private async void OnAdvertisementReceived(
        BluetoothLEAdvertisementWatcher sender,
        BluetoothLEAdvertisementReceivedEventArgs args)
    {
        // Filter by local name — CircuitPython default is "CIRCUITPY"
        string name = args.Advertisement.LocalName;
        if (string.IsNullOrEmpty(name) || !name.Contains("CIRCUITPY")) return;
        if (connected) return;

        Debug.Log($"Found device: {name}");
        watcher.Stop();

        var bleDevice = await BluetoothLEDevice.FromBluetoothAddressAsync(args.BluetoothAddress);
        if (bleDevice == null) { Debug.LogError("Could not connect."); return; }

        var servicesResult = await bleDevice.GetGattServicesForUuidAsync(SERVICE_UUID);
        if (servicesResult.Status != GattCommunicationStatus.Success)
        {
            Debug.LogError("NUS service not found.");
            return;
        }

        var service = servicesResult.Services[0];

        // Get TX (board → Unity) — subscribe to notifications
        var txResult = await service.GetCharacteristicsForUuidAsync(TX_UUID);
        txCharacteristic = txResult.Characteristics[0];
        await txCharacteristic.WriteClientCharacteristicConfigurationDescriptorAsync(
            GattClientCharacteristicConfigurationDescriptorValue.Notify);
        txCharacteristic.ValueChanged += OnValueChanged;

        // Get RX (Unity → board) — for sending commands
        var rxResult = await service.GetCharacteristicsForUuidAsync(RX_UUID);
        rxCharacteristic = rxResult.Characteristics[0];

        connected = true;
        Debug.Log("BLE Connected and subscribed!");
        lock (valueLock) { pendingMessage = null; }
        UnityEngine.WSA.Application.InvokeOnAppThread(UpdateConnectButtonLabel, false);
    }

    private void OnValueChanged(GattCharacteristic sender, GattValueChangedEventArgs args)
    {
        var reader = DataReader.FromBuffer(args.CharacteristicValue);
        string raw = reader.ReadString(args.CharacteristicValue.Length).Trim();

        lock (valueLock) { pendingMessage = raw; }

        if (int.TryParse(raw, out int val))
        {
            lock (valueLock) { pendingValue = val; }
        }
    }

    public async void SendLEDOn()  => await SendCommand("LED_ON");
    public async void SendLEDOff() => await SendCommand("LED_OFF");

    private async System.Threading.Tasks.Task SendCommand(string cmd)
    {
        if (rxCharacteristic == null) return;
        var writer = new DataWriter();
        writer.WriteString(cmd + "\n");
        await rxCharacteristic.WriteValueAsync(writer.DetachBuffer());
    }

    void Update()
    {
        // Move data from BLE thread → Unity main thread
        lock (valueLock)
        {
            if (pendingMessage != null)
            {
                if (bleMessageText) bleMessageText.text = pendingMessage;
                pendingMessage = null;
            }

            if (pendingValue >= 0)
            {
                proximityValue = pendingValue;
                OnProximityChanged(proximityValue);
                pendingValue = -1;
            }
        }
    }

    void OnProximityChanged(int value)
    {
        // 🔧 YOUR GAME LOGIC HERE
        Debug.Log($"Proximity: {value}");
        // Example: scale an object
        // target.transform.localScale = Vector3.one * (value / 255f * 3f);
    }

    void OnDestroy()
    {
        watcher?.Stop();
        txCharacteristic = null;
        rxCharacteristic = null;
    }
#else
    void Start() => Debug.LogWarning(
        "Windows BLE only works in UWP builds or Windows Standalone with IL2CPP.");
#endif
}