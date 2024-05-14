# A Low-cost UFC F/A-18 Panel

## Background

As part of a project in Ofek, a school for gifted Children in Jerusalem, we are building an F18 UFC pannel. The motivation is to learn the integration of embeded controls to a PC software and to have fun !

## Resources used

   1. See the file bill_of_materials.xlsx for parts used.
   2. Switches: list of pins used in Arduino
   3. Switches: Arduino project

## ESP8266 as 4-alph-numeric display controller

   It is important to turn off the "LiveSignalRts" check box in the DCS-BIOS Bridge
      
   This is because the "RTS" signal is used as "reset" in the ESP2866

   See esp8266_4alpha_display.ino for the Arduino code

### Connections:

<br>

|ESP8266|Display|
| ----- |-------|
|  5V | 2x +|
|  G | -|
|  D1 |C |
|  D2 |D |

### ESP8266 and Display Refernces

  - https://diyi0t.com/i2c-tutorial-for-arduino-and-esp8266

  - https://www.digikey.com/en/maker/tutorials/2022/an-introduction-to-14-segment-led-displays-with-the-ht16k33-driver

