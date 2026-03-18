// The serviceUuid must match the serviceUuid of the device you would like to connect
const serviceUuid = "6e400001-b5a3-f393-e0a9-e50e24dcca9e";
let myCharacteristic;
let input;
let myBLE;

function setup() {
  myBLE = new p5ble();

  // Create a 'Connect' button
  const connectButton = createButton('Connect')
  connectButton.mousePressed(connectToBle);

  // Create a text input
  input = createInput();

  // Create a 'Write' button
  const writeButton = createButton('Write');
  writeButton.mousePressed(writeToBle);
  
  console.log("Setup complete. Click 'Connect' to start BLE connection.");
}

function connectToBle() {
  console.log("Starting BLE connection...");
  console.log("Service UUID:", serviceUuid);
  
  // Use native Web Bluetooth API for better reliability
  connectUsingWebBluetooth();
}

async function connectUsingWebBluetooth() {
  try {
    console.log("Requesting Bluetooth device...");
    
    const device = await navigator.bluetooth.requestDevice({
      filters: [{ services: [serviceUuid] }],
      optionalServices: ['generic_access']
    });
    
    console.log("Device selected:", device.name);
    console.log("Connecting to GATT server...");
    
    const server = await device.gatt.connect();
    console.log("✓ GATT Server connected");
    
    console.log("Discovering service:", serviceUuid);
    const service = await server.getPrimaryService(serviceUuid);
    console.log("✓ Service found");
    
    console.log("Discovering characteristics...");
    const characteristics = await service.getCharacteristics();
    console.log("✓ Found " + characteristics.length + " characteristics");
    
    gotCharacteristics(null, characteristics);
    
  } catch (error) {
    console.error("❌ Bluetooth connection error:", error);
    console.error("Error name:", error.name);
    console.error("Error message:", error.message);
    
    // Try p5ble as fallback
    console.log("Attempting fallback with p5ble...");
    myBLE.connect(serviceUuid, gotCharacteristics);
  }
}

// function gotCharacteristics(error, characteristics) {
//   if (error) console.log('error: ', error);
//   console.log('characteristics: ', characteristics);
//   // Set the first characteristic as myCharacteristic
//   myCharacteristic = characteristics[0];
// }

function gotCharacteristics(error, characteristics) {
  if (error) {
    console.error('❌ Error getting characteristics:', error);
    return;
  }
  
  if (!characteristics || characteristics.length === 0) {
    console.error('❌ No characteristics found');
    return;
  }
  
  console.log('✓ Discovered ' + characteristics.length + ' characteristic(s)');
  
  // Log all characteristics found
  console.log('Available characteristics:');
  characteristics.forEach((char, index) => {
    const uuid = char.uuid || char;
    console.log(`  [${index}] UUID: ${uuid}`);
  });
  
  // Nordic UART RX Characteristic UUID (for writing/sending data to device)
  const rxUuid = "6e400002-b5a3-f393-e0a9-e50e24dcca9e";
  // Nordic UART TX Characteristic UUID (for reading/notifications)
  const txUuid = "6e400003-b5a3-f393-e0a9-e50e24dcca9e";
  
  // Find the RX characteristic (for writing)
  myCharacteristic = characteristics.find(char => {
    const charUuid = char.uuid || char;
    return charUuid.toLowerCase() === rxUuid;
  });
  
  if (myCharacteristic) {
    console.log("✓ Found RX characteristic!");
  } else {
    console.warn("⚠️  RX Characteristic not found, using first one");
    myCharacteristic = characteristics[0];
  }
  
  console.log("✓ Connected and ready to send data!");
}



function writeToBle() {
  const inputValue = input.value();
  console.log("Attempting to send:", inputValue);

  // Make sure we actually have a characteristic connected before writing
  if (!myCharacteristic) {
    console.error("❌ No characteristic found. Are you connected?");
    return;
  }

  // Create an encoder to translate text to bytes
  let encoder = new TextEncoder('utf-8');
  
  // Encode your input string into a Uint8Array
  let encodedString = encoder.encode(inputValue);
  
  console.log("Sending bytes:", encodedString);
  
  // Try native Web Bluetooth API first (has writeValue method)
  if (myCharacteristic.writeValue) {
    myCharacteristic.writeValue(encodedString)
      .then(() => console.log("✓ Text successfully sent!"))
      .catch(error => console.error("❌ Error writing text:", error));
  } 
  // Fallback for p5ble
  else if (myBLE && myBLE.write) {
    myBLE.write(myCharacteristic, encodedString);
    console.log("✓ Text sent via p5ble");
  }
  else {
    console.error("❌ No write method available");
  }
}