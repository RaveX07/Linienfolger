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
int UltrasonicLeft = 1;

//Ultrasonic Sensor Left/Middle?
#define US_LEFT_ECHO 3
long durationL;
int distanceL;
int UltrasonicRight = 8

//Ultrasonic Sensor Right
#define US_RIGHT_ECHO 2
;long durationR;
int distanceR;
int UltrasonicRight = 9;

//IR-Sensors
int ir_sensor_Left = 0;
int ir_sensor_HalfLeft = 0;
int ir_sensor_LeftFromMiddle = 0;
int ir_sensor_MiddleLeft = 0;
int ir_sensor_MiddleRight = 0;
int ir_sensor_RightFromMiddle = 0;
int ir_sensor_HalfRight = 0;
int ir_sensor_Right = 0;

int readAllIRSensors(){
  ir_sensor_Left = digitalRead(A0);
  ir_sensor_HalfLeft = digitalRead(A1);
  ir_sensor_LeftFromMiddle = digitalRead(A2);
  ir_sensor_MiddleLeft = digitalRead(A3);
  ir_sensor_MiddleRight = digitalRead(A4);
  ir_sensor_RightFromMiddle = digitalRead(A5);
  ir_sensor_HalfRight = digitalRead(0); 
  ir_sensor_Right = digitalRead(?);
}

int findline(){
  readAllIRSensors();
  if ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
  (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
  (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

    while ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
    (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
    (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

      analogWrite(LEFT_PWM_PIN_FORWARD, 125);
      analogWrite(RIGHT_PWM_PIN_FORWARD, 125);
      delay(500);
      analogWrite(LEFT_PWM_PIN_FORWARD, 0);
      analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
      readAllIRSensors();

        while ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
        (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
        (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

            analogWrite(LEFT_PWM_PIN_FORWARD, 100);
            analogWrite(RIGHT_PWM_PIN_FORWARD, 50);
            delay(3000);
            analogWrite(LEFT_PWM_PIN_FORWARD, 0);
            analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
            readAllIRSensors();

                while ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
                (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
                (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

                    analogWrite(RIGHT_PWM_PIN_FORWARD, 100);
                    delay(300);
                    analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
                    delay(10)
                    analogWrite(RIGHT_PWM_PIN_FORWARD, 100);
                    analogWrite(LEFT_PWM_PIN_FORWARD, 50);
                    delay(6000);
                    analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
                    analogWrite(LEFT_PWM_PIN_FORWARD, 0);
                    readAllIRSensors();

                        while ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
                        (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
                        (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

                            analogWrite(LEFT_PWM_PIN_FORWARD, 100);
                            delay(100);
                            analogWrite(LEFT_PWM_PIN_FORWARD, 0);
                            delay(10)
                            analogWrite(LEFT_PWM_PIN_FORWARD, 100);
                            analogWrite(RIGHT_PWM_PIN_FORWARD, 50);
                            delay(3000);
                            analogWrite(LEFT_PWM_PIN_FORWARD, 0);
                            analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
                            readAllIRSensors();

            }
        }
      }
    }
    analogWrite (RIGHT_PWM_PIN_FORWARD, 100)
    delay(100)
    analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
    delay(10)
    analogWrite(LEFT_PWM_PIN_FORWARD, 125);
    analogWrite(RIGHT_PWM_PIN_FORWARD, 125);
    delay(500);
    analogWrite(LEFT_PWM_PIN_FORWARD, 0);
    analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
    readAllIRSensors();
    
  }
  readAllIRSensors();
  if ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
  (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
  (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

    while ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
    (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
    (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

      analogWrite(LEFT_PWM_PIN_FORWARD, 125);
      analogWrite(RIGHT_PWM_PIN_FORWARD, 125);
      delay(1000);
      analogWrite(LEFT_PWM_PIN_FORWARD, 0);
      analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
      readAllIRSensors();

        while ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
        (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
        (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

            analogWrite(LEFT_PWM_PIN_FORWARD, 100);
            analogWrite(RIGHT_PWM_PIN_FORWARD, 50);
            delay(3000);
            analogWrite(LEFT_PWM_PIN_FORWARD, 0);
            analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
            readAllIRSensors();

                while ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
                (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
                (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

                    analogWrite(RIGHT_PWM_PIN_FORWARD, 100);
                    delay(300);
                    analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
                    delay(10)
                    analogWrite(RIGHT_PWM_PIN_FORWARD, 100);
                    analogWrite(LEFT_PWM_PIN_FORWARD, 50);
                    delay(6000);
                    analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
                    analogWrite(LEFT_PWM_PIN_FORWARD, 0);
                    readAllIRSensors();

                        while ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
                        (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
                        (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

                            analogWrite(LEFT_PWM_PIN_FORWARD, 100);
                            delay(100);
                            analogWrite(LEFT_PWM_PIN_FORWARD, 0);
                            delay(10)
                            analogWrite(LEFT_PWM_PIN_FORWARD, 100);
                            analogWrite(RIGHT_PWM_PIN_FORWARD, 50);
                            delay(3000);
                            analogWrite(LEFT_PWM_PIN_FORWARD, 0);
                            analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
                            readAllIRSensors();

            }
        }
      }
    }
    analogWrite (RIGHT_PWM_PIN_FORWARD, 100)
    delay(100)
    analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
    delay(10)
    analogWrite(LEFT_PWM_PIN_FORWARD, 125);
    analogWrite(RIGHT_PWM_PIN_FORWARD, 125);
    delay(1000);
    analogWrite(LEFT_PWM_PIN_FORWARD, 0);
    analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
    readAllIRSensors();
  }
    readAllIRSensors();
  if ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
  (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
  (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

    while ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
    (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
    (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

      analogWrite(LEFT_PWM_PIN_FORWARD, 125);
      analogWrite(RIGHT_PWM_PIN_FORWARD, 125);
      delay(1500);
      analogWrite(LEFT_PWM_PIN_FORWARD, 0);
      analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
      readAllIRSensors();

        while ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
        (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
        (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

            analogWrite(LEFT_PWM_PIN_FORWARD, 100);
            analogWrite(RIGHT_PWM_PIN_FORWARD, 50);
            delay(3000);
            analogWrite(LEFT_PWM_PIN_FORWARD, 0);
            analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
            readAllIRSensors();

                while ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
                (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
                (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

                    analogWrite(RIGHT_PWM_PIN_FORWARD, 100);
                    delay(300);
                    analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
                    delay(10)
                    analogWrite(RIGHT_PWM_PIN_FORWARD, 100);
                    analogWrite(LEFT_PWM_PIN_FORWARD, 50);
                    delay(6000);
                    analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
                    analogWrite(LEFT_PWM_PIN_FORWARD, 0);
                    readAllIRSensors();

                        while ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
                        (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
                        (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

                            analogWrite(LEFT_PWM_PIN_FORWARD, 100);
                            delay(100);
                            analogWrite(LEFT_PWM_PIN_FORWARD, 0);
                            delay(10)
                            analogWrite(LEFT_PWM_PIN_FORWARD, 100);
                            analogWrite(RIGHT_PWM_PIN_FORWARD, 50);
                            delay(3000);
                            analogWrite(LEFT_PWM_PIN_FORWARD, 0);
                            analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
                            readAllIRSensors();

            }
        }
      }
    }
    analogWrite (RIGHT_PWM_PIN_FORWARD, 100)
    delay(100)
    analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
    delay(10)
    analogWrite(LEFT_PWM_PIN_FORWARD, 125);
    analogWrite(RIGHT_PWM_PIN_FORWARD, 125);
    delay(1500);
    analogWrite(LEFT_PWM_PIN_FORWARD, 0);
    analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
    readAllIRSensors();
  }
    readAllIRSensors();
  if ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
  (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
  (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

    while ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
    (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
    (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

      analogWrite(LEFT_PWM_PIN_FORWARD, 125);
      analogWrite(RIGHT_PWM_PIN_FORWARD, 125);
      delay(2000);
      analogWrite(LEFT_PWM_PIN_FORWARD, 0);
      analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
      readAllIRSensors();

        while ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
        (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
        (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

            analogWrite(LEFT_PWM_PIN_FORWARD, 100);
            analogWrite(RIGHT_PWM_PIN_FORWARD, 50);
            delay(3000);
            analogWrite(LEFT_PWM_PIN_FORWARD, 0);
            analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
            readAllIRSensors();

                while ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
                (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
                (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

                    analogWrite(RIGHT_PWM_PIN_FORWARD, 100);
                    delay(300);
                    analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
                    delay(10)
                    analogWrite(RIGHT_PWM_PIN_FORWARD, 100);
                    analogWrite(LEFT_PWM_PIN_FORWARD, 50);
                    delay(6000);
                    analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
                    analogWrite(LEFT_PWM_PIN_FORWARD, 0);
                    readAllIRSensors();

                        while ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) &&
                        (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) &&
                        (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {

                            analogWrite(LEFT_PWM_PIN_FORWARD, 100);
                            delay(100);
                            analogWrite(LEFT_PWM_PIN_FORWARD, 0);
                            delay(10)
                            analogWrite(LEFT_PWM_PIN_FORWARD, 100);
                            analogWrite(RIGHT_PWM_PIN_FORWARD, 50);
                            delay(3000);
                            analogWrite(LEFT_PWM_PIN_FORWARD, 0);
                            analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
                            readAllIRSensors();

            }
        }
      }
    }
  }
    analogWrite (RIGHT_PWM_PIN_FORWARD, 100)
    delay(100)
    analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
    delay(10)
    analogWrite(LEFT_PWM_PIN_FORWARD, 125);
    analogWrite(RIGHT_PWM_PIN_FORWARD, 125);
    delay(500);
    analogWrite(LEFT_PWM_PIN_FORWARD, 0);
    analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
    readAllIRSensors();
}
