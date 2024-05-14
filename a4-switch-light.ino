/*
  Tell DCS-BIOS to use a serial connection and use interrupt-driven
  communication. The main program will be interrupted to prioritize
  processing incoming data.
  
  This should work on any Arduino that has an ATMega328 controller
  (Uno, Pro Mini, many others).
 */
#define DCSBIOS_IRQ_SERIAL

#include "DcsBios.h"
#include "Addresses.h"

/* paste code snippets from the reference documentation here */
/* DcsBios::LED masterCaution(A_10C_MASTER_CAUTION_AM, LED_BUILTIN); */
DcsBios::LED apn153Memorylight(A_4E_C_APN153_MEMORYLIGHT_AM, LED_BUILTIN);
DcsBios::Switch2Pos dopplerMemTest("DOPPLER_MEM_TEST", 9);
void setup() {
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
}

