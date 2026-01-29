#define DCSBIOS_DEFAULT_SERIAL
// #define DCSBIOS_IRQ_SERIAL   // This statment (as opposed to DCSBIOS_DEFAULT_SERIAL) is for 'real' Arduino boards - not for ESP
#include "DcsBios.h"
// #include "Addresses.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

#define DISPLAY_ADDRESS 0x70


Adafruit_AlphaNum4 disp0 = Adafruit_AlphaNum4();
Adafruit_AlphaNum4 disp1 = Adafruit_AlphaNum4();
Adafruit_AlphaNum4 disp2 = Adafruit_AlphaNum4();
Adafruit_AlphaNum4 disp3 = Adafruit_AlphaNum4();
Adafruit_AlphaNum4 disp4 = Adafruit_AlphaNum4();

String text_to_display = "  HELLO WORLD  ";
int string_pointer = 0;
char display_buffer[4];
long last_display_refresh = 0L;


void onUfcOptionDisplay1Change(char* textToDisplay) {
  disp0.clear();
	// send the text to the display
	for(int i = 0; i < 4; i++) {     
        //display_buffer[i] = textToDisplay.charAt(i);
  	    //disp.writeDigitAscii(i, display_buffer[i]);
  	    disp0.writeDigitAscii(i, textToDisplay[i]);
        
  }
  disp0.writeDisplay();
}
 
// DcsBios::StringBuffer<4> ufcOptionDisplay1Buffer(FA_18C_hornet_UFC_OPTION_DISPLAY_1_A, onUfcOptionDisplay1Change);
// DcsBios::StringBuffer<4> ufcOptionDisplay1Buffer(FA_18C_hornet_UFC_OPTION_DISPLAY_1  , onUfcOptionDisplay1Change);
   DcsBios::StringBuffer<4> ufcOptionDisplay1Buffer(0x7432, onUfcOptionDisplay1Change);




void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // Initialize the built-in LED pin as an output
  
  disp0.begin(DISPLAY_ADDRESS);
  //disp.setBrightness(4);
  disp0.setBrightness(15);
  disp0.clear();
  //disp.flashDigitAscii(0, '2');
  disp0.writeDigitAscii(0, '0');
  disp0.writeDisplay();
  disp0.writeDigitAscii(1, '0');
  disp0.writeDisplay();

  disp1.begin(DISPLAY_ADDRESS+1);
  //disp.setBrightness(4);
  disp1.setBrightness(15);
  disp1.clear();
  //disp.flashDigitAscii(0, '2');
  disp1.writeDigitAscii(0, '0');
  disp1.writeDisplay();
  disp1.writeDigitAscii(1, '1');
  disp1.writeDisplay();

  disp2.begin(DISPLAY_ADDRESS+2);
  //disp.setBrightness(4);
  disp2.setBrightness(15);
  disp2.clear();
  //disp.flashDigitAscii(0, '2');
  disp2.writeDigitAscii(0, '0');
  disp2.writeDisplay();
  disp2.writeDigitAscii(1, '2');
  disp2.writeDisplay();

  disp3.begin(DISPLAY_ADDRESS+3);
  //disp.setBrightness(4);
  disp3.setBrightness(15);
  disp3.clear();
  //disp.flashDigitAscii(0, '2');
  disp3.writeDigitAscii(0, '0');
  disp3.writeDisplay();
  disp3.writeDigitAscii(1, '3');
  disp3.writeDisplay();

  disp4.begin(DISPLAY_ADDRESS+4);
  //disp.setBrightness(4);
  disp4.setBrightness(15);
  disp4.clear();
  //disp.flashDigitAscii(0, '2');
  disp4.writeDigitAscii(0, '0');
  disp4.writeDisplay();
  disp4.writeDigitAscii(1, '4');
  disp4.writeDisplay();



  DcsBios::setup();
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);  // Turn the LED on (Note: LOW is often ON for onboard LEDs)
  delay(1000);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH); // Turn the LED off
  delay(1000);                      // Wait for a second
  DcsBios::loop();
}