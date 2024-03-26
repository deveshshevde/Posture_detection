#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>


VL53L0X sensor; //Must use polulu wala lirary 

//Have to use I2C multiplex!!
//--> Both sensor have same i2c addr!

void setup()
{
  Serial.begin(9600);
  Wire.begin(); //May cause issue with esp32 ka I2C!!
  sensor.setTimeout(500);
  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {Serial.println("Failed to detect and initialize sensor!"); delay(200);}
  }
  sensor.startContinuous();
}

void loop()
{
  Serial.print(sensor.readRangeContinuousMillimeters());
  if (sensor.timeoutOccurred()) { Serial.println(" TIMEOUT"); }

  
}
