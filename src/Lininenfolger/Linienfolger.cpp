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

  //meassure duration and calculate distance
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

int dogdeObstacle () {
checkDistanceFront;
checkDistanceLeft;
checkDistanceRight;
//Roboter trifft auf Hindernis maximal 3 cm vor ihm
while (distanceF < 3)
{
  checkDistanceRight ();
  checkDistanceLeft ();
  checkDistanceFront ();
//Roboter dreht sich um sich selbst, bis das Hindernis neben ihm ist
  while ((distanceL > 3) && (distanceR > 3))
  {
    digitalWrite (LEFT_PWM_PIN_FORWARD, 0);
    digitalWrite (RIGHT_PWM_PIN_FORWARD, 100);
    checkDistanceRight ();
    checkDistanceLeft ();
    checkDistanceFront ();
  };
//das Hindenis ist nun rechts neben ihm
  if (distanceR < 3)
  {
    checkDistanceRight ();
    checkDistanceLeft ();
    checkDistanceFront ();
//Er fähr solange gerade aus, bis das Hindernis nicht mehr neben ihm ist
    while (distanceR < 3)
    {
      digitalWrite (LEFT_PWM_PIN_FORWARD, 100);
      digitalWrite (RIGHT_PWM_PIN_FORWARD, 100);
      checkDistanceRight ();
      checkDistanceLeft ();
      checkDistanceFront ();
    };
  }
  //nun ist er am Hinderniss seitlich vorbeigefahren
  if ((distanceL > 3) && (distanceR > 3) && (distanceF > 3))
  {
    checkDistanceRight ();
    checkDistanceLeft ();
    checkDistanceFront ();
//nun fährt er eine Kurve nach rechts, bis er auf das Hindernis trifft
    while ((distanceL > 3) && (distanceR > 3) && (distanceF > 3))
    {
      digitalWrite (LEFT_PWM_PIN_FORWARD, 50);
      digitalWrite (RIGHT_PWM_PIN_FORWARD, 100);
      checkDistanceRight ();
      checkDistanceLeft ();
      checkDistanceFront ();
    };
  }

  checkDistanceFront;
  checkDistanceLeft;
  checkDistanceRight;
//das Hinderniss ist vor ihm
  if (distanceF < 3)
  {
    checkDistanceRight ();
    checkDistanceLeft ();
    checkDistanceFront ();
//er dreht sich um die eigene Achse, bis das Hindernis neben ihm ist
    while ((distanceL > 3) && (distanceR > 3))
    {
      digitalWrite (LEFT_PWM_PIN_FORWARD, 0);
      digitalWrite (RIGHT_PWM_PIN_FORWARD, 100);
      checkDistanceRight ();
      checkDistanceLeft ();
      checkDistanceFront ();
    }
    
  }
  checkDistanceFront;
  checkDistanceLeft;
  checkDistanceRight;
//das Hindernis ist nun rechts von ihm
  if (distanceR < 3)
  {
    checkDistanceRight ();
    checkDistanceLeft ();
    checkDistanceFront ();
//er fährt am Hindernis entlang, bis es nicht mehr rechts von ihm ist
    while (distanceR < 3)
    {
      digitalWrite (LEFT_PWM_PIN_FORWARD, 100);
      digitalWrite (RIGHT_PWM_PIN_FORWARD, 100);
      checkDistanceRight ();
      checkDistanceLeft ();
      checkDistanceFront ();
    }
  }
  checkDistanceRight ();
  checkDistanceLeft ();
  checkDistanceFront ();
//er ist nun parallel zur Weiterführung der Linie seitlich am Hindernis vorbeigefahren
  if ((distanceL > 3) && (distanceR > 3) && (distanceF > 3))
    {
      checkDistanceRight ();
      checkDistanceLeft ();
      checkDistanceFront ();
      //er fährt eine Kurve, bis er das Hindernis wieder mit einem Sensor erkennt
      while ((distanceL > 3) && (distanceR > 3) && (distanceF > 3))
      {
        digitalWrite (LEFT_PWM_PIN_FORWARD, 100);
        digitalWrite (RIGHT_PWM_PIN_FORWARD, 50);
        checkDistanceRight ();
        checkDistanceLeft ();
        checkDistanceFront ();
      }
  }
  //das Hindernis befindet sich vor ihm
   if (distanceF < 3)
   {
     //er dreht sich, bis das Hindernis rechts von ihm ist
     while (distanceR > 3)
     {
      digitalWrite (LEFT_PWM_PIN_FORWARD, 0);
      digitalWrite (RIGHT_PWM_PIN_FORWARD, 50);
      checkDistanceRight ();
      checkDistanceLeft ();
      checkDistanceFront ();
     }
     
   }
checkDistanceRight ();
checkDistanceLeft ();
checkDistanceFront ();
//das Hinderniss befindet sich nun rechts von ihm
if (distanceR < 3)
  {
    checkDistanceRight ();
    checkDistanceLeft ();
    checkDistanceFront ();
    readAllIRSensors;
  //er fährt solange, bis ein IR Sensor anschlägt oder das Hindernis nicht mehr rechts von ihm ist
    while ((ir_sensor_Left = 0) && (ir_sensor_HalfLeft = 0) && (ir_sensor_LeftFromMiddle = 0) && 
    (ir_sensor_MiddleLeft = 0) && (ir_sensor_MiddleRight = 0) && (ir_sensor_RightFromMiddle = 0)
    && (ir_sensor_HalfRight = 0) && (ir_sensor_Right = 0) && (distanceR < 3))
    {
      digitalWrite (LEFT_PWM_PIN_FORWARD, 100);
      digitalWrite (RIGHT_PWM_PIN_FORWARD, 100);
      checkDistanceRight ();
      checkDistanceLeft ();
      checkDistanceFront ();
      readAllIRSensors;
    };
  }

  if ((ir_sensor_Left = 1) && (ir_sensor_HalfLeft = 1) && (ir_sensor_LeftFromMiddle = 1) && 
  (ir_sensor_MiddleLeft = 1) && (ir_sensor_MiddleRight = 1) && (ir_sensor_RightFromMiddle = 1)
  && (ir_sensor_HalfRight = 1) && (ir_sensor_Right = 1))
  {
    readAllIRSensors;
    checkDistanceRight;
    while (distanceR < 3)
    {
      digitalWrite (RIGHT_PWM_PIN_FORWARD, 50);
      checkDistanceRight;
      readAllIRSensors;
    }
      
  }
    
  }

}

int LineFollowing ()
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
    ir_sensor_RightFromMiddle = digitalRead(A5);
    while (ir_sensor_RightFromMiddle == 1)
    {
      ir_sensor_RightFromMiddle = digitalRead(A5);
      analogWrite(LEFT_PWM_PIN_FORWARD, 200);
      analogWrite(RIGHT_PWM_PIN_FORWARD, 190);
    }
  }

  else if (ir_sensor_LeftFromMiddle == 1)
  {
    ir_sensor_LeftFromMiddle = digitalRead(A2);
    while (ir_sensor_LeftFromMiddle == 1)
    {
      analogWrite(LEFT_PWM_PIN_FORWARD, 190);
      analogWrite(RIGHT_PWM_PIN_FORWARD, 200);
      ir_sensor_LeftFromMiddle = digitalRead(A2);
    }
  }

  else if (ir_sensor_HalfRight == 1)
  {
    ir_sensor_HalfRight = digitalRead(8);
    while (ir_sensor_HalfRight == 1);
    {
      analogWrite(LEFT_PWM_PIN_FORWARD, 200);
      analogWrite(RIGHT_PWM_PIN_FORWARD, 180);
      ir_sensor_HalfRight = digitalRead(8);
    }
  }

  else if (ir_sensor_HalfLeft == 1)
  {
    ir_sensor_HalfLeft = digitalRead(A1);
    while (ir_sensor_HalfLeft == 1)
    {
      analogWrite(LEFT_PWM_PIN_FORWARD, 180);
      analogWrite(RIGHT_PWM_PIN_FORWARD, 200);
      ir_sensor_HalfLeft = digitalRead(A1);
    }
  }
  else if (ir_sensor_Right == 1)
  {
    ir_sensor_Right = digitalRead(A1);
    while (ir_sensor_Right == 1)
    {
      analogWrite(LEFT_PWM_PIN_FORWARD, 200);
      analogWrite(RIGHT_PWM_PIN_FORWARD, 170);
      ir_sensor_Right = digitalRead(A1);
    }
  }

  else if (ir_sensor_Left == 1)
  {
    ir_sensor_Left = digitalRead(A1);
    while (ir_sensor_Left == 1)
    {
    analogWrite(LEFT_PWM_PIN_FORWARD, 170);
    analogWrite(RIGHT_PWM_PIN_FORWARD, 200);
    ir_sensor_Left = digitalRead(A1);
    }

  }

  else if ((ir_sensor_MiddleLeft == 1) && (ir_sensor_MiddleRight == 0))
  {
    ir_sensor_MiddleLeft = digitalRead(A1);
    ir_sensor_MiddleRight = digitalRead(A1);
    while ((ir_sensor_MiddleLeft == 1) && (ir_sensor_MiddleRight == 0))
    {
      analogWrite(RIGHT_PWM_PIN_FORWARD, 200);
      analogWrite(LEFT_PWM_PIN_FORWARD, 195);
      ir_sensor_MiddleLeft = digitalRead(A1);
      ir_sensor_MiddleRight = digitalRead(A1);
    }
  }

  else if ((ir_sensor_MiddleLeft == 0) && (ir_sensor_MiddleRight == 1))
  {
    ir_sensor_MiddleLeft = digitalRead(A1);
    ir_sensor_MiddleRight = digitalRead(A1);
    while ((ir_sensor_MiddleLeft == 0) && (ir_sensor_MiddleRight == 1))
    {
      analogWrite(RIGHT_PWM_PIN_FORWARD, 195);
      analogWrite(LEFT_PWM_PIN_FORWARD, 200);
      ir_sensor_MiddleLeft = digitalRead(A1);
      ir_sensor_MiddleRight = digitalRead(A1);
    }
  } else if ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight)
    && (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0)
    && (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {
    findline();
    }
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
      delay(100);
      analogWrite(LEFT_PWM_PIN_FORWARD, 0);
      analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
      readAllIRSensors();
      if ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) && (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) && (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {
        analogWrite(LEFT_PWM_PIN_FORWARD, 100);
        analogWrite(RIGHT_PWM_PIN_FORWARD, 50);
        delay(100);
        analogWrite(LEFT_PWM_PIN_FORWARD, 0);
        analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
        readAllIRSensors();
        if ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) && (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) && (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {
          analogWrite(RIGHT_PWM_PIN_FORWARD, 100);
          analogWrite(LEFT_PWM_PIN_FORWARD, 50);
          delay(200);
          analogWrite(RIGHT_PWM_PIN_FORWARD, 0);
          analogWrite(LEFT_PWM_PIN_FORWARD, 0);
          readAllIRSensors();
          if ((ir_sensor_Right == 0) && (ir_sensor_RightFromMiddle == 0) && (ir_sensor_HalfRight) && (ir_sensor_MiddleRight == 0) && (ir_sensor_MiddleLeft == 0) && (ir_sensor_HalfLeft == 0) && (ir_sensor_LeftFromMiddle == 0) && (ir_sensor_Left == 0)) {
            analogWrite(LEFT_PWM_PIN_FORWARD, 100);
            delay(100);
            analogWrite(LEFT_PWM_PIN_FORWARD, 0);
            readAllIRSensors();
          }
        }
      }
    }
  }

}

int drive()
{
checkDistanceFront;
checkDistanceLeft;
checkDistanceRight;
readAllIRSensors();
//wenn kein Hindernis erkannt wird, folgt er der Linie wie gehabt
while (distanceF < 3)
  {
    LineFollowing;
  }
//wenn ein Hinderniss voraus ist, umgeht er dies
while (distanceF < 3)
  {
    dogdeObstacle;
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
