#include "Marquee.h"
#include "FastLED.h"

Marquee::Marquee() { }

Marquee::Marquee(CRGB *ledArr, const int numLEDS, CRGB::HTMLColorCode color, int frequency) : Effect(ledArr, numLEDS) {
    this->color = color;
    this->frequency = frequency;
}

void Marquee::setup() { 

}

void Marquee::loop() {
    static int iter = 0;
    FastLED.clear();

    if (iter % 2 == 0) {
        for (int i = 0; i < numLEDS-1; i+= 2) {
            ledArr[i] = color;
        }
    } else {
        for (int i = 1; i < numLEDS-1; i+= 2) {
            ledArr[i] = color;
        }
    }

    if (iter == numLEDS) {
        iter = 0;
    } else {
        iter += 1;
    }

    FastLED.show();
    delay(frequency);
}

Marquee::~Marquee() { }
