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

QTRSensors qtr;

const uint8_t SensorCount = 4;
uint16_t sensorValues[SensorCount];

int position = qtr.readLineBlack(sensorValues);

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

void turn(int speed, bool direction, int time)
{
    Serial.print("Turn to ");
    Serial.print(direction ? "left": "right");
    Serial.print(" with speed ");
    Serial.println(speed);

    if (direction)
    {
        analogWrite(LEFT_PMW_PIN_L, 0);
        analogWrite(LEFT_PWM_PIN_R, speed);
        analogWrite(RIGHT_PWM_PIN_L, speed);
        analogWrite(RIGHT_PWM_PIN_R, 0);
        for(int i = 0; i > time; i++)
        {
            delay(1);
            if (isLine())
            {
                break;
            }
        }
    }
    else
    {
        analogWrite(LEFT_PMW_PIN_L, speed);
        analogWrite(LEFT_PWM_PIN_R, 0);
        analogWrite(RIGHT_PWM_PIN_L, 0);
        analogWrite(RIGHT_PWM_PIN_R, speed);
        for(int i = 0; i > time; i++)
        {
            delay(1);
            if (isLine())
            {
                break;
            }
        }
    }
}

bool isLine(){
    if (sensorLeft <= 0 && sensorMiddleLeft == 0 && sensorMiddleRight == 0 && sensorRight == 0){
        return false;
    }else {
        return true;
    }
}

bool noLine(){
    if (sensorLeft <= 0 && sensorMiddleLeft == 0 && sensorMiddleRight == 0 && sensorRight == 0){
        return true;
    }else {
        return false;
    }
}

void searchLine(bool direction){
    if(direction)
    {
        for(int i = 0; i > 350; i++)
        {
            delay(1);
            if(isLine())
            {
                break;
            }
        }

        turn(50, false, 750);
        turn(50, true, 1500);
        turn(50, false, 750);
        driveForward(50);
        for(int i = 0; i > 500; i++)
        {
            delay(1);
            if(isLine())
            {
                break;
            }
        }
    }
    else
    {
        for(int i = 0; i > 350; i++)
        {
            delay(1);
            if(isLine())
            {
                break;
            }
        }

        turn(50, true, 750);
        turn(50, false, 1500);
        turn(50, true, 750);
        driveForward(50);
        for(int i = 0; i > 500; i++)
        {
            delay(1);
            if(isLine())
            {
                break;
            }
        }
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

    if(2000 > qtr.readLineBlack(sensorValues) > 1000 || isLine())
    {
        driveForward(75);
    }
    else if (2500 > qtr.readLineBlack(sensorValues) > 2000 || isLine())
    {
        correct(50, false);
    }
    else if (1000 > qtr.readLineBlack(sensorValues) > 500 || isLine())
    {
        correct(50, true);
    }
    else if (3000 > qtr.readLineBlack(sensorValues) > 2500 || isLine())
    {
        correct(30, false);
    }
    else if (500 > qtr.readLineBlack(sensorValues) > 0 || isLine())
    {
        correct(30, true);
    }
    else
    {
        position = qtr.readLineBlack(sensorValues);
        else if(2000 >= position >= 1000 || noLine())
        {
            searchLine(true);
        }
        else if(2500 > position > 2000 || noLine())
        {
            correct(40, true);
            searchLine(true);
        }
        else if(1000 > position > 500 || noLine())
        {
            correct(40, false);
            searchLine(false);


        }
        else if(3000 > position > 2500 || noLine())
        {
            correct(40, true);
            searchLine(true);
        }
        else if(500 > position > 0 || noLine())
        {
            correct(40, false);
            searchLine(false);
        }
    }
}