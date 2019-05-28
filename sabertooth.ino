int start;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT_PULLUP);

       EIFR |= (1 << INTF0);
  EIFR |= (1 << INTF1);
  attachInterrupt(digitalPinToInterrupt(2), isr, RISING);

  EIFR |= (1 << INTF0) | ( 1 << INTF1);

  Serial1.print("M1: startup\r\n");
  Serial1.print("M2: startup\r\n");
  Serial1.print("M1: 300\r\n");
  Serial1.print("M2: 300\r\n");


  start = millis();

}

volatile int ctr = 0;
volatile int ctr2 = 0;

void isr() {
  ctr++;
}


void isr2() {
  ctr2++;
}
void loop() {

  if (millis() - start >= 5000) {
    Serial1.print("M1: 0\r\n");
    Serial1.print("M2: 0\r\n");
    while (1);
  }

  delay(100);
  int last = ctr;
  Serial.println(ctr);
  if (ctr != last) {
    Serial.println("stopping " + String(ctr));
       EIFR |= (1 << INTF0);
  EIFR |= (1 << INTF1);

     attachInterrupt(digitalPinToInterrupt(3), isr2, FALLING);
      EIFR |= (1 << INTF0);
  EIFR |= (1 << INTF1);

      Serial1.print("M1: 300\r\n");
  Serial1.print("M2: 300\r\n");

    int last2 = ctr2;
    while (ctr2 != last) {

      if (millis() - start >= 5000) {
        Serial.println("timeout");
          Serial1.print("M1: 0\r\n");
    Serial1.print("M2: 0\r\n");
    while (1);
      }
      Serial.println("stopped " + String(ctr2));
      Serial1.print("M1: 0\r\n");
      Serial1.print("M2: 0\r\n");
    }


  } else {
     Serial.println("running");
  }
}

