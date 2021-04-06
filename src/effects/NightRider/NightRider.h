#include "../../models/Effect.h"
#include "FastLED.h"

#ifndef NIGHTRIDER_H
#define NIGHTRIDER_H

class NightRider : public Effect {
    public:
        int color;
        int delay_milis;
        int trailingLEDCount;
        int ledFadeAmnt;

        int movingLED;
        int direction;

        NightRider();
        NightRider(CRGB ledArr[], const int numLEDS, CRGB::HTMLColorCode color, int trailingLEDCount, int ledFadeAmnt, int delay_milis);
        ~NightRider();

        void setup();
        void loop();
};

#endif