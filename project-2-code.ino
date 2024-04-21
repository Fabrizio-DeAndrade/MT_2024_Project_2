#include <Servo.h>

const int numSwitches = 4;
const int switchPins[numSwitches] = {7, 10, 12, 5};

const int numServos = 4;
const int servoPins[numServos] = {8, 9, 11, 6};

Servo servos[numServos];
bool switchStates[numSwitches] = {false};
bool prevSwitchStates[numSwitches] = {false};

void setup() {
  for (int i = 0; i < numServos; i++) {
    servos[i].attach(servoPins[i]);
  }

  for (int i = 0; i < numServos; i++) {
    pinMode(switchPins[i], INPUT);
  }

  for (int i = 0; i < numServos; i++) {
    servos[0].write(20); //final servo
    servos[1].write(0); //figure on right
    servos[2].write(130); //figure on left
    servos[3].write(110); //swing servo
  }

}

void loop() {
  for (int i = 0; i < numSwitches; i++) {
    switchStates[i] = digitalRead(switchPins[i]);
  }

  for (int i = 0; i < numSwitches; i++) {
    if (switchStates[i] != prevSwitchStates[i]) {
      if (switchStates[i] == HIGH) {
        activateServo(i);
      }
      prevSwitchStates[i] = switchStates[i];
    }
  }
}

void activateServo(int servoIndex) {
  switch (servoIndex) {
    case 0:
      servos[0].write(130);
      break;
    case 1:
      servos[1].write(90);
      break;
    case 2:
      servos[2].write(35);
      break;
    case 3:
      servos[3].write(85);
      break;

    default:
    break;

  }
}
