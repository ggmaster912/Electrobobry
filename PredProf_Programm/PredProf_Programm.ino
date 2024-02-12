#include <Servo.h>

#define VALUE 50
#define SPEED 1

Servo ser;

int angle = 0;

void setup() {
  ser.attach(9);
  Serial.begin(9600);
}

void loop() {
  int first_sensor = analogRead(A0);
  int second_sensor = analogRead(A1);
  int error = first_sensor - second_sensor;
  
  if (error > VALUE) {
    angle -= SPEED;
  }
  else if (error < -VALUE) {
    angle += SPEED;
  }
  if (angle < 0) {
    angle = 0;
  }
  if (angle > 180) {
    angle = 180;
  }
  
  ser.write(angle);

  Serial.print(first_sensor);
  Serial.print(" ");
  Serial.print(second_sensor);
  Serial.print(" ");
  Serial.print(error);
  Serial.print(" ");
  Serial.println(angle);
}
