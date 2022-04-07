#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial DroneBT(2,3); // Using pin 2 for RX and pin 3 for TX
Servo myservo;

#define servoPin 10
int soilPin = A0;

char incoming_value = 0;
int servoAngle = 0;


void setup() {
  // put your setup code here, to run once:

  pinMode(7, OUTPUT);
  pinMode(soilPin, INPUT);

  myservo.attach(servoPin);
  Serial.begin(9600);
  DroneBT.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (DroneBT.available() > 0) {
    incoming_value = DroneBT.read();
    Serial.print(incoming_value);
    Serial.print("\n");
    
    if (incoming_value == '1') {
      digitalWrite(7, HIGH);

      Serial.println("LED: ON");
    } else if (incoming_value == '0') {
      digitalWrite(7, LOW);
      Serial.println("LED: OFF");
    } else if (incoming_value == '7') {
      myservo.write(70);
      DroneBT.println(analogRead(soilPin));
      Serial.println(analogRead(soilPin));
      
      
    } else if (incoming_value == '8') {
      myservo.write(170);
      delay(500);
    }
  }

}
