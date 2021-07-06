#include <Arduino.h>
#include <NewPing.h>

// Hook up HC-SR04 with Trig to Arduino Pin 9, Echo to Arduino pin 10
#define TRIGGER_PIN 3
#define ECHO_PIN1 12
#define ECHO_PIN2 4
#define ECHO_PIN3 9

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400	



// NewPing setup of pins and maximum distance.
NewPing sonar1(TRIGGER_PIN, ECHO_PIN1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN, ECHO_PIN2, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN, ECHO_PIN3, MAX_DISTANCE);
float duration1, distance1, duration2, distance2, duration3, distance3;

void setup() 
{
	Serial.begin(115200);
	pinMode(TRIGGER_PIN, OUTPUT);
	pinMode(ECHO_PIN1, INPUT);
	pinMode(ECHO_PIN2, INPUT);
	pinMode(ECHO_PIN3, INPUT);
}

void loop() 
{
	// Send ping, get distance in cm
	distance1 = sonar1.ping_cm();
	distance2 = sonar2.ping_cm();
	distance3 = sonar3.ping_cm();
	
	Serial.print("Distance Left = ");
	
	if (distance1 <= 0) 
	{
		Serial.println("Out of range");
	}
	else 
	{
		Serial.print(distance1);
		Serial.println(" cm");
	}

	Serial.print("Distance Front = ");
	
	if (distance2 <= 0) 
	{
		Serial.println("Out of range");
	}
	else 
	{
		Serial.print(distance2);
		Serial.println(" cm");
	}

	Serial.print("Distance Right = ");
	
	if (distance3 <= 0) 
	{
		Serial.println("Out of range");
	}
	else 
	{
		Serial.print(distance3);
		Serial.println(" cm");
	}
	delay(500);


}