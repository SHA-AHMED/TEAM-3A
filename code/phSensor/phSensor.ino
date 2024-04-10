#include "ph_grav.h"
Gravity_pH pH = Gravity_pH(A0);

void setup() {
  // put your setup code here, to run once:

  // setup serial communication with LoRa transmitter board
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  // read ph sensor
  float pH_Value = pH.read_ph();

  // send ph sensor data to LoRa board

  // sleep? delay?
  delay(1000);

}
