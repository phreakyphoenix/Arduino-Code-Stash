void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial1.print("M2:startup\r\n");
  Serial1.print("M2: 500\r\n");
  delay(2000);
  Serial1.print("M2:shutdown\r\n");
}

void loop()
{

}
