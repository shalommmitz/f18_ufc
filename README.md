# A Low-cost UFC F/A-18 Panel

## Background

As part of a project in Ofek, a school for gifted Children in Jerusalem, we are building an F18 UFC pannel. The motivation is to learn the integration of embeded controls to a PC software and to have fun !

## Resources used

   1. See the file bill_of_materials.xlsx for parts used.
   2. Switches: list of pins used in Arduino
   3. Switches: Arduino project

## ESP8266 as 10-alph-numeric display controller

   It is important to turn off the "LiveSignalRts" check box in the DCS-BIOS Bridge
      
   This is because the "RTS" signal is used as "reset" in the ESP2866

   See esp8266_10alpha_display.ino for the Arduino code

### Connections:

<br>


<br>

|ESP8266|Display name|Display pin #|
| ----- |------------|-------------|
|  5V | | |
|  5V |BS1 | |
|  G | |  |
|  D1 | | |
|  D2 | | |

### Display Info

  - Resolution: 128*32
  - Color: green light
  - Driver: SSD1307
  - Grayscale: monochrome
  - Product structure: COG+FPC
  - Connection method: welding
  - Driving voltage: 12V
  - Interface: 6800/8080/SPI/I2C 

### Refrences

  - https://diyi0t.com/i2c-tutorial-for-arduino-and-esp8266
  - https://lcddisplay.co/wp-content/uploads/2023/02/SSD1307.pdf
  - https://www.displayfuture.com/Display/datasheet/controller/SSD1307.pdf


## ESP8266 as 4-alph-numeric display controller

   It is important to turn off the "LiveSignalRts" check box in the DCS-BIOS Bridge
      
   This is because the "RTS" signal is used as "reset" in the ESP2866

   See esp8266_4alpha_display.ino for the Arduino code

### Connections:

<br>

| I2C |ESP8266| 4 Disp|
| ----| ----- |-------|
| Vcc |  5V | 2x +|
| Gnd |  G | -|
| SCL |  D1 |C |
| SDA |  D2 |D |

### ESP8266 and Display Refernces

  - https://diyi0t.com/i2c-tutorial-for-arduino-and-esp8266

  - https://www.digikey.com/en/maker/tutorials/2022/an-introduction-to-14-segment-led-displays-with-the-ht16k33-driver

