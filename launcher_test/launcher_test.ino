int dir1 = 2;
int dir2 = 4;
int enable=A3;
int pwm = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(enable,OUTPUT);
  pinMode(pwm, OUTPUT);
//  pinMode(photo_forw, INPUT);
  //pinMode(photo_bac, INPUT);
 // pinMode(photo_load, INPUT);
  //pinMode(bump_switch,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available())
{
  char ch =Serial.read();
  if(ch=='f')
  {
    //digitalWrite(enable,1);
    digitalWrite(dir1,1);
    digitalWrite(dir2,0);
    analogWrite(pwm,20);
  }
  if(ch=='s')
  {
    
    //digitalWrite(enable,1);
    digitalWrite(dir1,1);
    digitalWrite(dir2,1);
    analogWrite(pwm,0);
  
  }
  if(ch=='b')
  {
    //digitalWrite(enable,1);
    digitalWrite(dir1,0);
    digitalWrite(dir2,1);
    analogWrite(pwm,20);
  }
}
}
