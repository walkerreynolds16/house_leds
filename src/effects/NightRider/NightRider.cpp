#include "NightRider.h"
#include "FastLED.h"
#include "Arduino.h"

NightRider::NightRider() { }

NightRider::NightRider(CRGB *ledArr, const int numLEDS, CRGB::HTMLColorCode color, int trailingLEDCount, int ledFadeAmnt, int delay_milis) : Effect(ledArr, numLEDS) {
    this->color = color;
    this->delay_milis = delay_milis;
    this->trailingLEDCount = trailingLEDCount;
    this->ledFadeAmnt = ledFadeAmnt;
}

void NightRider::setup() { 
    movingLED = 1;
    direction = 1; // 1 goes postive led direction, -1 goes negative led direction
}

void NightRider::loop() {
    static int iter = 0;
    // FastLED.clear();
    
    if (movingLED == 0 || movingLED == (numLEDS - trailingLEDCount)) {
        direction *= -1;
    }

    movingLED += 1 * direction;

    for (int i = 0; i < trailingLEDCount; i++) {
        ledArr[movingLED + i] = color;
    }

    for (int k = 0; k < numLEDS; k++) {
        ledArr[k] = ledArr[k].fadeToBlackBy(ledFadeAmnt);
    }

    FastLED.show();
    delay(delay_milis);
}

NightRider::~NightRider() { }
