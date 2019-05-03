/* Comment this out to disables and save space */
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "cb6b5198a212417e9578367af827cb85";
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Robocon";
char pass[] = "whatpassword";
int x, y, button, slider;
float trm;
// void print()
// {
// Serial.println("X::"+String(x)+"\tY::"+String(y));
// }
void send_data(char point, char data)
{
  Serial.print('s');
  Serial.print(point);
  Serial.print(data);
}

BLYNK_WRITE(V0)
{
  y = param[1].asInt();
  // print();
  send_data('y', y);
}

BLYNK_WRITE(V1)
{
  x = param[0].asInt();
  send_data('x', x);
  // print();
}

BLYNK_WRITE(V2)
{
  button = param.asInt();
  send_data('b', button);
  // Serial.println("Button::"+String(button));
}

BLYNK_WRITE(V3)
{
  slider = param.asInt();
  send_data('p', slider);
  // Serial.println("Slider::"+String(slider));
}

BLYNK_WRITE(V4)
{
  trm = param.asFloat();
  send_data('t', trm);
  // Serial.println("Trim::"+String(trm));
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  // Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  // Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 0, 104), 8442);
  Blynk.virtualWrite(V3, 30);
}

void loop()
{
  Blynk.run();
  // Serial.println("X::"+String(x)+"/tY::"+String(y));
}
