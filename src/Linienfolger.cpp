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
int ir_sensor_Left = A0;
int ir_sensor_HalfLeft = A1;
int ir_sensor_LeftFromMiddle = A2;
int ir_sensor_MiddleLeft = A3;
int ir_sensor_MiddleRight = A4;
int ir_sensor_RightFromMiddle = A5;
int ir_sensor_HalfRight = 8;
int ir_sensor_Right = 9;

//function for checking for objects on the front
int checkDistanceFront()
{
  //make sure that the trigpins are disabled
  digitalWrite(US_FRONT_ECHO, LOW);
  delayMicroseconds(2);

  //send ultrasonic signal
  digitalWrite(US_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_TRIGGER, LOW);

  //messure duration and  calculate distance
  durationF = pulseIn(US_FRONT_ECHO, HIGH);
  distanceF = durationF * 0.034 / 2; //distance in cm
}

//function for checking for objects on the sides
int checkDistanceRight(){
  //make sure that the trigpins are disabled
  digitalWrite(US_TRIGGER, LOW);
  delayMicroseconds(2);

  //Right check
  
  //send ultrasonic signal
  digitalWrite(US_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_TRIGGER, LOW);

  //messure duration and calculate distance
  durationR = pulseIn(US_RIGHT_ECHO, HIGH);
  distanceR = durationR*0.034/2; //distance in cm
}

int checkDistanceLeft () {
    //Left check
  
  //send ultrasonic signal
  digitalWrite(US_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_TRIGGER, LOW);

  //messure duration and calculate distance
  durationL = pulseIn(US_LEFT_ECHO, HIGH);
  distanceL = durationL*0.034/2; //distance in cm


}


int drive()
{
  ir_sensor_Left = digitalRead(A0);
  ir_sensor_HalfLeft = digitalRead(A1);
  ir_sensor_LeftFromMiddle = digitalRead(A2);
  ir_sensor_MiddleLeft = digitalRead(A3);
  ir_sensor_MiddleRight = digitalRead(A4);
  ir_sensor_RightFromMiddle = digitalRead(A5);
  ir_sensor_HalfRight = digitalRead(8);
  ir_sensor_Right = digitalRead(9);

  if (ir_sensor_RightFromMiddle == 1)
  {
    analogWrite(LEFT_PWM_PIN_FORWARD, 200);
    analogWrite(RIGHT_PWM_PIN_FORWARD, 190);
  }
  else if (ir_sensor_LeftFromMiddle == 1)
  {
    analogWrite(LEFT_PWM_PIN_FORWARD, 190);
    analogWrite(RIGHT_PWM_PIN_FORWARD, 200);
  }
  else if (ir_sensor_HalfRight == 1)
  {
    analogWrite(LEFT_PWM_PIN_FORWARD, 200);
    analogWrite(RIGHT_PWM_PIN_FORWARD, 180);
  }
  else if (ir_sensor_HalfLeft == 1)
  {
    analogWrite(LEFT_PWM_PIN_FORWARD, 180);
    analogWrite(RIGHT_PWM_PIN_FORWARD, 200);
  }
  else if (ir_sensor_Right == 1)
  {
    analogWrite(LEFT_PWM_PIN_FORWARD, 200);
    analogWrite(RIGHT_PWM_PIN_FORWARD, 170);
  }
  else if (ir_sensor_Left == 1)
  {
    analogWrite(LEFT_PWM_PIN_FORWARD, 170);
    analogWrite(RIGHT_PWM_PIN_FORWARD, 200);
  }
  else if ((ir_sensor_MiddleLeft == 1) && (ir_sensor_MiddleRight == 0))
  {
    analogWrite(RIGHT_PWM_PIN_FORWARD, 200);
    analogWrite(LEFT_PWM_PIN_FORWARD, 195);
  }
  else if ((ir_sensor_MiddleLeft == 0) && (ir_sensor_MiddleRight == 1))
  {
    analogWrite(RIGHT_PWM_PIN_FORWARD, 195);
    analogWrite(LEFT_PWM_PIN_FORWARD, 200);
  }
}

  void setup()
  {
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

  void loop()
  {
    drive();
  }
