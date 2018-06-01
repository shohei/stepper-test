#define PPS       1000
#define MICROSTEP 16
// #define DELAY_US (int)(1000*1000/(PPS*MICROSTEP))
#define DELAY_US 1000

#define X1_STEP_PIN    18 
#define X1_DIR_PIN     42 
#define X1_EN_PIN      12 
#define X2_STEP_PIN    36 
#define X2_DIR_PIN     19 
#define X2_EN_PIN      49 
#define Y1_STEP_PIN    48 
#define Y1_DIR_PIN     33 
#define Y1_EN_PIN      48 
#define Y2_STEP_PIN    37 
#define Y2_DIR_PIN     41 
#define Y2_EN_PIN      45 
#define Z1_STEP_PIN    34 
#define Z1_DIR_PIN     40 
#define Z1_EN_PIN      47 
#define Z2_STEP_PIN    31 
#define Z2_DIR_PIN     35 
#define Z2_EN_PIN      46 
#define E_STEP_PIN     30 
#define E_DIR_PIN      32 
#define E_EN_PIN       43
#define A_STEP_PIN     65 
#define A_DIR_PIN      64 
#define A_EN_PIN       44 

#define TRAVEL_S 3
#define TOTAL 3000

#define PULSE_DELAY_US 2

void setup(){
  Serial.begin(9600);
  pinMode(X1_STEP_PIN,OUTPUT);
  pinMode(X1_DIR_PIN, OUTPUT);
  pinMode(X1_EN_PIN,  OUTPUT);
  pinMode(X2_STEP_PIN,INPUT);
  pinMode(X2_DIR_PIN, INPUT);
  pinMode(X2_EN_PIN,  INPUT);
  pinMode(Y1_STEP_PIN,OUTPUT);
  pinMode(Y1_DIR_PIN, OUTPUT);
  pinMode(Y1_EN_PIN,  OUTPUT);
  pinMode(Y2_STEP_PIN,INPUT);
  pinMode(Y2_DIR_PIN, INPUT);
  pinMode(Y2_EN_PIN,  INPUT);
  pinMode(Z1_STEP_PIN,OUTPUT);
  pinMode(Z1_DIR_PIN, OUTPUT);
  pinMode(Z1_EN_PIN,  OUTPUT);
  pinMode(Z2_STEP_PIN,INPUT);
  pinMode(Z2_DIR_PIN, INPUT);
  pinMode(Z2_EN_PIN,  INPUT);
  pinMode(E_STEP_PIN, OUTPUT);
  pinMode(E_DIR_PIN,  OUTPUT);
  pinMode(E_EN_PIN,   OUTPUT);
  pinMode(A_STEP_PIN, OUTPUT);
  pinMode(A_DIR_PIN,  OUTPUT);
  pinMode(A_EN_PIN,   OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);

  digitalWrite(X1_EN_PIN,LOW);
  // digitalWrite(X2_EN_PIN,LOW);
  digitalWrite(Y1_EN_PIN,LOW);
  // digitalWrite(Y2_EN_PIN,LOW);
  digitalWrite(Z1_EN_PIN,LOW);
  // digitalWrite(Z2_EN_PIN,LOW);
  digitalWrite(E_EN_PIN,LOW);
  digitalWrite(A_EN_PIN,LOW);
}

void oneshot(){
  digitalWrite(X1_STEP_PIN,HIGH);
  // digitalWrite(X2_STEP_PIN,HIGH);
  digitalWrite(Y1_STEP_PIN,HIGH);
  // digitalWrite(Y2_STEP_PIN,HIGH);
  digitalWrite(Z1_STEP_PIN,HIGH);
  // digitalWrite(Z2_STEP_PIN,HIGH);
  digitalWrite(E_STEP_PIN,HIGH);
  digitalWrite(A_STEP_PIN,HIGH);
  delayMicroseconds(PULSE_DELAY_US);
  digitalWrite(X1_STEP_PIN,LOW);
  // digitalWrite(X2_STEP_PIN,LOW);
  digitalWrite(Y1_STEP_PIN,LOW);
  // digitalWrite(Y1_STEP_PIN,LOW);
  digitalWrite(Z1_STEP_PIN,LOW);
  // digitalWrite(Z1_STEP_PIN,LOW);
  digitalWrite(A_STEP_PIN,LOW);
  digitalWrite(E_STEP_PIN,LOW);
  delayMicroseconds(PULSE_DELAY_US);

  delayMicroseconds(DELAY_US);
}

void oneshot2(){
  digitalWrite(X1_STEP_PIN,HIGH);
  // digitalWrite(X2_STEP_PIN,HIGH);
  digitalWrite(Y1_STEP_PIN,HIGH);
  // digitalWrite(Y2_STEP_PIN,HIGH);
  digitalWrite(Z1_STEP_PIN,HIGH);
  // digitalWrite(Z2_STEP_PIN,HIGH);
  digitalWrite(E_STEP_PIN,HIGH);
  digitalWrite(A_STEP_PIN,HIGH);
  delayMicroseconds((int)(DELAY_US/2));
  digitalWrite(X1_STEP_PIN,LOW);
  // digitalWrite(X2_STEP_PIN,LOW);
  digitalWrite(Y1_STEP_PIN,LOW);
  // digitalWrite(Y2_STEP_PIN,LOW);
  digitalWrite(Z1_STEP_PIN,LOW);
  // digitalWrite(Z2_STEP_PIN,LOW);
  digitalWrite(E_STEP_PIN, LOW);
  digitalWrite(A_STEP_PIN, LOW);
  delayMicroseconds((int)(DELAY_US/2));
}

void loop(){
  Serial.println("CW");
  digitalWrite(X1_DIR_PIN,HIGH);
  // digitalWrite(X2_DIR_PIN,HIGH);
  digitalWrite(Y1_DIR_PIN,HIGH);
  // digitalWrite(Y2_DIR_PIN,HIGH);
  digitalWrite(Z1_DIR_PIN,HIGH);
  // digitalWrite(Z2_DIR_PIN,HIGH);
  digitalWrite(E_DIR_PIN,HIGH);
  digitalWrite(A_DIR_PIN,HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  for(long i=0;i<TOTAL;i++){
  	// oneshot();
    oneshot2();
    if (i%1000==0) Serial.println("processing");
  }

  Serial.println("CCW");
  digitalWrite(X1_DIR_PIN,LOW);
  // digitalWrite(X2_DIR_PIN,LOW);
  digitalWrite(Y1_DIR_PIN,LOW);
  // digitalWrite(Y2_DIR_PIN,LOW);
  digitalWrite(Z1_DIR_PIN,LOW);
  // digitalWrite(Z2_DIR_PIN,LOW);
  digitalWrite(E_DIR_PIN, LOW);
  digitalWrite(A_DIR_PIN, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  for(long i=0;i<TOTAL;i++){
  	// oneshot();
    oneshot2();
    if (i%1000==0) Serial.println("processing");
  }
}

