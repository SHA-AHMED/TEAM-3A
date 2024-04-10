void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // serial connection with computer for debugging
  Serial1.begin(9600); // serial connection with other board

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial1.available()) {
    Serial.println(Serial1.read());
  }

  delay(1000);

}
