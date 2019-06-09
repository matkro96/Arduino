// Arduino stepper motor control code

#include <Stepper.h> // Include the header file
const int trigPin = 3;
const int echoPin = 2;
long duration;
int distance;



// change this to the number of steps on your motor




void setup() {
  Serial.begin(9600);

pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(4, OUTPUT);
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
if(distance<8)
{
  digitalWrite(4,HIGH);
  delay(100);
}

else 
digitalWrite(4, LOW);

}
