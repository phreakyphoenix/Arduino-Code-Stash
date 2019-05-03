#include<SoftwareSerial.h>

String name;
SoftwareSerial BT(10,11);
int swh =13;
void setup()
{
  Serial.begin(38400);
  BT.begin(38400);
  delay(200);
  Serial.println("Welcome to Robocon Chat Server. Please Enter Your Name:");
  while(!Serial.available());
  name= Serial.readString();
}

void loop()
{
  digitalWrite(swh, HIGH);  
  if(Serial.available())
  {
    BT.print(name);
    while(Serial.available())
      BT.write(Serial.read());
    BT.write('\n');
  }
  if(BT.available())
  {
    while(BT.available())
      Serial.print(BT.read());
    Serial.print('\n');
    digitalWrite(swh, LOW);  
  }
  delay(500);
}
