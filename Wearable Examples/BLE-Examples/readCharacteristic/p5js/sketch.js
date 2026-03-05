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
}

function connectToBle() {
  // Connect to a device by passing the service UUID
  myBLE.connect(serviceUuid, gotCharacteristics);
}

function gotCharacteristics(error, characteristics) {
  if (error) console.log('error: ', error);
  console.log('characteristics: ', characteristics);
  // Set the first characteristic as myCharacteristic
  myCharacteristic = characteristics[0];
}

function writeToBle() {
  const inputValue = input.value();
  console.log("Attempting to send:", inputValue);

  // Make sure we actually have a characteristic connected before writing
  if (!myCharacteristic) {
    console.error("No characteristic found. Are you connected?");
    return;
  }

  // 1. Create an encoder to translate text to bytes
  let encoder = new TextEncoder('utf-8');
  
  // 2. Encode your input string into a Uint8Array
  let encodedString = encoder.encode(inputValue);
  
  // 3. Write directly to the characteristic using the native API
  myCharacteristic.writeValue(encodedString)
    .then(() => console.log("Text successfully sent!"))
    .catch(error => console.error("Error writing text: ", error));
}