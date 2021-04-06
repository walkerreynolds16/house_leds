#include "../../models/Effect.h"
#include "FastLED.h"

#ifndef RAINBOWMARQUEE_H
#define RAINBOWMARQUEE_H

class RainbowMarquee : public Effect {
    public:
        int initial_hue;
        int hue_delta;
        int hue_density;
        int frequency;

        RainbowMarquee();
        RainbowMarquee(CRGB ledArr[], const int numLEDS, int initial, int delta, int density, int frequency);
        ~RainbowMarquee();

        void setup();
        void loop();
};

#endif