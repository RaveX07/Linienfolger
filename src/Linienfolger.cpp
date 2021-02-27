#include <Arduino.h>

//Left Motor
#define LEFT_ENABLE_PIN 12
#define LEFT_PWM_PIN_FORWARD 11
#define LEFT_PWM_PIN_BACKWARD 10

//PWM: 11, 10, 9, 6, 5, 3

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

//Ultrasonic Sensor Left
#define US_LEFT_ECHO 3
long durationL;
int distanceL;

//Ultrasonic Sensor Right
#define US_RIGHT_ECHO 2
long durationR;
int distanceR;

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

void loop() {
  // put your main code here, to run repeatedly:

}
 



void loop() {
  // put your main code here, to run repeatedly:

}
