#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define WIRE Wire
Adafruit_SSD1306 display = Adafruit_SSD1306(64, 48, &WIRE);

void setup() {
  Serial.begin(9600);

  Serial.println("OLED FeatherWing test");
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32

  Serial.println("OLED begun");

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(1000);

  // Clear the buffer.
  display.clearDisplay();
  display.display();

  Serial.println("IO test");


  // text display tests
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  //display.print("Connecting to SSID\n'adafruit':");
   //display.println("IP: 10.0.1.23");
  //display.println("Sending val #0");
  //display.setCursor(0,0);
  display.display(); // actually display all of the above
}

void loop() {
  Serial.println("01");
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("01");
  display.display();
  delay(2000);
  Serial.println("48");
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("48");
  display.display();
  delay(2000);
}
