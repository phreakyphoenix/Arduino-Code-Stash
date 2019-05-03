#include <Wire.h>

void setup() 
{
  Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)
}

void loop() 
{
  int a=1;
  
  Wire.beginTransmission(8); // transmit to device #8
  if(Serial.available())
  Wire.println(Serial.read());
  
    Wire.requestFrom(8,100);
    if(Wire.available()>0)
    {
    Serial.write(Wire.read());
    }
  Wire.endTransmission(); 
  delay(10);   
}
