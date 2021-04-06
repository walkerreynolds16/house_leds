#include "Rainbow.h"
#include "FastLED.h"

Rainbow::Rainbow() {}

Rainbow::Rainbow(CRGB *ledArr, const int numLEDS, int initial, int delta, int density, int delay) : Effect(ledArr, numLEDS)
{
    initial_hue = initial;
    hue_delta = delta;
    hue_density = density;
    delay_milis = delay;
}

void Rainbow::setup() {}

void Rainbow::loop()
{
    fill_rainbow(ledArr, numLEDS, initial_hue += hue_density, hue_delta);
    delay(delay_milis);
    FastLED.show();
}

Rainbow::~Rainbow() {}
