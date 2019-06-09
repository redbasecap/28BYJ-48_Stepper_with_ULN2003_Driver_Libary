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
    
    //////// END CODEEXAMPLE///////
    
4) Use on off the 3 different modes 
Take a look at the DriveMethod.png (Source: https://www.youtube.com/watch?v=B86nqDRskVU by Bret Stateham) 
StepperMotor... 
  -1) .waveDrive(100);
  
	//Only a single coil is controlled per time.
	//Low torque and precision but very easy to understand. 512 Steps/360 Degrees
	
  -2) .fullStep(100);
  
	//Two Coils active at a time
	//Maximum Torque, Medium precision, 512 Steps/360 Degrees
	
  -3) .halfStep(100);
  
	//One or Two coils active at a time
	//Medium Torque, Smallest step angle, 1024 Steps per 360 Degrees
	
  -4) .clearInputs();
  
	//Put all Digital Outputs to 0
