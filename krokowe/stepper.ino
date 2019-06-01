// Arduino stepper motor control code

#include <Stepper.h> // Include the header file
const int trigPin = 2;
const int echoPin = 3;
// defines variables
long duration;
int distance;



// change this to the number of steps on your motor
#define STEPS 32

// create an instance of the stepper class using the steps and pins
Stepper stepper(STEPS, 8, 10, 9, 11);
 Stepper stepper1(STEPS, 4, 6, 5, 7);

int val =2048;

void setup() {
  Serial.begin(9600);
stepper.setSpeed(200);
stepper1.setSpeed(200);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if(distance>8)
{
    stepper1.step(2);
        stepper.step(2);}


  
 

}
