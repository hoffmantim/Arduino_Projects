#include <SoftwareSerial.h>

SoftwareSerial DroneBT(2,3); // Using pin 2 for RX and pin 3 for TX

char incoming_value = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
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
    }
  }

}
