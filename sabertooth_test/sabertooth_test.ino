void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial1.print("M2: startup\r\n");
//  Serial1.print("M2: startup\r\n");
 Serial.print("fickjb");
 Serial1.print("M2: 2000\r\n");
  //Serial1.print("M2: -1000\r\n");
  delay(2000);
  Serial1.print("M2: shutdown\r\n");
  //Serial1.print("M2: 0\r\nM2: shutdown\r\n");
  
}

void loop() 
{
  
}
