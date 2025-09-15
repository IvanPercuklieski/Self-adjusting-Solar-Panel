#include <Servo.h>

const int light1Pin = A0;
const int light2Pin = A1;
const int solarPin = A2;
const int servoPin = 9;

int angle = 90;

int light1Reading;
int light2Reading;
int difference;

int margin = 50;

int solarReading;
float solarVoltage;

Servo servo1;

void setup() {
  servo1.attach(servoPin);
  servo1.write(angle);
  Serial.begin(9600); 
}

void loop() {
  light1Reading = analogRead(light1Pin);
  light2Reading = analogRead(light2Pin);

  difference = light2Reading - light1Reading;

  if(difference > margin){
    if(angle<176){
      angle = angle + 5;
    }
  }
  else if(difference < (-1*margin)){
    if(angle>4){
      angle = angle - 5;
    }
  }
  else{ 
  }

  servo1.write(angle);

  solarReading = analogRead(solarPin);
  solarVoltage = solarReading * 5.0 / 1023 ;

  Serial.print("Sensor 1 reading: ");
  Serial.print(light1Reading);
  Serial.print(" Sensor 2 reading: ");
  Serial.print(light2Reading);
  Serial.print(" Solar panel voltage: ");
  Serial.println(solarVoltage);
}
