#include <Arduino.h>
#include <HCSR04.h>

#define sensorTrigPin    8
#define sensorEchoPin1   2
#define sensorEchoPin2   3
#define sensorEchoPin3   9

HCSR04 hc1(8, sensorEchoPin1);
HCSR04 hc2(8, sensorEchoPin2);
HCSR04 hc3(8, sensorEchoPin3);

long duration;
int distance;

void setup()
{
    Serial.begin(115200);
    pinMode(sensorTrigPin, OUTPUT);
    pinMode(sensorEchoPin1, INPUT);
    pinMode(sensorEchoPin2, INPUT);
    pinMode(sensorEchoPin3, INPUT);
}

void loop()
{
    // digitalWrite(sensorTrigPin, LOW);
    // delayMicroseconds(2);
    // digitalWrite(sensorTrigPin, HIGH);
    // delayMicroseconds(10);
    // digitalWrite(sensorTrigPin, LOW);

    // duration = pulseIn(sensorEchoPin1, HIGH);
    // distance = (duration/2) / 29.1;

    // Serial.print("Distance: ");
    // Serial.println(distance);
    // delay(1000);
    
    Serial.print("1: ");
    Serial.println(hc1.dist());
    Serial.print("2: ");
    Serial.println(hc2.dist());
    Serial.print("3: ");
    Serial.println(hc3.dist());

    delay(500);    
}