#include <Arduino.h>
#include <FastLED.h>
#include "effects/Rainbow/Rainbow.h"
#include "effects/Marquee/Marquee.h"
#include "effects/RainbowMarquee/RainbowMarquee.h"
#include "effects/NightRider/NightRider.h"

#define LED_PIN 4
#define NUM_LEDS 60

CRGB leds[NUM_LEDS];

Rainbow rainbow;
Marquee marquee;
RainbowMarquee rainbowMarquee;
NightRider nightRider;

void setup()
{
    // put your setup code here, to run once:
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);

    FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(255);

    // rainbow = Rainbow(leds, NUM_LEDS, 0, 16, 4, 50);

    // rainbow.setup();

    // marquee = Marquee(leds, NUM_LEDS, CRGB::DarkGoldenrod, 125);

    // marquee.setup();

    // rainbowMarquee = RainbowMarquee(leds, NUM_LEDS, 0, 16, 4, 125);
    // rainbowMarquee.setup();

    nightRider = NightRider(leds, NUM_LEDS, CRGB::DarkRed, 2, 128, 15);
    nightRider.setup();
}

void loop()
{
    // rainbow.loop();
    // marquee.loop();
    // rainbowMarquee.loop();
    nightRider.loop();
}