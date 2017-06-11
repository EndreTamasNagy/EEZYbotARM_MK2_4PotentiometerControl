//Control of 4 servos through 4 potmeters
#include <Servo.h>

// create servo objects to control servos
Servo servoGrip,servoUpper,servoLower,servoRot;  

// analog pins used to connect the potentiometers
int potGrip=2;
int potUpper=3;
int potLower=4;
int potRot = 5;

// variables to read the potentiometers from the analog pins
int ctrlGrip;
int ctrlUpper;
int ctrlLower;
int ctrlRot;    

void setup() {
  // attaches the servos on digital pins to the servo objects
  servoGrip.attach(5);
  servoUpper.attach(6);
  servoRot.attach(9);  
  servoLower.attach(10);
}

void loop() {
  // reads the value of the potentiometers (output value between 0 and 1023)
  ctrlGrip=analogRead(potGrip);
  ctrlUpper=analogRead(potUpper);
  ctrlLower=analogRead(potLower);
  ctrlRot = analogRead(potRot);            
  
  // scale values to use it with the servos (output value between 0 and 180)
  ctrlGrip=map(ctrlGrip,0,1023,0,180);
  ctrlUpper=map(ctrlUpper,0,1023,0,180);
  ctrlLower=map(ctrlLower,0,1023,0,180);
  ctrlRot = map(ctrlRot, 0, 1023, 0, 180);     

  // sets the servo positions according to the scaled value
  servoGrip.write(ctrlGrip);
  servoUpper.write(ctrlUpper);
  servoLower.write(ctrlLower);
  servoRot.write(ctrlRot);                  

  // waits for the servo to get there
  delay(15);                           
}













