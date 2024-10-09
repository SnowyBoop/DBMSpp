#define PWM_FREQ 100 //hertz

void setup() {
  pinMode(15, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(14), inputPressed, FALLING);
}


void loop() {
  digitalWrite(15, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(100);                      // wait for a second
  digitalWrite(15, LOW);   // turn the LED off by making the voltage LOW
  delay(100);                      // wait for a second

  int periodInMicro = 1000000/PWM_FREQ;
  int onPeriod = 0;
  int offPeriod = 0;
  float divHunPeriod = 0;
  
  divHunPeriod = periodInMicro/100;

  for(int i = 0; i<100; i++) {



    onPeriod = (i*divHunPeriod);
    offPeriod = periodInMicro - onPeriod;

    for(int k = 0; k<10; k++) {
      delayMicroseconds(onPeriod);
      digitalWrite(15,LOW);
      delayMicroseconds(offPeriod); 
      digitalWrite(15,HIGH);
    }

  }



  digitalWrite(15, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(15, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);   

}

void inputPressed() {

  

}
