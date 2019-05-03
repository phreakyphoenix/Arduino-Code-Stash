const int motorPin1  = 12;
const int motorPin2  = 13;
const int motorPin3  = 8;
const int motorPin4  = 7;
const int motorPin5  = 5;
const int motorPin6  = 4;

void setup()
{
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(motorPin5, OUTPUT);
  pinMode(motorPin6, OUTPUT);
  pinMode(6, OUTPUT);
  analogWrite(6, 255);
  pinMode(9, OUTPUT);
  analogWrite(9, 255);
  pinMode(11, OUTPUT);
  analogWrite(11, 255);
  Serial.begin(9600);
}

void loop()
{
  char s;
  if (Serial.available())
  {
    s = Serial.read();

    if (s == '1')
      Aup();
    else if (s == '2')
      Adown();
    else if (s == '4')
      Bup();
    else if (s == '5')
      Bdown();
    else if (s == '7')
      Cup();
    else if (s == '8')
      Cdown();
    else if (s == '3')
      Astop();
    else if (s == '6')
      Bstop();
    else if (s == '9')
      Cstop();
    else if (s == 'a')
      allUp();
    else if (s == 'd')
      allDown();
    else if (s == 's')
      stopAll();
    else if (s == '0')
      style();
  }
}

void style()
{
  while (true)
  {
    Aup();
    delay(2000);
    Bup();
    delay(2000);
    Cup();
    delay(2000);
    Adown();
    delay(2000);
    Bdown();
    delay(2000);
    Cdown();
    delay(2000);
  }
}

void Aup()                                                     //This code  will turn Motor A up.
{
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  Serial.println("rick1");
  // delay(5000);
}

void Adown()                                                   //This code will turn Motor A down.
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  Serial.println("fuck1");
  //  delay(5000);
}

void Astop()                                                  //This code will stop Motor A.
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  Serial.println("stop1");
}

void Bup()                                                    //This code  will turn MotorB up.
{
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  Serial.println("rick2");
  //  delay(5000);
}

void Bdown()                                                  //This code will turn Motor B down.
{
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  Serial.println("fuck2");
  //  delay(5000);
}

void Bstop()                                                  //This code will stop Motor B.
{
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  Serial.println("stop2");
}

void Cup()                                                    //This code will turn Motor C up.
{
  digitalWrite(motorPin5, HIGH);
  digitalWrite(motorPin6, LOW);
  Serial.println("rick3");
  // delay(5000);
}

void Cdown()                                                  //This code will turn Motor C down.
{
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, HIGH);
  Serial.println("fuck3");
  // delay(5000);
}

void Cstop()                                                  //This code will stop Motor C.
{
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, LOW);
  Serial.println("stop3");
}

void allUp()                                                //STOPS THE MOTHERFUCKING UNIVERSE.
{
  Aup(); Bup(); Cup();
}

void allDown()                                                //STOPS THE MOTHERFUCKING UNIVERSE.
{
  Adown(); Bdown(); Cdown();
}

void stopAll()                                                //STOPS THE MOTHERFUCKING UNIVERSE.
{
  Astop(); Bstop(); Cstop();
}

