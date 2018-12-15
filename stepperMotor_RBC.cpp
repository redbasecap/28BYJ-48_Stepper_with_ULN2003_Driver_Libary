#include "Arduino.h"
#include "stepperMotor_RBC.h"

StepperMotor::StepperMotor(int inone, int intwo, int inthree, int infore, int timedel)
{
//The Setup
  pinMode(inone, OUTPUT);
  pinMode(intwo, OUTPUT);
  pinMode(inthree, OUTPUT);
  pinMode(infore, OUTPUT);
  _inone = inone;
  _intwo = intwo;
  _inthree = inthree;
  _infore = infore;
  _timedel = timedel;

}

/*
   This function lets the step motor rotate in 512 steps. Because this 4 OUTPUT combinations
   make 4 times 11.25 degree of the rotor which is geared with a ratio of 64
   so 4*11.25 / 64 =~ 1/512
*/
void StepperMotor::waveDrive(int steps)
{
  for (int i = 0; i < steps; i++ ) {
    //1000 1
    digitalWrite(_inone,   1);
    digitalWrite(_intwo,   0);
    digitalWrite(_inthree, 0);
    digitalWrite(_infore,  0);
    delay(_timedel);
    //0100 2
    digitalWrite(_inone,   0);
    digitalWrite(_intwo,   1);
    digitalWrite(_inthree, 0);
    digitalWrite(_infore,  0);
    delay(_timedel);
    //0010 3
    digitalWrite(_inone,   0);
    digitalWrite(_intwo,   0);
    digitalWrite(_inthree, 1);
    digitalWrite(_infore,  0);
    delay(_timedel);
    //0001 4
    digitalWrite(_inone,   0);
    digitalWrite(_intwo,   0);
    digitalWrite(_inthree, 0);
    digitalWrite(_infore,  1);
    delay(_timedel);
  }
}


/*
   This function lets the step motor rotate in 512 steps. Because this 4 OUTPUT combinations
   make 4 times 11.25 degree of the rotor which is geared with a ratio of 64
   so 4*11.25 / 64 =~ 1/512 same steps but doubled the torque!
*/
void StepperMotor::fullStep(int steps) {
  for (int i = 0; i < steps; i++ ) {
    //1100 1
    digitalWrite(_inone,   1);
    digitalWrite(_intwo,   1);
    digitalWrite(_inthree, 0);
    digitalWrite(_infore,  0);
    delay(_timedel);
    //0110 2
    digitalWrite(_inone,   0);
    digitalWrite(_intwo,   1);
    digitalWrite(_inthree, 1);
    digitalWrite(_infore,  0);
    delay(_timedel);
    //0011 3
    digitalWrite(_inone,   0);
    digitalWrite(_intwo,   0);
    digitalWrite(_inthree, 1);
    digitalWrite(_infore,  1);
    delay(_timedel);
    //1001 4
    digitalWrite(_inone,   1);
    digitalWrite(_intwo,   0);
    digitalWrite(_inthree, 0);
    digitalWrite(_infore,  1);
    delay(_timedel);
  }
}

/*
   This programm lets the step motor rotate in 512 steps. Because this 4 OUTPUT combinations
   make 4 times 11.25 degree of the rotor which is geared with a ratio of 64
   so 4*11.25 / 64 =~ 1/512 same steps but doubled the torque!
*/
void StepperMotor::halfStep(int steps) {
  for (int i = 0; i < steps; i++ ) {
    //1000 1
    digitalWrite(_inone,   1);
    digitalWrite(_intwo,   0);
    digitalWrite(_inthree, 0);
    digitalWrite(_infore,  0);
    delay(_timedel);
    //1100 2
    digitalWrite(_inone,   1);
    digitalWrite(_intwo,   1);
    digitalWrite(_inthree, 0);
    digitalWrite(_infore,  0);
    delay(_timedel);
    //0100 3
    digitalWrite(_inone,   0);
    digitalWrite(_intwo,   1);
    digitalWrite(_inthree, 0);
    digitalWrite(_infore,  0);
    delay(_timedel);
    //0110 4
    digitalWrite(_inone,   0);
    digitalWrite(_intwo,   1);
    digitalWrite(_inthree, 1);
    digitalWrite(_infore,  0);
    delay(_timedel);
    //0010 5
    digitalWrite(_inone,   0);
    digitalWrite(_intwo,   0);
    digitalWrite(_inthree, 1);
    digitalWrite(_infore,  0);
    delay(_timedel);
    //0011 6
    digitalWrite(_inone,   0);
    digitalWrite(_intwo,   0);
    digitalWrite(_inthree, 1);
    digitalWrite(_infore,  1);
    delay(_timedel);
    //0001 7
    digitalWrite(_inone,   0);
    digitalWrite(_intwo,   0);
    digitalWrite(_inthree, 0);
    digitalWrite(_infore,  1);
    delay(_timedel);
    //1001 8
    digitalWrite(_inone,   1);
    digitalWrite(_intwo,   0);
    digitalWrite(_inthree, 0);
    digitalWrite(_infore,  1);
    delay(_timedel);
  }
}

void StepperMotor::clearInputs() {
  digitalWrite(_inone, 0);
  digitalWrite(_intwo, 0);
  digitalWrite(_inthree, 0);
  digitalWrite(_infore, 0);
}
