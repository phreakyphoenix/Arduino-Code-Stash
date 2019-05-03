//0---->White
//1---->Black

//Array for Arduino pins
int sensPins[]={3,5,A0,A1,A2,A3,A4,A5};
//Variable that stores the sensor reading
int reading;
int inp;
//Array that stores the reading from each input
int readings[]={0,0,0,0,0,0,0,0};
//Setup
void setup()
{
  //For Debugging
  Serial.begin(9600);
  int i;
  //Assigning pins to INPUT
   while(i<5)
   {
    pinMode(sensPins[i],INPUT);
    i=i+1;
   }
   Serial.println("Setup...");
   Serial.println("Ready for transmission.."); 
 }
 void loop()
 {
   //Reading stored in the variable by calling readOut() functoin
   reading=readOut(sensPins);
   Serial.print(reading);
   Serial.println("");
   delay(500);
   //Delay is just so that change in readings is more noticeable
 }
 
 //Function that returns the reading as an integer
 int readOut(int sensPins[])
 {
   
   int i,j,k=0;
   inp=0;
   //Loop to resets the array before each reading is stored
   while(k<5)
  {
    readings[k]=0;
    k=k+1;
  }
  //Loop stores each sensor input into the array
    for(i=0;i<5;i++)
   {
     readings[i]=analogRead(sensPins[i]);
   }
   //Loop converts the array to an integer
   while(j<5)
   {
     inp=inp*10+readings[j];
     j=j+1;
  }
  //Returns the reading as an integer
  return inp;
}
