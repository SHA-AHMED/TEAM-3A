#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // serial connection with computer for debugging
  Wire.begin(7);
  Wire.onReceive(receiveData);

}

void loop() {
  // put your main code here, to run repeatedly:

}

void receiveData(int numBytes) {
  while(Wire.available()) {

    // TODO: change back to float and order bytes correctly

    union {
      float f;
      unsigned char bytes[4];
    } convert;

    // float x;
    convert.bytes[3] = Wire.read();
    convert.bytes[2] = Wire.read();
    convert.bytes[1] = Wire.read();
    convert.bytes[0] = Wire.read();

    // memcpy(&x, &buff, sizeof(float));

    Serial.println(convert.f);
  }
}
