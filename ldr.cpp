const int ledPin = 13;    // Built-in LED pin
const int ldrPin = A0;    // LDR analog pin
int ldrValue = 0;         // Variable to store LDR value

void setup() {
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
  Serial.begin(9600);       // Initialize serial communication
}

void loop() {
  ldrValue = analogRead(ldrPin);  // Read the LDR value
  Serial.println(ldrValue);       // Print the LDR value to the Serial Monitor

  if (ldrValue < 500) {           // Adjust the threshold value as needed
    digitalWrite(ledPin, HIGH);   // Turn on the LED if the LDR value is below the threshold
  } else {
    digitalWrite(ledPin, LOW);    // Turn off the LED if the LDR value is above the threshold
  }

  delay(1000);  // Wait for 1 second before reading the LDR value again
}
