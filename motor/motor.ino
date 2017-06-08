// connect motor controller pins to Arduino digital pins
// motor two
int en = 5;
int m1 = 7;
int m2 = 6;
void setup()
{
  // set all the motor control pins to outputs
  
  pinMode(en, OUTPUT);
  
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
}
void drive()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor B
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(en, 200);
  delay(2000);
  // now change motor directions
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH); 
  delay(2000);
  // now turn off motors
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
}
void loop()
{
  drive();
  delay(1000);
}
