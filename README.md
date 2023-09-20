# Repo for testing of Analog Input on an ESP32
### 

## Contents
- [Notes](#notes)
- [Installation Instructions](#installation-instructions)
- [Arduino Nano](#ARDUINO-NANO)
- [Esp32-devkitC](#esp32-devkitC-v4)
- [WEMOS LOLIN32 with OLED Board](#WEMOS-LOLIN32)
- [WeMos d1 Mini Pro](#d1_Mini_Pro)
- [Heltec WiFi LORA 32 V1](#Heltec-WiFi-LORA-32-V1)
- [Heltec WiFi LORA 32 V2](#Heltec-WiFi-LORA-32-V2)
- [Esp32 with battery holder and OLED](#TTGOBatteryOLED)
- [Adafruit ADS1115](#Adafruit-ADS1115)
- [BME280/BMP280 Pressure/Temperature/Humidity sensor](#BME280/BMP280)
- [MPRLS Pressure sensor](#MPRLS)
- [LSM303DLHC e-Compass 3 Axis Accelerometer + 3 Axis Magnetometer Module Sensor](#LSM303DLHC) 

## Notes
- We are using a esp32-devkitC v4 with a Pot connected to GPIO34

## Installation Instructions
- Use VS Code and PlatformIO

## ARDUINO NANO
Board name ARDUINO NANO atmega328. For PlatformIO use "nanoatmega328" for the board type.<br/>

![Pin Functions](docs/arduino-nano-pinout.png)
## esp32-devkitC-v4
Board name esp32-devkitC v4. For PlatformIO use "esp32dev" for the board type.<br/>
Purchased several of these. They have a connection for an external antenna.<br/>

![Pin Functions](docs/ESP32-DEV-KIT-DevKitC-v4-pinout-mischianti.png)
![Pin Functions](docs/esp32-devkitC-v4-pinout.png)

## WEMOS LOLIN32
Board name WEMOS LOLIN32. For PlatformIO use "lolin32" for the board type.<br/>
<ul>
    <li>OLED Connections:</li>
        <li>CLOCK 4</li>
        <li>DATA 5</li>
        <li>RESET 16</li>
</ul>

![Pin Functions](docs/WemosESP32OLEDTop.jpg)
![Pin Functions](docs/WemosESP32OLEDBottom.jpg)
![Pin Functions](docs/WemosESP32OLEDPinout.jpg)
## - #WEMOS LOLIN32V100
Board name WeMos LOLIN32 V1.0.0. For PlatformIO use "" for the board type.<br/>
![Pin Functions](docs/ESP32WeMosLOLIN32Top.jpg)
![Pin Functions](docs/ESP32WeMosLOLIN32Bottom.jpg)
![Pin Functions](docs/ESP32WeMosLOLIN32Pinout.png)
## - #d1_Mini_Pro
Board name WeMos d1 Mini Pro. For PlatformIO use "" for the board type.<br/>
![Pin Functions](docs/wemos_d1_mini_pro_pinout.png)
## Heltec WiFi LORA 32 V1
Heltec WiFi LORA 32 V1 – For PlatformIO use "heltec_wifi_lora_32" for the board type.<br/>
ESP32 with OLED and LORA Board<br/>
To program you need to hold button labeled PRG near coil antenna.<br/>
<ul>
    <li>I2C Connections:</li>
        <li>SCL 22</li>
        <li>SDA 21</li>
    <li>OLED Connections:</li>
        <li>CLOCK 15</li>
        <li>DATA 4</li>
        <li>RESET 16</li>
</ul>

![Pin Functions](docs/WiFi-LORA-32-pinout-Diagram.png)
## Heltec WiFi LORA 32 V2
Heltec WiFi LORA 32 V2 – For PlatformIO use "heltec_wifi_lora_32_V2" for the board type.<br/>
ESP32 with OLED and LORA Board<br/>
To program you need to hold button labeled PRG near coil antenna.<br/>
I have unresolved issues using a second I2C device with the OLED<br/>
<ul>
    <li>I2C Connections:</li>
        <li>SCL 22</li>
        <li>SDA 21</li>
    <li>OLED Connections:</li>
        <li>CLOCK 15</li>
        <li>DATA 4</li>
        <li>RESET 16</li>
</ul>

![Pin Functions](docs/WIFI_LoRa_32_V2PinDiagram.png)

## TTGOBatteryOLED
TTGO ESP32 with builtin battery holder and OLED – For PlatformIO use "TTGOBatteryOLED" for the board type.<br/>
<ul>
    <li>OLED Connections:</li>
        <li>CLOCK 4</li>
        <li>DATA 5</li>
        <li>RESET NULL</li>
</ul><br/>

![Pin Functions](docs/ESP32OledBatteryHolder.jpg)<br/>
![Pin Functions](docs/ESP32OledBatteryHolderPinout.jpg)<br/>

## Adafruit ADS1115
I2C address is 0x48<br/>
Supply Range: 2.0V to 5.5V DC<br/>
The ADS1115 provides 16-bit ADC precision at 860 samples/second over I2C. The chip can be configured as 4 single-ended input channels, or two differential channels. As a nice bonus, it even includes a programmable gain amplifier, up to x16, to help boost up smaller single/differential signals to the full range. <br/>
![Pin Functions](docs/AdafruitADS1015ADS1115PinDiagram.jpg)<br/>
Go to [Adafruit](https://www.adafruit.com/product/1085) for more information.<br/>

## BME280/BMP280
I2C address is 0x76 or 0x77 if you cut the trace between the left two pads and add a jumper to the right two pads.<br/>
Supply Range: 1.8V to 5V DC<br/>
The BME280 has Pressure, Temperature, and Humidity. The BMP only has Pressure and Temperature.<br/>
![Pin Functions](docs/BMP280.jpg)<br/>
Go to [Adafruit](https://learn.adafruit.com/adafruit-bme280-humidity-barometric-pressure-temperature-sensor-breakout) for more information.<br/>

## MPRLS
I2C address is 0x18 and cannot be changed.<br/>
Supply Range: 2.0V to 5.5V DC<br/>
The MPRLS has Pressure sensing of 0-25 PSI with a push on a tube connection.<br/>
![Pin Functions](docs/MPRLS3965-00.jpg)<br/>
Go to [Adafruit](https://www.adafruit.com/products/3965) or [Sparkfun](https://www.sparkfun.com/products/16476) for more information.<br/>

## LSM303DLHC
I2C address is 0x19 AND 0x1E and cannot be changed.<br/>
Supply Range: 2.0V to 5.5V DC<br/>
The LSM303DLHC is a Triple-axis Accelerometer+Magnetometer (Compass) Board.<br/>
![Pin Functions](docs/LSM303DLHCe-Compass3AxisAccelerometerAnd3AxisMagnetometerModule.jpg)![Pin Functions](docs/LSM303DLHCe-Compass3AxisAccelerometerAnd3AxisMagnetometerModule61VO3bK8u+L._AC_SX679_.jpg) <br/>
This board is a knock off and is completely untested.<br/>
Go to [Adafruit](https://www.adafruit.com/product/1120) for more information. New information is [LSM303 Accelerometer + Compass Breakout.](https://learn.adafruit.com/lsm303-accelerometer-slash-compass-breakout/coding)<br/>