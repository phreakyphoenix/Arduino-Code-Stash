#include <SPI.h>


void setup (void)
{

  digitalWrite(53, HIGH);  // ensure SS stays high for now
pinMode(51,OUTPUT);
pinMode(52,OUTPUT);
pinMode(53,OUTPUT);
digitalWrite(51, LOW);
digitalWrite(52, LOW);
  // Put SCK, MOSI, SS pins into output mode
  // also put SCK, MOSI into LOW state, and SS into HIGH state.
  // Then put SPI hardware into Master mode and turn SPI on
  SPI.begin ();

}  
void loop (void)
{

  char c;

  // enable Slave Select
  digitalWrite(53, LOW);    // SS is pin 10

  // send test string
  for (const char * p = "Hello, world!\n" ; c = *p; p++)
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(53, HIGH);

  delay (50);  // 1 seconds delay
}  // end of loop
