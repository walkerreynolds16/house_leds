#include "RainbowMarquee.h"
#include "FastLED.h"

RainbowMarquee::RainbowMarquee() { }

RainbowMarquee::RainbowMarquee(CRGB ledArr[], const int numLEDS, int initial_hue, int hue_delta, int hue_density, int frequency) : Effect(ledArr, numLEDS) {
    this->initial_hue = initial_hue;
    this->hue_delta = hue_delta;
    this->hue_density = hue_density;
    this->frequency = frequency;
}

void RainbowMarquee::setup() { 

}

void RainbowMarquee::loop() {
    static int iter = 0;
    FastLED.clear();
    fill_rainbow(ledArr, numLEDS, initial_hue += hue_density, hue_delta);

    if (iter % 2 == 0) {
        for (int i = 0; i < numLEDS-1; i+= 2) {
            ledArr[i] = CRGB::Black;
        }
    } else {
        for (int i = 1; i < numLEDS-1; i+= 2) {
            ledArr[i] = CRGB::Black;
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

RainbowMarquee::~RainbowMarquee() { }
