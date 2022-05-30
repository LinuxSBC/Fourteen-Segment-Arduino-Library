#include "Digit.h"


Digit::Digit(uint8_t cathode, const uint8_t* anodes) {
    this->cathode = cathode;
    for (int i = 0; i < 15; i++) {
        this->anodes[i] = anodes[i]; // Arrays can't be directly assigned, so I needed to do this workaround.
        pinMode(anodes[i], OUTPUT); // Makes the pin a toggleable output rather than an input
    }
    pinMode(cathode, OUTPUT); // For the cathode, LOW allows the LED to turn on because there's a current gradient when the anode is HIGH and the cathode is LOW.
}

void Digit::hide() const {
    digitalWrite(cathode, HIGH); // "Hides" the digit by removing the current gradient without actually changing its value
                                 // Because of how diodes work, current cannot flow backwards, so no LED can be on while the cathode is HIGH.
}

void Digit::show() const {
    digitalWrite(cathode, LOW); // Opposite of hide(). Any anode set to HIGH will be visible, while any anode set to LOW will be invisible.
}

void Digit::drawSegment(uint8_t segment) {
    digitalWrite(segment, HIGH); // Pretty self-explanatory. Sets a given segment HIGH to make it visible if the digit is visible.
}

void Digit::eraseSegment(uint8_t segment) {
    digitalWrite(segment, LOW); // Opposite of drawSegment().
}

uint16_t Digit::getCharDef(char c) {
    return charMap[int(c) - 32]; // Maps the ASCII value of each character to a bitmask of the segments that should be lit.
}

void Digit::drawChar(char c) {
    uint16_t charDef = getCharDef(c);
    for (int i = 0; i < 15; i++) {
        if (charDef & (1 << i)) { // Checks if the bitmask is 1 at position i when converted to binary
            drawSegment(anodes[i]);
        } else {
            eraseSegment(anodes[i]);
        }
    }
}
