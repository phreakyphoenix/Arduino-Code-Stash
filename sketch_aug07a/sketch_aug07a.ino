#include <SoftwareSerial.h>

SoftwareSerial chat(10, 11); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  chat.begin(9600);
  chat.println("Hello, world?");
}

void loop() 
{ 
  String s;
  if (chat.available()) //if I reading output
  {
    s=chat.read();
  }
  if (Serial.available()) //if i m giving input
  {
    chat.write(Serial.read());
  }
}
