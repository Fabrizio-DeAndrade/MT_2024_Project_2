#include <Servo.h>

const int numSwitches = 4;                               //number of switches 
const int switchPins[numSwitches] = {7, 10, 12, 5};

const int numServos = 4;                                 //number of servos
const int servoPins[numServos] = {8, 9, 11, 6};

Servo servos[numServos];
bool switchStates[numSwitches] = {false};
bool prevSwitchStates[numSwitches] = {false};

void setup() {
  for (int i = 0; i < numServos; i++) {         
    servos[i].attach(servoPins[i]);                 //attach servos to pins
  }

  for (int i = 0; i < numServos; i++) {
    pinMode(switchPins[i], INPUT);                  //sets pin mode
  }

  for (int i = 0; i < numServos; i++) {
    servos[0].write(20); //final servo starts at 20 degrees
    servos[1].write(0); //figure on right starts at 0 degrees
    servos[2].write(130); //figure on left starts at 130 degrees
    servos[3].write(110); //swing servo starts at 110 degrees
  }

}

void loop() {
  for (int i = 0; i < numSwitches; i++) {
    switchStates[i] = digitalRead(switchPins[i]);      //read switch state
  }

  for (int i = 0; i < numSwitches; i++) {
    if (switchStates[i] != prevSwitchStates[i]) {
      if (switchStates[i] == HIGH) {                   //switch is activated
        activateServo(i);                              //run function for activating servos
      }
      prevSwitchStates[i] = switchStates[i];          
    }
  }
}

void activateServo(int servoIndex) {
  switch (servoIndex) {
    case 0:
      servos[0].write(130);                //when corresponding switch is activated, move servo 0 to 130 degrees
      break;
    case 1:
      servos[1].write(90);                 //when corresponding switch is activated, move servo 1 to 90 degrees
      break;
    case 2:
      servos[2].write(35);                 //when corresponding switch is activated, move servo 2 to 35 degrees
      break;
    case 3:
      servos[3].write(85);                 //when corresponding switch is activated, move servo 3 to 85 degrees
      break;

    default:
    break;

  }
}
