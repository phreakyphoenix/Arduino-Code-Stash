void setup() 
{
  Serial.begin(38400); // Bluetooth Serial
  Serial1.begin(38400); //PC Serial
  Serial3.begin(38400); //Sabertooth
}
void startx()
{
  Serial3.write (5);Serial3.write(133);
}
void starty()
{
  Serial3.write (69);Serial3.write(197);
}
void stopx()
{
    Serial3.write (0);Serial3.write(0);
}

char c=' ';

void loop() 
{
  if(Serial.available())
  {
  c = Serial.read();
  Serial.write(c);
  }
 /* switch (c)
  {
    case 1:startx();break;
    case 2:stopx();break;
    case 3:starty();break;
    case 4:stopy();break;
  }*/
}

