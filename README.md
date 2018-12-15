# Stepper_28BYJ-48_with_ULN2003_Driver_Libary

Welcome to my little StepperLibary

How to use it: 

1) Get the libary 
- Clone it in to your libaries folder which is in /Documents/Arduino/Sketches/libaries
or 
- Just download, exctract it and put it into it manually
      
2) Include the libary
- #include <stepperMotor_RBC.h>
or
- Choose Sketch in the toolbar -> Include libary -> Stepper_28BYJ-48_with_ULN2003_Driver_Libary  //this is the way I recommend

3)  First you have to give the pins that you are using to the class in the libary.

    ////////CODEEXAMPLE///////
    
    #include <stepperMotor_RBC.h>

    StepperMotor StepperMotor(2,3,4,5,20); //Pin for IN1, IN2, IN3, IN4, Timedelay //the TIMEDELAY have to be >5 ms

    void setup() {
    }

    void loop() {
    }
    
    ////////CODEEXAMPLE///////
    
4) The just use the 3 different modes 
StepperMotor...
  -1) .waveDrive(100);
  -2) .fullStep(100);
  -3) .halfStep(100);
  -4) .clearInputs();
