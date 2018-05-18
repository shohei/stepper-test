#define PPS       1000
#define MICROSTEP 16
// #define DELAY_US (int)(1000*1000/(PPS*MICROSTEP))
#define DELAY_US 1000

#define X_STEP_PIN 18 
#define X_DIR_PIN 42 
#define X_EN_PIN 12 

#define TRAVEL_S 3
#define TOTAL 300000

#define PULSE_DELAY_US 2

void setup(){
  Serial.begin(9600);
  pinMode(X_STEP_PIN,OUTPUT);
  pinMode(X_DIR_PIN,OUTPUT);
  pinMode(X_EN_PIN,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);

  digitalWrite(X_EN_PIN,LOW);
}

void oneshot(){
  digitalWrite(X_STEP_PIN,HIGH);
  delayMicroseconds(PULSE_DELAY_US);
  digitalWrite(X_STEP_PIN,LOW);
  delayMicroseconds(PULSE_DELAY_US);
}

void loop(){
  Serial.println("CW");
  digitalWrite(X_DIR_PIN,HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  for(long i=0;i<TOTAL;i++){
  	oneshot();
  	delayMicroseconds(DELAY_US);
  }

  Serial.println("CCW");
  digitalWrite(X_DIR_PIN,LOW);
  digitalWrite(LED_BUILTIN, LOW);
  for(long i=0;i<TOTAL;i++){
  	oneshot();
  	delayMicroseconds(DELAY_US);
  }
}

