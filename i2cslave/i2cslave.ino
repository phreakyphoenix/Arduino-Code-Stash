#include <Wire.h>

void setup() 
{
  Wire.begin(8);                // join i2c bus with address #8
  Serial.begin(9600);           // start serial for output
}

void loop() 
{
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(sendData);  
  delay(100);
}

void receiveEvent() 
{
  while (Wire.available())  
    
  Serial.write(Wire.read());
}
void sendData() 
{
  if(Serial.available())
  Wire.write(Serial.read());
}
