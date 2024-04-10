#include <Wire.h>

#include <ph_grav.h>
Gravity_pH pH = Gravity_pH(A0);

void setup() {
  // put your setup code here, to run once:

  // setup serial communication with LoRa transmitter board
  Serial.begin(9600); // serial communication with computer for debugging
  Wire.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

  // read ph sensor
  // float pH_Value = pH.read_ph();

  union {
    float f;
    unsigned char bytes[4];
  } convert;

  // convert.f = pH_Value;

  unsigned char testData[] = {0x12, 0x34, 0x56, 0x78};

  // send ph sensor data to LoRa board
  Wire.beginTransmission(7);
  Wire.write(testData, 4);
  Wire.endTransmission();

  // sleep? delay?
  delay(1000);

}
