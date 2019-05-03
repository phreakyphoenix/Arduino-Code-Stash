void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

analogWrite(9,128);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);delay(3000);
  Serial.print("rev");
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);delay(3000);
}
