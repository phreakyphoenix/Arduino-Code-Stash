void setup() 
{
Serial.begin(9600);
Serial1.begin(9600);
Serial.println("Enter AT commands:");
}

void loop()

{

if (Serial1.available())

Serial.write(Serial1.read());

if (Serial.available())
{
  Serial1.write(Serial.read());

}
}