/*
 * IRremote
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * For details, see http://arcfn.com/2009/08/multi-protocol-infrared-remote-library.htm http://arcfn.com
 *
 * Interrupt code based on NECIRrcv by Joe Knapp
 * http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1210243556
 * Also influenced by http://zovirl.com/2008/11/12/building-a-universal-remote-with-an-arduino/
 *
 * Modified by Kristian Lauszus to work with ATTiny85
 * For details, see http://blog.tkjelectronics.dk
 * Attiny85 adaptation by Nick Gammon http://arduino.cc/forum/index.php?topic=91488.msg687101#msg687101)
 * Spilt into two lib by philteta@gmail.com www.tetalab.org (IRTinyTX-lib-v1)
 */

#ifndef attiny85_RC6_IR.h
#define attiny85_RC6_IR.h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define IRLED PB1 // (Used as OC0B) - pin 6 on ATtiny85

// Ensures that the compiler knows it's running at 16MHz, if it's not defined in the makefile or not using the Arduino IDE
#ifndef F_CPU
//#define F_CPU 16000000UL  // 16 MHz
#define F_CPU 8000000UL  // 8 MHz


#endif

#define TOPBIT 0x80000000
#define RC6_HDR_MARK  2666
#define RC6_HDR_SPACE 889
#define RC6_T1    444
#define RC6_RPT_LENGTH  46000

#define MIN_RC6_SAMPLES 1

class IRsend
{
public:
  IRsend() {}
  // *Note instead of sending the REPEAT constant if you want the JVC repeat signal sent, send the original code value and change the repeat argument from 0 to 1. JVC protocol repeats by skipping the header NOT by sending a separate code value like NEC does.
  void sendRC6(unsigned long data, int nbits);
  void enableIROut(uint8_t khz);
private:
  void mark(int16_t usec);
  void space(int16_t usec);
};

#endif
