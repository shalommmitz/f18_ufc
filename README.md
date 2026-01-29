# A Low-cost UFC F/A-18 Panel

## Background

As part of a project in Ofek, a school for gifted Children in Jerusalem, we are building an F18 UFC pannel. The motivation is to learn the integration of embeded controls to a PC software and to have fun !

## Resources used

   1. See the file bill_of_materials.xlsx for parts used.
   2. The ESP8622 controller is used to interface the hardware and the PC
   3. The ESP8622 is used as Arduino controller, using Arduino scketshes
   4. The main simulation sw used is DCS (Digital Combat Simulator)
   5. We use the DCS-Bios to bridge the various ESP8266 controllers to the SCS sw
   
      The basic "chain" is:
      
      SCS-main-executable  -- Lua script -- bridge sw -- serial com -- ESP8266 -- hardware
      
   6. Components of the SCS-Bios used:
   
      - A LUA script, that is put in the "plug-ins" folder of DCS and send/receives events from the main sw
      - The Windows executable "DCS-BIOS Bridge", which bridges the events sourced from the LUA script to the ESP2866 controllers, through USB-simulated serial ports.
      - The firmware, that is programmed into the ESP8266 controllers, contains a library called "dcs-bios" that create/consume events.
      
   6. Displays used:
   
      - 5 x 4 characters displays
      - 2 x 2 characters displays
      - 1 x 10 characters display
      
## Installing the Development Environment       

1. Install the Arduino IDE
2. Install ESP8266 Board add-on in Arduino IDE open preferences

    2.1 In your Arduino IDE, go to File> Preferences
    Enter http://arduino.esp8266.com/stable/package_esp8266com_index.json into the Additional Boards Manager  URLs field
    Click "Ok"

    2.2 Open the Boards Manager. Go to Tools > Board > Boards Manager
    Select "esp8266" and "Generic board"

3. Copy the files under "arduino_libs" (which contains the various Arduino libs used here) to the 
   Arduino IDE LIBs location. In the Ofek computers, do:

   xcopy /s/e arduino_libs  "D:\user data\Documents\Arduino\libraries"


4. Configure the port
   At the top left of the sketch, choose "Generic ESP8266" and the com port you saw on the device manager (normally 4 to 8)


## Information sepcific to the displays

   The below is relavant to the 3 types of displays:
   
   - All the displayes are controlled through I2C. 
   - Specific to the 4-chars display: 
      - Short-circuit the "Vcc" and "I2CV" pins (two extream pins)
      - Set each displa to its own address
   - The sketch at "arduino_sketshes_no_dcs_bios_integration/get_i2c_disp_addr_through_serial
     can detect the addresses of the displays present.
   - It is important to turn off the "LiveSignalRts" check box in the DCS-BIOS Bridge      
     This is because the "RTS" signal is used as "reset" in the ESP2866

   - Wiring the displays:
<br>

| I2C |ESP8266| 4 Disp|
| ----| ----- |-------|
| Vcc |  5V | 2x +|
| Gnd |  G | -|
| SCL |  D1 |C |
| SDA |  D2 |D |


### Refrences

  - https://diyi0t.com/i2c-tutorial-for-arduino-and-esp8266
  - https://lcddisplay.co/wp-content/uploads/2023/02/SSD1307.pdf
  - https://www.displayfuture.com/Display/datasheet/controller/SSD1307.pdf

### ESP8266 and Display Refernces

  - https://diyi0t.com/i2c-tutorial-for-arduino-and-esp8266

  - https://www.digikey.com/en/maker/tutorials/2022/an-introduction-to-14-segment-led-displays-with-the-ht16k33-driver

