void setup() {
  analogWrite(6, 50);
  // put your setup code here, to run once:
  Serial.begin(9600);
  digitalWrite(7, HIGH);
  digitalWrite(4, LOW);
  Serial.println("rick1");
  delay(2000);
  digitalWrite(7, LOW);
  digitalWrite(4, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(7, HIGH);
  digitalWrite(4, LOW);
  Serial.print("rick1");
  delay(2000);
  digitalWrite(7, LOW);
  digitalWrite(4, HIGH);
  Serial.print("fuck");
}
