# I2C_Scanner
Initialize I2C and Serial Communication:
 Use Wire.begin() to initialize the I2C bus.
 Use Serial.begin(115200) to initialize serial communication for outputting the scan results.

Scan I2C Devices:
 Use Wire.beginTransmission(address) to attempt communication with each possible I2C address.
 Use Wire.endTransmission() to check if the communication is successful.
 If the return value is 0, it indicates that the device exists and responds; if the return value is 4, it indicates that the device exists but communication failed.

Output Results:
 If a device is found, output the device's address.
 If no devices are found, output a prompt message.

Notes
Hardware Connection:
 Ensure that the SDA (data line) and SCL (clock line) of the I2C device are correctly connected to the corresponding pins on the ESP32. The default I2C pins for ESP32 are:
 SDA: GPIO 27
 SCL: GPIO 26
 If other pins are used, they need to be specified in the code.
Power Supply:
 Ensure that the power supply voltage of the I2C device matches that of the ESP32, typically 3.3V.
Pull-up Resistors:
 The I2C bus requires pull-up resistors, typically connecting a 4.7kΩ resistor to 3.3V on both the SDA and SCL lines.
Example Output
 Assuming an I2C device with address 0x20 is connected, the program output might be as follows:

**I2C Scanner

Scanning for I2C devices...
 
Scanning...
I2C device found at address 0x20  !
done**

Notes on the Code
 Initialization: The Wire.begin() function initializes the I2C bus, and Serial.begin(115200) sets up the serial communication at a baud rate of 115200.
 Scanning: The for loop iterates through all possible I2C addresses (from 1 to 127). For each address, it attempts to communicate using Wire.beginTransmission(address) and checks the result with   Wire.endTransmission().
 Output: If a device responds (error == 0), its address is printed. If there is an unknown error (error == 4), it prints an error message. If no devices are found, it prints "No I2C devices found".
 This program allows you to easily detect and confirm the addresses of I2C devices connected to the ESP32.

![图片描述](https://github.com/Maclanren/I2C_Scanner/blob/main/I2c-scan.png?raw=true)


![图片描述](https://github.com/Maclanren/I2C_Scanner/blob/main/I2c-scan%20test.png?raw=true)


