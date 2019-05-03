void setup()
{
  Serial.begin(38400); // PC Serial and bl
  Serial3.begin(9600); //Sabertooth
}
char c = '0';
void loop()
{
  if (Serial.available())
  {
    c = Serial.read();Serial.print(c);
    if (c == '1')
      Serial3.print("40");
    else if (c == '2')
      Serial3.print("228");
  }
}

