<<<<<<< HEAD
/*
  stepperMotor_RBC - Library for driving the 28BYJ-48 stepper with ULN2003 driver board.
  Created by RedBaseCap, 19. Nov, 2018.
  GPL-3.0 by redbasecap/28BYJ-48_Stepper_with_ULN2003_Driver_Libary
  */
  
#ifndef stepperMotor_RBC
#define stepperMotor_RBC
#include "Arduino.h"

class stepperMotor_RBC
{
	public:
	void waveDrive(int);
	void fullStep(int);
	void halfStep(int);
	void clearInputs();
	private:
	int _inone, _intwo, _inthree, _infore, _timedel;

}



>>>>>>> 5da09e515b0cca35172d595649f8b5d66b146518
#endif