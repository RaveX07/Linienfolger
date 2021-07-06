#include <Arduino.h>
#include <QTRSensors.h>

#define LEFT_EN_PIN 7
#define LEFT_PWM_PIN_R 10
#define LEFT_PMW_PIN_L 11
#define RIGHT_EN_PIN 8
#define RIGHT_PWM_PIN_L 6
#define RIGHT_PWM_PIN_R 5

#define IR_RIGHT A0
#define IR_BETWEEN_RIGHT A1
#define IR_MID_RIGHT A2
#define IR_MID_LEFT A3
#define IR_BETWEEN_LEFT A4
#define IR_LEFT A5

QTRSensors qtr;

const uint8_t SensorCount = 6;
uint16_t sensorValues[SensorCount];

#define sensorRight sensorValues[0]
#define sensorBetweenRight sensorValues[1]
#define sensorMiddleRight sensorValues[2]
#define sensorMiddleLeft sensorValues[3]
#define sensorBetweenLeft sensorValues[4]
#define sensorLeft sensorValues[5]

#define blackWhiteValue 550

void setup()
{
    Serial.begin(115200);

    pinMode(LEFT_EN_PIN, OUTPUT);
    pinMode(LEFT_PMW_PIN_L, OUTPUT);
    pinMode(LEFT_PWM_PIN_R, OUTPUT);
    pinMode(RIGHT_EN_PIN, OUTPUT);
    pinMode(RIGHT_PWM_PIN_L, OUTPUT);
    pinMode(RIGHT_PWM_PIN_R, OUTPUT);

    digitalWrite(LEFT_EN_PIN, HIGH);
    digitalWrite(RIGHT_EN_PIN, HIGH);

    qtr.setTypeAnalog();
    qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5}, SensorCount);

    delay(500);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    for (uint16_t i = 0; i < 400; i++)
    {
        qtr.calibrate();
    }
    digitalWrite(LED_BUILTIN, LOW);

    Serial.println("READY!!!");
}
//if direction is true than do right

void driveForward(int speed)
{
    Serial.print("Drive forward with speed ");
    Serial.println(speed);
    analogWrite(LEFT_PWM_PIN_R, 0);
    analogWrite(LEFT_PMW_PIN_L, speed);
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
        analogWrite(LEFT_PWM_PIN_R, 100);
        analogWrite(RIGHT_PWM_PIN_L, 0);
        analogWrite(RIGHT_PWM_PIN_R, speed);
    }
    else
    {
        analogWrite(LEFT_PMW_PIN_L, 0);
        analogWrite(LEFT_PWM_PIN_R, speed);
        analogWrite(RIGHT_PWM_PIN_L, 0);
        analogWrite(RIGHT_PWM_PIN_R, 100);
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

void loop()
{

    qtr.read(sensorValues);
    for (auto &&sensor : sensorValues)
    {
        Serial.print(sensor);
        Serial.print(" ");
    }
    Serial.println("");
    return;

    if ((sensorMiddleLeft > blackWhiteValue && sensorMiddleRight > blackWhiteValue) || (sensorMiddleRight > blackWhiteValue) || (sensorMiddleLeft > blackWhiteValue))
    {
        driveForward(100);
    }
    else if ((sensorBetweenLeft > blackWhiteValue && sensorLeft > blackWhiteValue) || (sensorLeft > blackWhiteValue) || (sensorBetweenLeft > blackWhiteValue))
    {
        correct(75, false);
    }
    else if ((sensorBetweenRight > blackWhiteValue && sensorRight > blackWhiteValue) || (sensorRight > blackWhiteValue) || (sensorBetweenRight > blackWhiteValue))
    {
        correct(65, true);
    }
    else
    {
        turn(50, false);
        for (int i = 0; i < 1000; i++)
        {
            delay(1);
            qtr.read(sensorValues);
            if ((sensorLeft < blackWhiteValue) && (sensorBetweenLeft < blackWhiteValue) && (sensorMiddleLeft < blackWhiteValue) && (sensorMiddleRight < blackWhiteValue) && (sensorBetweenRight < blackWhiteValue) && (sensorRight < blackWhiteValue))
            {
                return;
            }
        }
        turn(50, true);
        for (int i = 0; i < 2000; i++)
        {
            delay(1);
            qtr.read(sensorValues);
            if ((sensorLeft < blackWhiteValue) && (sensorBetweenLeft < blackWhiteValue) && (sensorMiddleLeft < blackWhiteValue) && (sensorMiddleRight < blackWhiteValue) && (sensorBetweenRight < blackWhiteValue) && (sensorRight < blackWhiteValue))
            {
                return;
            }
        }
        turn(50, false);
        for (int i = 0; i < 1000; i++)
        {
            delay(1);
            qtr.read(sensorValues);
            if ((sensorLeft < blackWhiteValue) && (sensorBetweenLeft < blackWhiteValue) && (sensorMiddleLeft < blackWhiteValue) && (sensorMiddleRight < blackWhiteValue) && (sensorBetweenRight < blackWhiteValue) && (sensorRight < blackWhiteValue))
            {
                return;
            }
        }
        driveForward(50);
        for (int i = 0; i < 1000; i++)
        {
            delay(1);
            qtr.read(sensorValues);
            if ((sensorLeft < blackWhiteValue) && (sensorBetweenLeft < blackWhiteValue) && (sensorMiddleLeft < blackWhiteValue) && (sensorMiddleRight < blackWhiteValue) && (sensorBetweenRight < blackWhiteValue) && (sensorRight < blackWhiteValue))
            {
                return;
            }
        }
    }
}