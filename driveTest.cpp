#include <Arduino.h>

#define LEFT_EN_PIN 7
#define LEFT_PWM_PIN_R 10
#define LEFT_PMW_PIN_L 11
#define RIGHT_EN_PIN 8
#define RIGHT_PWM_PIN_L 5
#define RIGHT_PWM_PIN_R 6

void setup(){

    Serial.begin(115200);

    pinMode(LEFT_EN_PIN, OUTPUT);
    pinMode(LEFT_PMW_PIN_L, OUTPUT);
    pinMode(LEFT_PWM_PIN_R, OUTPUT);
    pinMode(RIGHT_EN_PIN, OUTPUT);
    pinMode(RIGHT_PWM_PIN_L, OUTPUT);
    pinMode(RIGHT_PWM_PIN_R, OUTPUT);

    digitalWrite(LEFT_EN_PIN, HIGH);
    digitalWrite(RIGHT_EN_PIN, HIGH);
}

void driveForward(int speed)
{
    Serial.print("Drive forward with speed ");
    Serial.println(speed);
    analogWrite(LEFT_PWM_PIN_R, speed);
    analogWrite(LEFT_PMW_PIN_L, 0);
    analogWrite(RIGHT_PWM_PIN_R, speed);
    analogWrite(RIGHT_PWM_PIN_L, 0);
}

void correct(int speed, bool direction)
{
    Serial.print("Drive to ");
    Serial.print(direction ? "left": "right");
    Serial.print(" with speed ");
    Serial.println(speed);
    if (direction)
    {
        analogWrite(LEFT_PMW_PIN_L, 0);
        analogWrite(LEFT_PWM_PIN_R, 75);
        analogWrite(RIGHT_PWM_PIN_L, 0);
        analogWrite(RIGHT_PWM_PIN_R, speed);
    }
    else
    {
        analogWrite(LEFT_PMW_PIN_L, 0);
        analogWrite(LEFT_PWM_PIN_R, speed);
        analogWrite(RIGHT_PWM_PIN_L, 0);
        analogWrite(RIGHT_PWM_PIN_R, 75);
    }
}

void turn(int speed, bool direction)
{
    Serial.print("Turn to ");
    Serial.print(direction ? "left": "right");
    Serial.print(" with speed ");
    Serial.println(speed);

    if (direction)
    {
        analogWrite(LEFT_PMW_PIN_L, 0);
        analogWrite(LEFT_PWM_PIN_R, speed);
        analogWrite(RIGHT_PWM_PIN_L, 0);
        analogWrite(RIGHT_PWM_PIN_R, 0);
    }
    else
    {
        analogWrite(LEFT_PMW_PIN_L, 0);
        analogWrite(LEFT_PWM_PIN_R, 0);
        analogWrite(RIGHT_PWM_PIN_L, 0);
        analogWrite(RIGHT_PWM_PIN_R, speed);
    }
}

void loop(){
    correct(40, false);
    delay(2000);
    correct(40, false);
}