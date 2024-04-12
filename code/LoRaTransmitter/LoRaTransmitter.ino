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

    float x;
    unsigned char x3 = Wire.read();
    unsigned char x2 = Wire.read();
    unsigned char x1 = Wire.read();
    unsigned char x0 = Wire.read();
    unsigned char buff[] = {x3, x2, x1, x0};

    // memcpy(&x, &buff, sizeof(float));
    memcpy(&x, &buff, sizeof(float));

    Serial.println(x);
    Serial.print(x3);
    Serial.print(" ");
    Serial.print(x2);
    Serial.print(" ");
    Serial.print(x1);
    Serial.print(" ");
    Serial.print(x0);
    Serial.print(" ");
    Serial.print("\n");
  }
}
