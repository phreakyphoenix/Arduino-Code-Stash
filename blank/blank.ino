// defines pins numbers
#include<SoftwareSerial.h>
const int trigPin = 9;
const int echoPin = 10;
SoftwareSerial bl(2, 3);
// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(38400); // Starts the serial communication
  bl.begin(38400);
  pinMode(2, INPUT); 
  pinMode(3, OUTPUT);


}
void loop() 
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  if (distance <= 100)
  {
    Serial.print("Distance: ");
    Serial.println(distance);
     bl.print("Distance: ");
    bl.println(distance);
  }
  if(bl.available())
  Serial.println(bl.readString());
  if(Serial.available())
  bl.println(Serial.readString());
  delay(500);
}

