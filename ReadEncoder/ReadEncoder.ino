 #define outputA 2
 #define outputB 3

 int aState;
 int aLastState;  
 volatile int c;
 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   Serial.begin (9600);
   aLastState = digitalRead(outputA);   
   attachInterrupt(digitalPinToInterrupt(2),isr, CHANGE);
 } 

 
void isr()
 {
  aState = digitalRead(outputA);
  if (aState != aLastState)
  { 
     if (digitalRead(outputB) != aState) 
     { 
          c++;
     }
     else 
     {
        c--;
     }
  }
  aLastState = aState;
 }
 void loop() 
 { 
     Serial.println(c);
     delay(500);
 } 
 

