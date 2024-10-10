// generating a pwm signal at a custom, configurable frequency, and looping  through all ranges (0-100%) all in  under 1kB of EPROM

#define PWM_FREQ 200 //hertz
#define  PRE_DEV_ID 100 // device ID -> 8 bits
#define PRE_SERV_ID 255 // server id -> 8 bits

void setup() {
  pinMode(15, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(14), inputPressed, FALLING);
}


void loop() {
  digitalWrite(15, HIGH);
  delay(100);                    
  digitalWrite(15, LOW); 
  delay(100);  

  int periodInMicro = 1000000/PWM_FREQ;
  int onPeriod = 0;
  int offPeriod = 0;
  float divHunPeriod = 0;
  
  int8_t deviceID = PRE_DEV_ID;
  int8_t serverID = PRE_SERV_ID;

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

}

void inputPressed() {



}
