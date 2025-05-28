#include <Wire.h>
void Get_I2C_ADD();
void setup()
{
  Wire.begin(27,26);            // ESP32 SDA=27 SCL=26
  Serial.begin(115200);
  while (!Serial);             // Leonardo: wait for serial monitor
  Serial.println("I2C Scanner\n");
  Serial.println("Scanning for I2C devices...\n");
  delay(100);       // delay100ms,and then scan I2C address
  Get_I2C_ADD();    // scan only once
}
void Get_I2C_ADD()
{
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127; address++ ) 
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
      nDevices++;
    }
    else if (error==4) 
    {
      Serial.print("Unknown error at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");
  delay(500);           // wait 5 seconds for next scan
}
void loop()
{
     //Continuous scanning will write Get_I2C_ADD(); into the main loop.
}
