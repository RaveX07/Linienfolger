#include <Arduino.h>
#include <QTRSensors.h>

#define LEFT_EN_PIN 7
#define LEFT_PWM_PIN_R 10
#define LEFT_PMW_PIN_L 11
#define RIGHT_EN_PIN 8
#define RIGHT_PWM_PIN_L 5
#define RIGHT_PWM_PIN_R 6

#define IR_LEFT A0
#define IR_MID_LEFT A5
#define IR_MID_RIGHT A4
#define IR_RIGHT A3

int iterration = 0;

QTRSensors qtr;

const uint8_t SensorCount = 4;
uint16_t sensorValues[SensorCount];

#define sensorLeft sensorValues[0]
#define sensorMiddleLeft sensorValues[1]
#define sensorMiddleRight sensorValues[2]
#define sensorRight sensorValues[3]

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
    qtr.setSensorPins((const uint8_t[]){A0, A5, A4, A3}, SensorCount);

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

void loop()
{

    qtr.readCalibrated(sensorValues);
    for (auto &&sensor : sensorValues)
    {
        Serial.print(sensor);
        Serial.print(" ");
    }

    if ((sensorMiddleLeft > blackWhiteValue && sensorMiddleRight > blackWhiteValue) || (sensorMiddleRight > blackWhiteValue) || (sensorMiddleLeft > blackWhiteValue))
    {
        driveForward(75);
        iterration = 0;
    }
    else if (sensorLeft > blackWhiteValue)
    {
        correct(40, false);
        iterration = 0;
    }
    else if (sensorRight > blackWhiteValue)
    {
        correct(40, true);
        iterration = 0;
    }
    else
    {
        if(iterration == 0){
            turn(50, false);
            for (int i = 0; i < 1000; i++)
            {
                delay(1);
                qtr.readCalibrated(sensorValues);
                if ((sensorLeft > blackWhiteValue) || (sensorMiddleLeft > blackWhiteValue) || (sensorMiddleRight > blackWhiteValue) || (sensorRight > blackWhiteValue))
                {
                    return;
                }
            }
        }
        
        turn(50, true);
        for (int i = 0; i < 2000; i++)
        {
            delay(1);
            qtr.readCalibrated(sensorValues);
            if ((sensorLeft > blackWhiteValue) || (sensorMiddleLeft > blackWhiteValue) || (sensorMiddleRight > blackWhiteValue) || (sensorRight > blackWhiteValue))
            {
                return;
            }
        }
        turn(50, false);
        for (int i = 0; i < 2000; i++)
        {
            delay(1);
            qtr.readCalibrated(sensorValues);
            if ((sensorLeft > blackWhiteValue) || (sensorMiddleLeft > blackWhiteValue) || (sensorMiddleRight > blackWhiteValue) || (sensorRight > blackWhiteValue))
            {
                return;
            }
        }
        iterration = 1;
    }
}