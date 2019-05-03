
const int motorPin1  = 5;
const int motorPin2  = 4;
const int motorPin3  = 8;
const int motorPin4  = 7;
const int motorPin5  = 12;
const int motorPin6  = 13;

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
  
    Aup();    delay(5000);     
    Adown();    delay(5000);
    
    Bup();    delay(5000);     
     Bdown();    delay(5000);

    Cup();    delay(5000);     
    Cdown();    delay(5000);
}

void Aup()                                                     //This code  will turn Motor A up.
{
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    Serial.println("rick1");
}

void Adown()                                                   //This code will turn Motor A down.
{
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    Serial.println("fuck1");
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
}

void Bdown()                                                  //This code will turn Motor B down.
{
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    Serial.println("fuck2");
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
}

void Cdown()                                                  //This code will turn Motor C down.
{
    digitalWrite(motorPin5, LOW);
    digitalWrite(motorPin6, HIGH);
    Serial.println("fuck3");
}

void Cstop()                                                  //This code will stop Motor C.
{
    digitalWrite(motorPin5, LOW);
    digitalWrite(motorPin6, LOW);
    Serial.println("stop3");
}

void stopAll()                                                //STOPS THE MOTHERFUCKING UNIVERSE.
{
  Astop();Bstop();Cstop();
}

