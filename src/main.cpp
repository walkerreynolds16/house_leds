#include <Arduino.h>
#include <FastLED.h>

#include "effects/Rainbow/Rainbow.h"
// #include "effects/Marquee/Marquee.h"
// #include "effects/RainbowMarquee/RainbowMarquee.h"
// #include "effects/NightRider/NightRider.h"
// #include "services/WebServer.h"
#include "services/LEDService.h"

#define LED_PIN 4
#define NUM_LEDS 60

Rainbow rainbow;
// Marquee marquee;
// RainbowMarquee rainbowMarquee;
// NightRider nightRider;
LEDService ledService;
RGBLightState ls;

#define NUM_LEDS 60

CRGB leds[NUM_LEDS];

void setup()
{
    Serial.begin(115200);

    // put your setup code here, to run once:
    pinMode(LED_BUILTIN, OUTPUT);

    // delay(5000);

    // marquee = Marquee(leds, NUM_LEDS, CRGB::DarkGoldenrod, 125);
    // marquee.setup();

    // rainbowMarquee = RainbowMarquee(leds, NUM_LEDS, 0, 16, 4, 125);
    // rainbowMarquee.setup();

    // nightRider = NightRider(leds, NUM_LEDS, CRGB::DarkRed, 5, 128, 20);
    // nightRider.setup();
    ledService = LEDService();
    LEDStripState strip = LEDStripState(NUM_LEDS, true, 255);
    ls = RGBLightState(leds, "testRainbow", strip);

    rainbow = Rainbow(leds, NUM_LEDS, 0, 16, 4, 10);
    rainbow.setup();

    // ledService.setLightState();
    // startServer();
}

void loop()
{
    rainbow.loop();
    // marquee.loop();
    // rainbowMarquee.loop();
    // nightRider.loop();
    // loopServer();

    ledService.setLightState(ls);

    
}