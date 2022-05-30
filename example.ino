#include <Arduino.h>
#include "FourteenSegment.h"

// Cathodes (digits)—add as many as you want
uint8_t cathode1 = 11; // Digital pin 11
uint8_t cathode2 = 10;
uint8_t cathodes [] = {cathode1, cathode2};

// Segments (anodes)
uint8_t segA = 9;
uint8_t segB = 12;
uint8_t segC = 3;
uint8_t segD = A5;
uint8_t segE = A0;
uint8_t segF = 4;
uint8_t segG1 = 8;
uint8_t segG2 = A4;
uint8_t segH = 5;
uint8_t segJ = 6;
uint8_t segK = 7;
uint8_t segL = A1;
uint8_t segM = A2;
uint8_t segN = A3;
uint8_t segDP = 2;
uint8_t segments [15] = {segA, segB, segC, segD, segE, segF, segG1, segG2, segH, segJ, segK, segL, segM, segN, segDP};

FourteenSegment* display; // Allows the display to be accessed by both setup and loop

void setup() {
    display = new FourteenSegment(cathodes, segments, 2);
}

void loop() {
//    display->drawString("Hello world!"); // Simply cuts off any of the string that goes outside the display. It relies on a fast loop.
//    display->wraparoundString("Hello world!", 1500); // Displays the cut off text after the given time (in milliseconds).
    display->rotateString("  Hello world!", 1000); // Rotates the text right to left every x milliseconds.
}
