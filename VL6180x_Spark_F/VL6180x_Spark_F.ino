#include <SparkFun_VL6180X.h>
#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200); // start serial at 115200 bps
 Wire begin(); //start I2C library
 delay(100);

 if (sensor.VL6180xInit() !=0) {
  Serial.println("FAILED TO INITIALIZE");
 };

 sensor.VL6180xDefalutSettings(); // load default settings to get started
 delay(1000);


}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("Ambient Light Level (Lux) = ");
  Serial.println(sensor.getAmbientLight(Gain_1);

  Serial.print("Distance Measured (mm) = ");
  Serial.prinln(sensor.getDistance());

  delay(1000);

}
