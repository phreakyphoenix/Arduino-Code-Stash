void setup() 
{
  Serial.begin(9600);

}

void loop()
{
  char s;
  if (Serial.available())
  {
    s = Serial.read();
    if (s=='1')
      Serial.println("Got Lucky");
      else
Serial.println("BLNT");
  }
}
