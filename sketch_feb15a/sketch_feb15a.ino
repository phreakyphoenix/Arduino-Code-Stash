void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(19,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(digitalRead(19));
  Serial.print("\n");
}
