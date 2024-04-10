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

    // float x;
    unsigned long y;
    unsigned char x1 = Wire.read();
    unsigned char x2 = Wire.read();
    unsigned char x3 = Wire.read();
    unsigned char x4 = Wire.read();
    
    unsigned char buff[] = {x1,x2,x3,x4};

    // memcpy(&x, &buff, sizeof(float));
    memcpy(&y, &buff, sizeof(unsigned long));

    Serial.println(y);
  }
}
