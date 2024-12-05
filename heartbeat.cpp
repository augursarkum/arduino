#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library

const int PulseWire = 0;       // 'S' Signal pin connected to A0
const int LED13 = 13;          // The on-board Arduino LED
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore
                               
PulseSensorPlayground pulseSensor;  // Creates an object

void setup() {
	Serial.begin(9600);

	// Configure the PulseSensor object, by assigning our variables to it
	pulseSensor.analogInput(PulseWire);   
	pulseSensor.blinkOnPulse(LED13);       // Blink on-board LED with heartbeat
	pulseSensor.setThreshold(Threshold);   

	// Double-check the "pulseSensor" object was created and began seeing a signal
	if (pulseSensor.begin()) {
		Serial.println("PulseSensor object created!");
	}
}

void loop() {
	int myBPM = pulseSensor.getBeatsPerMinute();      // Calculates BPM

	if (pulseSensor.sawStartOfBeat()) {               // Constantly test to see if a beat happened
		Serial.println("♥  A HeartBeat Happened ! "); // If true, print a message
		Serial.print("BPM: ");
		Serial.println(myBPM);                        // Print the BPM value
		}

	delay(20);
}