void setup() 
{
  Serial.begin(9600);
  pinMode(A0,INPUT_PULLUP);
}

void loop() 
{
  Serial.print((analogRead(A0)/1023.0)*5);Serial.print('\t');
  Serial.println(mapF(analogRead(A0),0,1023,10,50));
  delay(10);
}

float mapF(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
