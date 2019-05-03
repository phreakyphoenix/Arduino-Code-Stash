#include<PS2X_lib.h>
const int motorPin1  = 12;
const int motorPin2  = 13;
const int motorPin3  = 8;
const int motorPin4  = 7;
const int motorPin5  = 5;
const int motorPin6  = 4;

//=============================================================================
int pins[4] = {A0, A1, A2, A3};
//#include<Wire.h>
int CLOCK = pins[3];
int COMMAND = pins[0];
int  ATTENTION = pins[1];
int DATA = pins[2];
#define BAUD_RATE 9600
//=============================================================================
PS2X ps2x;
boolean up = 0;
boolean down = 0;

boolean left = 0;
boolean right = 0;

boolean triangle = 0;
boolean sqr = 0;
boolean cross = 0;
boolean circle = 0;

boolean r1 = 0;
boolean r2 = 0, p_r2 = 0;

boolean l1 = 0;
boolean l2 = 0, p_l2 = 0;
boolean r3 = 0;
boolean l3 = 0;

int RY = 0;
int RX = 0;

int LY = 0;
int LX = 0;
int d = 0;
boolean start = 0;
boolean select = 0;

boolean start_flag = 0;

void readButtons();// to check the value of PS2 buttons
void printState(); // to print/read the value of PS2 buttons

void setup()
{
  ps2x.config_gamepad(CLOCK, COMMAND, ATTENTION, DATA); // (clock(blue),command(orange), attention(yellow), data(brown))
  Serial.begin(BAUD_RATE);
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
  initialise();
}

void initialise()
{ allDown(); delay(5000);
  allUp(); delay(2500); stopAll();
}

void readButtons()
{
  ps2x.read_gamepad();
  up = ps2x.Button(PSB_PAD_UP);
  down = ps2x.Button(PSB_PAD_DOWN);
  left = ps2x.Button(PSB_PAD_LEFT);
  right = ps2x.Button(PSB_PAD_RIGHT);

  triangle = ps2x.Button(PSB_GREEN);
  circle = ps2x.Button(PSB_RED);
  cross = ps2x.Button(PSB_BLUE);
  sqr = ps2x.Button(PSB_PINK);

  r1 = ps2x.Button(PSB_R1);
  r2 = ps2x.Button(PSB_R2);
  l1 = ps2x.Button(PSB_L1);
  l2 = ps2x.Button(PSB_L2);

  r3 = ps2x.Button(PSB_R3);
  l3 = ps2x.Button(PSB_L3);

  RY = ps2x.Analog(PSS_RY);
  RX = ps2x.Analog(PSS_RX);

  LY = ps2x.Analog(PSS_LY);
  LX = ps2x.Analog(PSS_LX);

  start = ps2x.Button(PSB_START);
  select = ps2x.Button(PSB_SELECT);

}

boolean dbz()
{
  if ((RX > 125 && RX < 130) && (RY > 125 && RY < 130))
  {
    if (r1 == 0 && r2 == 0 && l1 == 0 && l2 == 0 && r3 == 0 && l3 == 0)
      return true;
  }
  else return false;
}
void printState()
{
  Serial.print(up);
  Serial.print(" ");
  Serial.print(down);
  Serial.print(" ");
  Serial.print(left);
  Serial.print(" ");
  Serial.print(right);
  Serial.print(" ");
  Serial.print(" ");

  Serial.print(triangle);
  Serial.print(" ");
  Serial.print(circle);
  Serial.print(" ");
  Serial.print(cross);
  Serial.print(" ");
  Serial.print(sqr);
  Serial.print(" ");
  Serial.print(" ");

  Serial.print(r1);
  Serial.print(" ");
  Serial.print(r2);
  Serial.print(" ");
  Serial.print(" ");

  Serial.print(l1);
  Serial.print(" ");
  Serial.print(l2);
  Serial.print(" ");
  Serial.print(" ");

  Serial.print(r3);
  Serial.print(" ");
  Serial.print(l3);
  Serial.print(" ");
  Serial.print(" ");

  Serial.print(RY);
  Serial.print(" ");
  Serial.print(RX);
  Serial.print(" ");
  Serial.print(LY);
  Serial.print(" ");
  Serial.print(LX);
  Serial.print(" ");

  Serial.print(start);
  Serial.print(" ");
  Serial.println(select);
  delay(100);
}
boolean flag = true;
void loop()
{
  readButtons();
  printState();
  if (RY < 20)
  {
    Aup();
    if (RX > 180)
      Cup();
    else if (RX < 20)
      Bup();
  }
  else if (RY > 245)
  {
    if (RX > 180)
      Cdown();
    else if (RX < 20)
      Bdown();
    else
    {
      Bdown();
      Cdown();
    }
  }

  else if (r1 == 1)
    Bup();
  else if (r2 == 1)
    Bdown();
  else if (l1 == 1)
    Cup();
  else if (l2 == 1)
    Cdown();
  else if (triangle == 1)
    Aup();
  else if (cross == 1)
    Adown();
  else if (circle == 1)
  { if (flag == true)
      allUp();
    else
      allDown();
    flag != flag;
  }
  else if (square == 1)
    allDown();
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

