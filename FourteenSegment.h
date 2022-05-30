#ifndef FOURTEENSEGMENT_FOURTEENSEGMENT_H
#define FOURTEENSEGMENT_FOURTEENSEGMENT_H


#include <Arduino.h>
#include <vector>
#include "Digit.h"

using std::vector;

class FourteenSegment {
public:
    /**
     * Each cathode corresponds to a digit, and each anode corresponds to a segment.
     * @param cathodes - array of pin numbers for the cathodes connecting to each digit
     * @param anodes - array of pin numbers for the anodes connecting to each segment
     * @param numDigits - number of digits on the display. Also the number of cathodes.
     */
    explicit FourteenSegment(uint8_t cathodes [], uint8_t anodes [15], uint8_t numDigits);
    /**
     * Draws a string to the display. If the string is longer than the display, it will be truncated.
     * @param str - the string to display
     */
    void drawString(String str);
    /**
     * Draws a string longer than the display by printing each set of numDigits characters every switchingTime milliseconds.
     * @param str - The string to be drawn
     * @param switchingTime - The time in milliseconds between each set of characters
     */
    void wraparoundString(const String& str, int switchingTime);
    /**
     * Enables or disables the decimal point for a given digit.
     * @param digit - the index of the digit for which you want to enable/disable the decimal point
     * @param enable - true to enable, false to disable
     */
    void enableDecimalPoint(int digit, bool enable);
    /**
     * Draws a string that rotates each character in to show the whole string every switchingTime milliseconds. Works better with longer displays.
     * @param str - The string to draw
     * @param switchingTime - The time in milliseconds between each rotation
     */
     void rotateString(const String& str, int switchingTime);
private:
    uint8_t numDigits;
    vector<Digit*> digits;
};


#endif //FOURTEENSEGMENT_FOURTEENSEGMENT_H
