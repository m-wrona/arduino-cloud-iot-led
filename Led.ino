#include "arduino_secrets.h"
#include "thingProperties.h"

int internalLed = LED_BUILTIN;
int externalLed = PIN_A2;

void setup() {

  // Initialize leds
  pinMode(internalLed, OUTPUT);
  pinMode(externalLed, OUTPUT);

  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  // mark status of initialisation
  digitalWrite(internalLed, ArduinoCloud.connected());
}


/*
  Since LEDON is READ_WRITE variable, onLEDONChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLEDONChange()  {
  digitalWrite(externalLed, lED_ON);
  delay(500);
}
