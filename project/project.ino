#include "NewPing.h"// Imports the NewPing Library.
int ledPin =(13); // Add the onboard LED on pin 13.
int trigPin = (10); // Add the Trig pin on pin 10.
int echoPin = (9); // Add the ECHO pin on pin 9.
int duration, distance; // Add types 'duration' and 'distance'.
// connect motor controller pins to Arduino digital pins
// motor two
int m1 = 7;
int m2 = 6;
//BUZZER
int buz = 11;

void setup() {
  pinMode (ledPin, OUTPUT); // The LED must be controlled by Arduino, it means it is an output type.
  pinMode (trigPin, OUTPUT);// Same as above, the TRIG pin will send the ultrasonic wave.
  pinMode (echoPin, INPUT); // The ECHO pin will recieve the rebounded wave, so it must be an input type.
  // set the motor control pins to outputs
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  //Buzzer
  pinMode (buz, OUTPUT);
}

void drive()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor B
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
}

void stopDrive() {
  // turn off motor
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW); 
}

void loop() {
  digitalWrite (ledPin, LOW); // Here, LOW means off and HIGH means on.
  //tone(buz, 1000);
  delay(1000);
  noTone(buz);
  delay(1000);
  digitalWrite (trigPin, HIGH);
  digitalWrite (trigPin, LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=(duration/2)/29.1;

  if(distance <=30) { // If the sensor detects an obstacle less than 30 cm in distance, the LED will start to blink.
    digitalWrite (ledPin, HIGH);
    //tone(buz, 1000);
    
    delay(1000);
    noTone(buz);
  delay(1000);
    stopDrive();
  }
  if(distance >=30) {// If no obstacle is there within 30 cm, the Led should turn off.
    digitalWrite (ledPin, LOW);
    //tone(buz, 1000);
    delay(1000);
    noTone(buz);
  delay(1000);
    drive();
  }
}
