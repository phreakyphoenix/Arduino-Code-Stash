//0---->White
//1---->Black

//Array for Arduino pins
int sensPins[] = {A0, A1, A2, A3, A4};

//Variable that stores the sensor reading
int reading;

//Array that stores the reading from each input
int readings[] = {0, 0, 0, 0, 0};
int maxima[] = {0, 0, 0, 0, 0};
int av[] = {0, 0, 0, 0, 0};
int minima[] = {1023, 1023, 1023, 1023, 1023};
void setup()
{
  int i;
  Serial.begin(9600);
  while (millis() <= 20000)
  {
    for ( i = 0; i < 5; i++)
    {
      readings[i] = analogRead(sensPins[i]);
      
      if (readings[i] > maxima[i])
        maxima[i] = readings[i];

      if (readings[i] < minima[i])
        minima[i] = readings[i];

    }
  }
  for ( i = 0; i < 5; i++)
  {
    av[i] = (maxima[i] + minima[i]) / 2;
  }

}
void loop()
{
  for (int i = 0; i < 5; i++)
  {
    readings[i] = analogRead(sensPins[i]);
    if (readings[i] > av[i])
    Serial.print('1');
    else
    Serial.print('0');
  }
  Serial.println();
}
