#include <Servo.h>
int switchPin = 1;

int switchVal = 0;
int prevSwitchVal = 0;
float servoSpeed = .5; 
float servoAngle = 0; 

Servo swingservo;  //this will be the servo for Spider-Man swinging

void setup() {
  pinMode(switchPin, INPUT);
  swingservo.attach(10);
  swingservo.write(servoAngle);

}

void loop() {
  switchVal = digitalRead(switchPin);

  if(switchVal != prevSwitchVal){
    if(switchVal == HIGH){
      if(servoAngle < 180)) { 
        servoAngle += servoSpeed; 
      }
    }else { 
      swingservo.write
  }
 
 prevSwitchVal = switchVal;
}
//changes added to change servo speed
