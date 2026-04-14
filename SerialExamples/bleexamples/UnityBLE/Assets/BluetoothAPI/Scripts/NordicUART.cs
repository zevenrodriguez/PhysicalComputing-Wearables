using System;
using System.Collections.Generic;
using System.Text;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Android;
using TMPro;
using ArduinoBluetoothAPI;

/// <summary>
/// Nordic UART Service (NUS) BLE — CircuitPython APDS9960 proximity demo
///
/// Receives proximity integers from the sensor and moves a sphere on the Z axis.
/// Sends "LED_ON" / "LED_OFF" to toggle the onboard LED.
///
/// Service UUID : 6e400001-b5a3-f393-e0a9-e50e24dcca9e
/// RX Char UUID : 6e400002  (Unity -> Device, write)
/// TX Char UUID : 6e400003  (Device -> Unity, notify)
/// </summary>
public class NordicUART : MonoBehaviour
{
    // ── UUIDs ──────────────────────────────────────────────────────────────
    private const string SERVICE_UUID = "6e400001-b5a3-f393-e0a9-e50e24dcca9e";
    private const string RX_UUID      = "6e400002-b5a3-f393-e0a9-e50e24dcca9e";
    private const string TX_UUID      = "6e400003-b5a3-f393-e0a9-e50e24dcca9e";

    // ── Inspector fields ───────────────────────────────────────────────────
    [Tooltip("Advertised BLE device name.")]
    public string deviceName = "Arduino";

    [Header("Sphere")]
    [Tooltip("The sphere to move forward/back based on proximity.")]
    public Transform sphere;

    [Tooltip("Proximity range from the sensor (0–255 typical).")]
    public float proximityMin = 0f;
    public float proximityMax = 255f;

    [Tooltip("Z-axis world positions mapped to min/max proximity.")]
    public float zNear = 5f;   // sphere position when object is close
    public float zFar  = -5f;  // sphere position when object is far

    [Tooltip("How fast the sphere moves toward its target.")]
    public float smoothSpeed = 5f;

    [Header("Optional UI")]
    public TMP_Text  statusText;
    public TMP_Text  receivedText;
    public Button    ledButton;
    public TMP_Text  ledButtonLabel;
    public TMP_Text  logText;

    [Tooltip("Max number of log lines shown on screen.")]
    public int maxLogLines = 15;

    // ── Private state ──────────────────────────────────────────────────────
    private BluetoothHelper               _helper;
    private BluetoothHelperCharacteristic _rxChar;
    private BluetoothHelperCharacteristic _txChar;

    private float  _targetZ;
    private bool   _ledOn = false;
    private string _receiveBuffer = "";
    private readonly List<string> _logLines = new List<string>();

    // ── Unity lifecycle ────────────────────────────────────────────────────
    private void Start()
    {
        _rxChar = new BluetoothHelperCharacteristic(RX_UUID);
        _rxChar.setService(SERVICE_UUID);

        _txChar = new BluetoothHelperCharacteristic(TX_UUID);
        _txChar.setService(SERVICE_UUID);

        if (sphere != null)
            _targetZ = sphere.position.z;

        BluetoothHelper.BLE = true;

        try
        {
            _helper = string.IsNullOrEmpty(deviceName)
                ? BluetoothHelper.GetInstance()
                : BluetoothHelper.GetInstance(deviceName);
        }
        catch (BluetoothHelper.BlueToothNotEnabledException)
        {
            SetStatus("Bluetooth not enabled — please turn on Bluetooth");
            return;
        }
        catch (Exception ex)
        {
            SetStatus($"Bluetooth error: {ex.Message}");
            Debug.LogError($"[NUS] Bluetooth init error: {ex.Message}");
            return;
        }

        _helper.OnScanEnded              += OnScanEnded;
        _helper.OnConnected              += OnConnected;
        _helper.OnConnectionFailed       += OnConnectionFailed;
        _helper.OnCharacteristicChanged  += OnCharacteristicChanged;
        _helper.OnCharacteristicNotFound += OnCharacteristicNotFound;
        _helper.OnServiceNotFound        += OnServiceNotFound;

        if (ledButton != null)
            ledButton.onClick.AddListener(ToggleLED);

        UpdateLedButtonLabel();

        // Request runtime permissions (required on Android 6+)
        if (!Permission.HasUserAuthorizedPermission(Permission.CoarseLocation))
            Permission.RequestUserPermission(Permission.CoarseLocation);
        if (!Permission.HasUserAuthorizedPermission(Permission.FineLocation))
            Permission.RequestUserPermission(Permission.FineLocation);

        StartScan();
    }

    private void Update()
    {
        // Smoothly move the sphere toward the target Z position
        if (sphere == null) return;
        Vector3 pos = sphere.position;
        pos.z = Mathf.Lerp(pos.z, _targetZ, Time.deltaTime * smoothSpeed);
        sphere.position = pos;
    }

    private void OnDestroy()
    {
        if (_helper == null) return;

        _helper.OnScanEnded              -= OnScanEnded;
        _helper.OnConnected              -= OnConnected;
        _helper.OnConnectionFailed       -= OnConnectionFailed;
        _helper.OnCharacteristicChanged  -= OnCharacteristicChanged;
        _helper.OnCharacteristicNotFound -= OnCharacteristicNotFound;
        _helper.OnServiceNotFound        -= OnServiceNotFound;

        _helper.Disconnect();
    }

    // ── BluetoothHelper events ─────────────────────────────────────────────

    private void StartScan()
    {
        SetStatus("Scanning...");
        bool started = _helper.ScanNearbyDevices();
        if (!started)
        {
            Debug.LogWarning("[NUS] ScanNearbyDevices() returned false — check permissions");
            SetStatus("Scan failed to start — check Bluetooth/location permissions");
        }
        else
        {
            Debug.Log("[NUS] Scan started");
        }
    }

    private void OnScanEnded(BluetoothHelper helper, LinkedList<BluetoothDevice> devices)
    {
        Debug.Log($"[NUS] Scan ended, {devices.Count} device(s) found");

        foreach (BluetoothDevice device in devices)
            Debug.Log($"[NUS] Found device: [{device.DeviceName}]");

        if (devices.Count == 0)
        {
            SetStatus("No devices found, rescanning...");
            StartScan();
            return;
        }

        SetStatus($"Connecting to {deviceName}...");
        helper.setDeviceName(deviceName);
        helper.Connect();
    }

    private void OnConnected(BluetoothHelper helper)
    {
        Debug.Log("[NUS] Connected");
        helper.Subscribe(_txChar);
        SetStatus("Connected — listening for proximity");
    }

    private void OnConnectionFailed(BluetoothHelper helper)
    {
        SetStatus("Connection failed — rescanning...");
        StartScan();
    }

    private void OnCharacteristicChanged(BluetoothHelper helper, byte[] data,
                                          BluetoothHelperCharacteristic characteristic)
    {
        // Accumulate bytes; CircuitPython sends "123\n"
        _receiveBuffer += Encoding.UTF8.GetString(data);

        int newlineIndex;
        while ((newlineIndex = _receiveBuffer.IndexOf('\n')) >= 0)
        {
            string line = _receiveBuffer.Substring(0, newlineIndex).Trim();
            _receiveBuffer = _receiveBuffer.Substring(newlineIndex + 1);

            if (string.IsNullOrEmpty(line)) continue;

            Debug.Log($"[NUS] Received: {line}");

            if (receivedText != null)
                receivedText.text = line;

            if (int.TryParse(line, out int proximity))
                HandleProximity(proximity);
        }
    }

    private void OnServiceNotFound(BluetoothHelper helper, string service)
    {
        Debug.LogWarning($"[NUS] Service not found: {service}");
        SetStatus($"Service not found: {service}");
    }

    private void OnCharacteristicNotFound(BluetoothHelper helper, string service, string characteristic)
    {
        Debug.LogWarning($"[NUS] Characteristic not found: {characteristic}");
        SetStatus($"Characteristic not found: {characteristic}");
    }

    // ── Proximity → sphere movement ────────────────────────────────────────

    private void HandleProximity(int proximity)
    {
        // Map proximity value to a Z position
        float t = Mathf.InverseLerp(proximityMin, proximityMax, proximity);
        _targetZ = Mathf.Lerp(zFar, zNear, t);
    }

    // ── LED toggle ─────────────────────────────────────────────────────────

    public void ToggleLED()
    {
        _ledOn = !_ledOn;
        Send(_ledOn ? "LED_ON" : "LED_OFF");
        UpdateLedButtonLabel();
    }

    private void UpdateLedButtonLabel()
    {
        if (ledButtonLabel != null)
            ledButtonLabel.text = _ledOn ? "LED: ON" : "LED: OFF";
    }

    // ── Send helpers ───────────────────────────────────────────────────────

    public void Send(string message)
    {
        if (_helper == null || !_helper.isConnected())
        {
            Debug.LogWarning("[NUS] Not connected — cannot send");
            return;
        }
        _helper.WriteCharacteristic(_rxChar, message);
        Debug.Log($"[NUS] Sent: {message}");
    }

    private void SetStatus(string msg)
    {
        Debug.Log($"[NUS] {msg}");
        if (statusText != null)
            statusText.text = msg;
        Log(msg);
    }

    private void Log(string msg)
    {
        _logLines.Add(msg);
        if (_logLines.Count > maxLogLines)
            _logLines.RemoveAt(0);
        if (logText != null)
            logText.text = string.Join("\n", _logLines);
    }
}
