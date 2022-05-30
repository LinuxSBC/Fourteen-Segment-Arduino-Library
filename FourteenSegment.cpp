#include "FourteenSegment.h"
#include <vector>
#include "Digit.h"

using std::vector;

FourteenSegment::FourteenSegment(uint8_t cathodes [], uint8_t anodes [15], uint8_t numDigits) {
    for (int i = 0; i < numDigits; i++) {
        auto* digit = new Digit(cathodes[i], anodes);
        digits.push_back(digit);
    }
    this->numDigits = numDigits;
}

void FourteenSegment::drawString(String str) {
    if (str.length() > numDigits)
        str = str.substring(0, numDigits);

    for (unsigned int i = 0; i < str.length(); i++) {
        digits[i]->drawChar(' ');
        digits[i]->show();
        digits[i]->drawChar(str.charAt(i));
        digits[i]->hide();
    }
}

void FourteenSegment::enableDecimalPoint(int digit, bool enable) {
    if (enable) {
        digits[digit]->drawSegment(14);
    } else {
        digits[digit]->eraseSegment(14);
    }
}

void FourteenSegment::wraparoundString(const String& str, int switchingTime) {
    unsigned long initialTime = millis();
    for (int i = 0; i < str.length(); i += numDigits) {
        while (millis() < initialTime + ((i + numDigits) / numDigits) * switchingTime)
            drawString(str.substring(i));
    }
}

void FourteenSegment::rotateString(const String& str, int switchingTime) {
    unsigned long initialTime = millis();
    for (int i = 0; i < str.length() + 1; i++) {
        while (millis() < initialTime + (i + 1) * switchingTime)
            drawString(str.substring(i));
    }
}
