/*
  This code initializes and sets up a Liquid Crystal Display 16x2 with an I2C interface 
  using the LiquidCrystal I2C library. And prints "Hello world!" and "LCD Tutorial" on the 
  first and second lines of the display.

  Board: ESP8266
  Component: Liquid Crystal Display 1620 with I2C Interface
  Library: https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/ (LiquidCrystal I2C by Frank de Brabander)  
*/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // initialize the Liquid Crystal Display object with the I2C address 0x27, 16 columns and 2 rows

int i = 0;
int j = 0;
int k = 0;
int delayTime2 = 350; // Delay between shifts

void scrollInFromRight (int line, char str1[]) {
  // Written by R. Jordan Kreindler June 2016
  i = strlen(str1);
  for (j = 16; j >= 0; j--) {
      lcd.setCursor(0, line);
      for (k = 0; k <= 15; k++) {
        lcd.print(" "); // Clear line
      }
      lcd.setCursor(j, line);
      lcd.print(str1);
      delay(delayTime2);
  }
}


void scrollInFromLeft (int line, char str1[]) {
  // Written by R. Jordan Kreindler June 2016
  i = 40 - strlen(str1);
  line = line - 1;
  for (j = i; j <= i + 16; j++) {
    for (k = 0; k <= 15; k++) {
      lcd.print(" "); // Clear line
    }
    lcd.setCursor(j, line);
    lcd.print(str1);
    delay(delayTime2);
  }
}



void setup() {
  lcd.init();       // initialize the LCD
  lcd.clear();      // clear the LCD display
  lcd.backlight();  // Make sure backlight is on

  // Print a message on both lines of the LCD.
  lcd.setCursor(2, 0);  //Set cursor to character 2 on line 0
  lcd.print("Hello world!");

  lcd.setCursor(2, 1);  //Move cursor to character 2 on line 1
  lcd.print("LCD Tutorial");
}

void loop() {
   lcd.clear();

scrollInFromRight(0, "All wepons ready");
}