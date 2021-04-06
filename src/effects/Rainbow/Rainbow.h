#include "../../models/Effect.h"
#include "FastLED.h"

#ifndef RAINBOW_H
#define RAINBOW_H

class Rainbow : public Effect {
    public:
        int initial_hue;
        int hue_delta;
        int hue_density;
        int delay_milis;

        Rainbow();
        Rainbow(CRGB ledArr[], const int numLEDS, int initial, int delta, int density, int delay);
        ~Rainbow();

        void setup();
        void loop();
};

#endif