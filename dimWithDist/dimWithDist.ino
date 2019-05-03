const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(38400); // Starts the serial communication
  pinMode(3,OUTPUT);
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
  }
  if(distance>100)
  analogWrite(3,10);
  else
  analogWrite(3,map(distance,10, 100,0,255));
  delay(100);
}

