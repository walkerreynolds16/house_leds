#ifndef LEDSERVICE_H
#define LEDSERVICE_H

#include "../models/RGBLightState.h"
#include "../models/HSVLightState.h"

#include <Arduino.h>
#include <FastLED.h>
#include <stdexcept>

// CONFIG
#define LED_PIN 4
#define NUM_LEDS 60
#define LED_TYPE WS2812B
#define LED_ORDER GRB
#define DEFAULT_BRIGHTNESS 16


class LEDService {

    private:
        CRGB *leds;

    public:
        LEDService() {

            pinMode(LED_PIN, OUTPUT);

            leds = new CRGB[NUM_LEDS];

            FastLED.addLeds<LED_TYPE, LED_PIN, LED_ORDER>(leds, NUM_LEDS);
            FastLED.setBrightness(DEFAULT_BRIGHTNESS);
        }

        ~LEDService() {}

        void setLightState(RGBLightState ls) {
            if (ls.getStrip().getNumLEDS() != NUM_LEDS) {
                throw std::invalid_argument("LightState's NumLEDS did not match LEDService's NumLEDS");
            }

            if (ls.getStrip().isPowered()) {
                CRGB *tempLEDS = ls.getLEDArr();

                for (int i = 0; i < NUM_LEDS; i++) {
                    leds[i] = tempLEDS[i];
                }

                FastLED.setBrightness(ls.getStrip().getBrightness());

            } else {
                FastLED.clear();
            }

            // TODO name is a little fucked
            // Showing lightState ���?␏Setting light state
            // Serial.printf("Showing lightState %s", ls.getName());
            FastLED.show();
        }

        void setLightState(HSVLightState ls) {
            // Create HSV array
            // convert to RGB using hsv2rgb_raw()
            
        }

};


#endif