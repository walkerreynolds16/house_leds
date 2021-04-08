#include <FastLED.h>

#ifndef EFFECT_H
#define EFFECT_H

class Effect {

    public:
        CRGB *ledArr;
        int numLEDS;

        Effect() {}
        Effect(CRGB *ledArr, const int numLEDS) {
            this->ledArr = ledArr;
            this->numLEDS = numLEDS;
        }

        ~Effect() { }

        virtual void setup() = 0;
        virtual void loop() = 0;  
};

#endif
