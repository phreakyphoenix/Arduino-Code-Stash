#include <SoftwareSerial.h>
boolean readdata=false;
char point ;
int x=0,y=0;
SoftwareSerial bot(9,10); //RX,TX
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
bot.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(bot.available())
{
  if (readdata)
  {
    point=bot.read();
    switch(point)
    {
      case 'x':
      x=bot.read();
      break;
      case 'y':
      y=bot.read();
      break;
     }
    readdata=false;
  }
  else if (bot.read()=='s')
  {
    readdata=true;
  }
 
}
Serial.print(String(x) + "\t" + String(y));
Serial.println();

}
