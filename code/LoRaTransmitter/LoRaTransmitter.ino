#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // serial connection with computer for debugging
  Wire.begin(7);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(Wire.available()) {

    float x;
    unsigned char x1 = Wire.read();
    unsigned char x2 = Wire.read();
    unsigned char x3 = Wire.read();
    unsigned char x4 = Wire.read();
    
    unsigned char buff[] = {x1,x2,x3,x4};

    memcpy(&x, &buff, sizeof(float));
    
    Serial.println(x);
  }

}
