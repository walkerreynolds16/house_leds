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

        virtual ~Effect() { }

        virtual void setup();
        virtual void loop();  
};

#endif
