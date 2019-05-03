void setup() 
{
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
}

void loop() 
{
 if (digitalRead(11)==HIGH)
 digitalWrite(9,HIGH);
 else
  digitalWrite(9,LOW);
}
