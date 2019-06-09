#include <AccelStepper.h>

const int trigPin = 2;
const int echoPin = 3;
long duration;
int distance=10;


#define FULLSTEP  4
#define HALFSTEP  8

#define motorPin1 8
#define motorPin2 9
#define motorPin3 10
#define motorPin4 11

#define motorPin5 4
#define motorPin6 5 
#define motorPin7 6
#define motorPin8 7

AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper2(HALFSTEP, motorPin5, motorPin7, motorPin6, motorPin8);
void setup(){
  stepper1.setMaxSpeed(800.0);
  stepper1.setAcceleration(400.0);
  stepper1.setSpeed(100);
  stepper1.moveTo(-20480000);

  stepper2.setMaxSpeed(800.0);
  stepper2.setAcceleration(400.0);
  stepper2.setSpeed(100);
  stepper2.moveTo(20480000);


Serial.begin(9600); // Starts the serial communication

}


void run()
{
stepper1.run();
stepper2.run();
}

void(* resetFunc) (void) = 0;

void loop() {




if(digitalRead(3)==HIGH)
{
 

 stepper1.stop();
 stepper2.stop();
 delay(2000);
resetFunc();
}
else{
stepper1.run();
stepper2.run();
}
}
