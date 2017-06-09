#define LCD_RS         7 //  4. RS  - Register Select - 0=Command / 1=Character  Arduino Pin as defined
                         //  5. RW  - Read/Write - 0=Write or 1=Read             GND
#define LCD_ENABLE     3 //  6. E   - Enable - Enable data transmit              Arduino Pin as defined
                         //  7. DB0 - Data Bit 0                                 N/A
                         //  8. DB1 - Data Bit 1                                 N/A
                         //  9. DB2 - Data Bit 2                                 N/A
                         // 10. DB3 - Data Bit 3                                 N/A
#define LCD_DB4        4 // 11. DB4 - Data Bit 4 - used in 4 bit operation       Arduino Pin as defined
#define LCD_DB5        5 // 12. DB5 - Data Bit 5 - used in 4 bit operation       Arduino Pin as defined
#define LCD_DB6        13 // 13. DB6 - Data Bit 6 - used in 4 bit operation       Arduino Pin as defined
#define LCD_DB7        2 // 14. DB7 - Data Bit 7 - used in 4 bit operation       Arduino Pin as defined
#define LCD_Backlight 10 // 15. BL1 - Backlight +                                Emitter of 2N3904, Collector to VCC, Base to D10 via 10K resistor
                         // 16. BL2 - Backlight -                                GND
#include "NewPing.h"// Imports the NewPing Library.
#include <LiquidCrystal.h>
int ledPin =(12);
int trigPin = (10); // Add the Trig pin on pin 10.
int echoPin = (9); // Add the ECHO pin on pin 9.
int duration, distance; // Add types 'duration' and 'distance'.
// connect motor controller pins to Arduino digital pins
// motor two
int m1 = 8;
int m2 = 6;
//BUZZER
int buz = 11;
LiquidCrystal lcd(LCD_RS, LCD_ENABLE, LCD_DB4, LCD_DB5, LCD_DB6, LCD_DB7);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Hello World!");
  pinMode(LCD_Backlight, OUTPUT); 
  analogWrite(LCD_Backlight, 128); // Set the brightness of the backlight
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

void driveSlow()
{
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  delay(500);
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  delay(500);
}

void stopDrive() {
  // turn off motor
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW); 
}

void loop() {
  digitalWrite (trigPin, HIGH);
  digitalWrite (trigPin, LOW);
  digitalWrite(buz, LOW);
  digitalWrite (ledPin, LOW); // Here, LOW means off and HIGH means on.
  
  duration=pulseIn(echoPin,HIGH);
  distance=(duration/2)/29.1;
  
  if(distance <=30 && distance > 15) { // If the sensor detects an obstacle less than 30 cm in distance, the LED will start to blink.
    driveSlow();
    lcd.clear();
    lcd.print("Medium Position: ");
    lcd.setCursor(0,1);
    lcd.print(distance);
    tone(buz, 1000);
    delay(500);
    noTone(buz);
    delay(500);
    digitalWrite (ledPin, HIGH);
    delay(1000);
    digitalWrite (ledPin, LOW);
    delay(1000);
  }

  if (distance <=15) {
    stopDrive();
    lcd.clear();
    lcd.print("Less Position: ");
    lcd.setCursor(0,1);
    lcd.print(distance);
    tone(buz, 1000);
    delay(300);
    noTone(buz);
    delay(300);
    digitalWrite (ledPin, HIGH);
    delay(200);
    digitalWrite (ledPin, LOW);
    delay(200);
  }
  
  if (distance >30) {// If no obstacle is there within 30 cm, the Led should turn off.
    drive();
    lcd.clear();
    lcd.print("Less Position: ");
    lcd.setCursor(0,1);
    lcd.print(distance);
    digitalWrite (ledPin, LOW);
  }
}
