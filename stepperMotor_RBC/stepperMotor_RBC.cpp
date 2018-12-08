#include "Arduino.h"
#include "stepperMotor_RBC.h"

stepperMotor::stepperMotor(int inone, int intwo, int inthree, int infore, int timedel)
{
//The Setup
  pinMode(inone, OUTPUT);
  pinMode(intwo, OUTPUT);
  pinMode(inthree, OUTPUT);
  pinMode(infore, OUTPUT);
  _inone = inone
  _intwo = intwo
  _inthree = inthree
  _infore = infore 
  _timedel = timedel
  
}

/*
   This function lets the step motor rotate in 512 steps. Because this 4 OUTPUT combinations
   make 4 times 11.25 degree of the rotor which is geared with a ratio of 64
   so 4*11.25 / 64 =~ 1/512
*/
void stepperMotor::waveDrive(int steps)
{
  for (int i = 0; i < steps; i++ ) {
    //1000 1
    digitalWrite(inone,   1);
    digitalWrite(intwo,   0);
    digitalWrite(inthree, 0);
    digitalWrite(infore,  0);
    delay(timedel);
    //0100 2
    digitalWrite(inone,   0);
    digitalWrite(intwo,   1);
    digitalWrite(inthree, 0);
    digitalWrite(infore,  0);
    delay(timedel);
    //0010 3
    digitalWrite(inone,   0);
    digitalWrite(intwo,   0);
    digitalWrite(inthree, 1);
    digitalWrite(infore,  0);
    delay(timedel);
    //0001 4
    digitalWrite(inone,   0);
    digitalWrite(intwo,   0);
    digitalWrite(inthree, 0);
    digitalWrite(infore,  1);
    delay(timedel);
  }
}


/*
   This function lets the step motor rotate in 512 steps. Because this 4 OUTPUT combinations
   make 4 times 11.25 degree of the rotor which is geared with a ratio of 64
   so 4*11.25 / 64 =~ 1/512 same steps but doubled the torque!
*/
void stepperMotor::fullStep(int steps) {
  for (int i = 0; i < steps; i++ ) {
    //1100 1
    digitalWrite(inone,   1);
    digitalWrite(intwo,   1);
    digitalWrite(inthree, 0);
    digitalWrite(infore,  0);
    delay(timedel);
    //0110 2
    digitalWrite(inone,   0);
    digitalWrite(intwo,   1);
    digitalWrite(inthree, 1);
    digitalWrite(infore,  0);
    delay(timedel);
    //0011 3
    digitalWrite(inone,   0);
    digitalWrite(intwo,   0);
    digitalWrite(inthree, 1);
    digitalWrite(infore,  1);
    delay(timedel);
    //1001 4
    digitalWrite(inone,   1);
    digitalWrite(intwo,   0);
    digitalWrite(inthree, 0);
    digitalWrite(infore,  1);
    delay(timedel);
  }
}

/*
   This programm lets the step motor rotate in 512 steps. Because this 4 OUTPUT combinations
   make 4 times 11.25 degree of the rotor which is geared with a ratio of 64
   so 4*11.25 / 64 =~ 1/512 same steps but doubled the torque!
*/
void stepperMotor::halfStep(int steps) {
  for (int i = 0; i < steps; i++ ) {
    //1000 1
    digitalWrite(inone,   1);
    digitalWrite(intwo,   0);
    digitalWrite(inthree, 0);
    digitalWrite(infore,  0);
    delay(timedel);
    //1100 2
    digitalWrite(inone,   1);
    digitalWrite(intwo,   1);
    digitalWrite(inthree, 0);
    digitalWrite(infore,  0);
    delay(timedel);
    //0100 3
    digitalWrite(inone,   0);
    digitalWrite(intwo,   1);
    digitalWrite(inthree, 0);
    digitalWrite(infore,  0);
    delay(timedel);
    //0110 4
    digitalWrite(inone,   0);
    digitalWrite(intwo,   1);
    digitalWrite(inthree, 1);
    digitalWrite(infore,  0);
    delay(timedel);
    //0010 5
    digitalWrite(inone,   0);
    digitalWrite(intwo,   0);
    digitalWrite(inthree, 1);
    digitalWrite(infore,  0);
    delay(timedel);
    //0011 6
    digitalWrite(inone,   0);
    digitalWrite(intwo,   0);
    digitalWrite(inthree, 1);
    digitalWrite(infore,  1);
    delay(timedel);
    //0001 7
    digitalWrite(inone,   0);
    digitalWrite(intwo,   0);
    digitalWrite(inthree, 0);
    digitalWrite(infore,  1);
    delay(timedel);
    //1001 8
    digitalWrite(inone,   1);
    digitalWrite(intwo,   0);
    digitalWrite(inthree, 0);
    digitalWrite(infore,  1);
    delay(timedel);
  }
}

void stepperMotor::clearInputs() {
  digitalWrite(inone, 0);
  digitalWrite(intwo, 0);
  digitalWrite(inthree, 0);
  digitalWrite(infore, 0);
}