#include <FastLED.h>
#include <Arduino.h>
#include "LEDStripState.h"

#ifndef LIGHTSTATE_H
#define LIGHTSTATE_H

class LightState {

    private:
        String name;
        LEDStripState strip;

    public:

        LightState() {}
        LightState(LEDStripState strip, String name) {
            this->strip = strip;
            this->name = name;
        }

        virtual ~LightState() { }

        LEDStripState getStrip() {
            return this->strip;
        }

        void setStrip(LEDStripState strip) {
            this->strip = strip;
        }

        String getName() {
            return this->name;
        }

        void setName(String name) {
            this->name = name;
        }
};

#endif
