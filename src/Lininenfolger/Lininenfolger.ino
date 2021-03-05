#include <Arduino.h>

//Left Motor
#define LEFT_ENABLE_PIN 12
#define LEFT_PWM_PIN_FORWARD 11
#define LEFT_PWM_PIN_BACKWARD 10

//PWM PINS: 11, 10, 9, 6, 5, 3

//Right Motor
#define RIGHT_ENABLE_PIN 7
#define RIGHT_PWM_PIN_FORWARD 6
#define RIGHT_PWM_PIN_BACKWARD 5

//Trigger
#define US_TRIGGER 13

//Ultrasonic Sensor Left
#define US_FRONT_ECHO 4
long durationF;
int distanceF;
int UltrasonicLeft = 2;

//Ultrasonic Sensor Left/Middle?
#define US_LEFT_ECHO 3
long durationL;
int distanceL;

//Ultrasonic Sensor Right
#define US_RIGHT_ECHO 2
long durationR;
int distanceR;
int UltrasonicRight = 9;

//IR-Sensors
int ir_sensor_array[8] = {A0, A1, A2, A3, A4, A5, 8, 9};


//function for checking for objects on the front
int checkDistanceFront(){
  //make sure that the trigpins are disabled
  digitalWrite(US_FRONT_ECHO, LOW);
  delayMicroseconds(2);


  //send ultrasonic signal
  digitalWrite(US_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_TRIGGER, LOW);

  //messure duration and  calculate distance
  durationF = pulseIn(US_FRONT_ECHO, HIGH);
  distanceF = durationF*0.034/2; //distance in cm


}

//function for checking for objects on the sides
int checkDistanceSides(){
  //make sure that the trigpins are disabled
  digitalWrite(US_TRIGGER, LOW);
  delayMicroseconds(2);

  //Left check
  
  //send ultrasonic signal
  digitalWrite(US_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_TRIGGER, LOW);

  //messure duration and calculate distance
  durationL = pulseIn(US_LEFT_ECHO, HIGH);
  distanceL = durationL*0.034/2; //distance in cm


  //Right check
  
  //send ultrasonic signal
  digitalWrite(US_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_TRIGGER, LOW);

  //messure duration and calculate distance
  durationR = pulseIn(US_RIGHT_ECHO, HIGH);
  distanceR = durationR*0.034/2; //distance in cm
}

void setup() {
  Serial.begin(9600);

  pinMode(LEFT_PWM_PIN_BACKWARD, OUTPUT);
  pinMode(LEFT_PWM_PIN_FORWARD, OUTPUT);
  pinMode(LEFT_ENABLE_PIN, OUTPUT);
  pinMode(RIGHT_ENABLE_PIN, OUTPUT);
  pinMode(RIGHT_PWM_PIN_BACKWARD, OUTPUT);
  pinMode(RIGHT_PWM_PIN_FORWARD, OUTPUT);
  
  digitalWrite(LEFT_ENABLE_PIN, HIGH);
  digitalWrite(RIGHT_ENABLE_PIN, HIGH);

}
 
