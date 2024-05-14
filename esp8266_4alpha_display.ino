#define DCSBIOS_DEFAULT_SERIAL
// #define DCSBIOS_IRQ_SERIAL   // This statment (as opposed to DCSBIOS_DEFAULT_SERIAL) is for 'real' Arduino boards - not for ESP
#include "DcsBios.h"
// #include "Addresses.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

#define DISPLAY_ADDRESS 0x70


Adafruit_AlphaNum4 disp = Adafruit_AlphaNum4();

String text_to_display = "  HELLO WORLD  ";
int string_pointer = 0;
char display_buffer[4];
long last_display_refresh = 0L;


void onUfcOptionDisplay1Change(char* textToDisplay) {
  disp.clear();
	// send the text to the display
	for(int i = 0; i < 4; i++) {     
        //display_buffer[i] = textToDisplay.charAt(i);
  	    //disp.writeDigitAscii(i, display_buffer[i]);
  	    disp.writeDigitAscii(i, textToDisplay[i]);
        
  }
  disp.writeDisplay();
}
 
// DcsBios::StringBuffer<4> ufcOptionDisplay1Buffer(FA_18C_hornet_UFC_OPTION_DISPLAY_1_A, onUfcOptionDisplay1Change);
// DcsBios::StringBuffer<4> ufcOptionDisplay1Buffer(FA_18C_hornet_UFC_OPTION_DISPLAY_1  , onUfcOptionDisplay1Change);
   DcsBios::StringBuffer<4> ufcOptionDisplay1Buffer(0x7432, onUfcOptionDisplay1Change);

void setup()
{
  disp.begin(DISPLAY_ADDRESS);
  disp.setBrightness(4);
  disp.clear();
  disp.writeDigitAscii(0, 'I');
  disp.writeDisplay();
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
}