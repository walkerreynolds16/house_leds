#include "../../models/Effect.h"
#include "FastLED.h"

#ifndef MARQUEE_H
#define MARQUEE_H

class Marquee : public Effect {
    public:
        int color;
        int frequency;

        Marquee();
        Marquee(CRGB ledArr[], const int numLEDS, CRGB::HTMLColorCode color, int frequency);
        ~Marquee();

        void setup();
        void loop();
};

#endif