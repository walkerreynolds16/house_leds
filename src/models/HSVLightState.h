#include <FastLED.h>
#include <Arduino.h>
#include "LightState.h"
#include "LEDStripState.h"

#ifndef HSVLIGHTSTATE_H
#define HSVLIGHTSTATE_H

class HSVLightState : public LightState {

    public:
        CHSV *ledArr;

        HSVLightState() {}
        HSVLightState(CHSV *ledArr, String name, LEDStripState strip) : LightState (strip, name) {
            this->ledArr = ledArr;
        }

        virtual ~HSVLightState() { }
};

#endif
