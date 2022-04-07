#include <Servo.h>

Servo myservo0;   // create servo objects to control each servo
Servo myservo1;
Servo myservo2;

int potpin0 = 0;  // analog pin used to connect to each potentiometer
int potpin1 = 2;
int potpin2 = 4;

int val0;         // variable to read the value from each analog pin
int val1;
int val2;

int _TOLERANCE_ = 5;

void setup() {
  // put your setup code here, to run once:

  myservo0.attach(8);   // attaches the servo on pin 8 to the servo object
  myservo1.attach(9);
  myservo2.attach(10);


}

void loop() {
  // put your main code here, to run repeatedly:

  val0 = analogRead(potpin0);         // reads the value of the potentiometer (value between 0 and 1023)
  int unbufferedVal0 = analogRead(potpin0);
  if (abs(unbufferedVal0 - val0) >= _TOLERANCE_) {
    val0 = unbufferedVal0;
  }
  val0 = map(val0, 0, 1023, 0, 180);  // scale it to use it with the servo (value betwen 0 and 180)
  myservo0.write(val0);               // sets the servo position according to the scaled value
  delay(20);                          // waits for the servo to get there

  val1 = analogRead(potpin1);
  int unbufferedVal1 = analogRead(potpin1);
  if (abs(unbufferedVal1 - val1) >= _TOLERANCE_) {
    val1 = unbufferedVal1;
  }
  val1 = map(val1, 0, 1023, 0, 180);
  myservo1.write(val1);
  delay(20);

  val2 = analogRead(potpin2);
  int unbufferedVal2 = analogRead(potpin0);
  if (abs(unbufferedVal2 - val2) >= _TOLERANCE_) {
    val2 = unbufferedVal2;
  }
  val2 = map(val2, 0, 1023, 0, 180);
  myservo2.write(val2);
  delay(20);

}
