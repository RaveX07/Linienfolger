#include <Arduino.h>

//Left Motor
int LR_IS = pin;
int LR_EN = pin;
int LR_PWM = pin;
int LL_IS = pin;
int LL_EN = pin;
int LL_PWM = pin;

//Right Motor
int RR_IS = pin;
int RR_EN = pin;
int RR_PWM = pin;
int RL_IS = pin;
int RL_EN = pin;
int RL_PWM = pin;

//Ultrasonic Sensor Left
const int trigPinL = pin;
const int echoPinL = pin;
long durationL;
int distanceL;

//Ultrasonic Sensor Front Left
const int trigPinFL = pin;
const int echoPinFL = pin;
long durationFL;
int distanceFL;

//Ultrasonic Sensor Front Right
const int trigPinFR = pin;
const int echoPinFR = pin;
long durationFR;
int distanceFR;

//Ultrasonic Sensor Right
const int trigPinR = pin;
const int echoPinR = pin;
long durationR;
int distanceR;

//function for checking for objects on the front
int checkDistanceFront(){
  //make sure that the trigpins are disabled
  digitalWrite(trigPinFL, LOW);
  digitalWrite(trigPinFR, LOW);
  delayMicroseconds(2);

  //frontLeft check
  
  //send ultrasonic signal
  digitalWrite(trigPinFL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFL; LOW);

  //messure duration and  calculate distance
  durationFL = pulseIn(echoPinFL, HIGH);
  distanceFL = durationFR*0.034/2; //distance in cm


  //frontRight check
  
  //send ultrasonic signal
  digitalWrite(trigPinFR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFR, LOW);

  //messure duration and calculate distance
  durationFR = pulseIn(echoPinFR, HIGH);
  distanceFR = durationFR*0.034/2; //distance in cm
}

//function for checking for objects on the sides
int checkDistanceSides(){
  //make sure that the trigpins are disabled
  digitalWrite(trigPinR, LOW);
  digitalWrite(trigPinL, LOW);
  delayMicroseconds(2);

  //Left check
  
  //send ultrasonic signal
  digitalWrite(trigPinL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinL; LOW);

  //messure duration and calculate distance
  durationL = pulseIn(echoPinL, HIGH);
  distanceL = durationL*0.034/2; //distance in cm


  //Right check
  
  //send ultrasonic signal
  digitalWrite(trigPinR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinR, LOW);

  //messure duration and calculate distance
  durationR = pulseIn(echoPinR, HIGH);
  distanceR = durationR*0.034/2; //distance in cm
}

void setup() {
  Serial.begin(9600);
  
  //LeftMotor
  pinMode(LR_IS, OUTPUT);
  pinMode(LR_PWM, OUTPUT);
  pinMode(LR_EN, OUTPUT);
  pinMode(LL_IS, OUTPUT);
  pinMode(LL_PWM, OUTPUT);
  pinMode(LL_EN, OUTPUT);
  digitalWrite(LR_IS, LOW);
  digitalWrite(LL_IS, LOW);
  digitalWrite(LR_EN, HIGH);
  digitalWrite(LL_EN, HIGH);

  //RightMotor
  pinMode(RR_IS, OUTPUT);
  pinMode(RR_PWM, OUTPUT);
  pinMode(RR_EN, OUTPUT);
  pinMode(RL_IS, OUTPUT);
  pinMode(RL_PWM, OUTPUT);
  pinMode(RL_EN, OUTPUT);
  digitalWrite(RR_IS, LOW);
  digitalWrite(RL_IS, LOW);
  digitalWrite(RR_EN, HIGH);
  digitalWrite(RL_EN, HIGH);

  //IR-Sensors
  int sensor1 = digitalRead(pin);
  int sensor2 = digitalRead(pin);
  int sensor3 = digitalRead(pin);
  int sensor4 = digitalRead(pin);
  int sensor5 = digitalRead(pin);
  int sensor6 = digitalRead(pin);
  int sensor7 = digitalRead(pin);
  int sensor8 = digitalRead(pin);

}

void loop() {
  // put your main code here, to run repeatedly:

}
