#include <FastLED.h>
#include <Arduino.h>
#include "LightState.h"
#include "LEDStripState.h"

#ifndef RGBLIGHTSTATE_H
#define RGBLIGHTSTATE_H

class RGBLightState : public LightState {

    private:
        CRGB *ledArr;

    public:

        RGBLightState() {}
        RGBLightState(CRGB *ledArr, String name, LEDStripState strip) : LightState (strip, name) {
            this->ledArr = ledArr;
        }

        virtual ~RGBLightState() { }

        CRGB* getLEDArr() {
            return this->ledArr;
        }

        void setLEDArr(CRGB *ledArr) {
            this->ledArr = ledArr;
        }
};

#endif
