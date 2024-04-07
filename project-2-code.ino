#include <Servo.h>
int switchPin = 1;

int switchVal = 0;
int prevSwitchVal = 0;

Servo swingservo;

void setup() {
  pinMode(switchPin, INPUT);
  swingservo.attach(10);
  swingservo.write(20);

}

void loop() {
  switchVal = digitalRead(switchPin);

  if(switchVal != prevSwitchVal){
    if(switchVal == HIGH){
      swingservo.write(120);
    }
  }
 
 prevSwitchVal = switchVal;
}
