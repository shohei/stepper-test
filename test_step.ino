#define PPS       1000
#define MICROSTEP 16
#define DELAY_US (int)(1000*1000/(PPS*MICROSTEP))

#define X_STEP_PIN 18 
#define X_DIR_PIN 42 
#define X_EN_PIN 12 

#define TRAVEL_S 3
#define TOTAL (int)((TRAVEL_S*1000*1000)/DELAY_US)

#define PULSE_DELAY_US 2

void setup(){
  pinMode(X_STEP_PIN,OUTPUT);
  pinMode(X_DIR_PIN,OUTPUT);
  pinMode(X_EN_PIN,OUTPUT);

  digitalWrite(X_EN_PIN,LOW);
}

void loop(){
  digitalWrite(X_DIR_PIN,HIGH);
  for(int i=0;i<TOTAL;i++){
  	oneshot();
  	delayMicroseconds(DELAY_US);
  }
  digitalWrite(X_DIR_PIN,LOW);
  for(int i=0;i<TOTAL;i++){
  	oneshot();
  	delayMicroseconds(DELAY_US);
  }
}

void oneshot(){
 	digitalWrite(X_STEP_PIN,HIGH);
  	delayMicroseconds(PULSE_DELAY_US);
  	digitalWrite(X_STEP_PIN,LOW);
  	delayMicroseconds(PULSE_DELAY_US);
}