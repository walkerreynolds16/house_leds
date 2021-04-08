#include <FastLED.h>
#include <Arduino.h>

#ifndef LEDSTRIPSTATE_H
#define LEDSTRIPSTATE_H

class LEDStripState {

    private:
        int numLEDS;
        uint8_t brightness;
        bool power;

    public:
        LEDStripState() {}
        LEDStripState(const int numLEDS, bool power, uint8_t brightness) {
            this->numLEDS = numLEDS;
            this->power = power;
            this->brightness = brightness;
        }

        virtual ~LEDStripState() { }

        int getNumLEDS() {
            return this->numLEDS;
        }

        uint8_t getBrightness() {
            return this->brightness;
        }

        void setBrightness(uint8_t brightness) {
            this->brightness = brightness;
        }

        bool isPowered() {
            return this->power;
        }

        void setPower(bool power) {
            this->power = power;
        } 

        void togglePower() {
            this->power = !power;
        }
};

#endif
