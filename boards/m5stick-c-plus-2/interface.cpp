#include "core/powerSave.h"
#include "core/utils.h"
#include <M5Unified.h>
#include <interface.h>

#define TFT_BRIGHT_CHANNEL 0
#define TFT_BRIGHT_Bits 8
#define TFT_BRIGHT_FREQ 5000

void _setup_gpio() {
    M5.begin();
    Wire1.begin(21, 22);
    pinMode(G26, OUTPUT);
    pinMode(G0, OUTPUT);
    digitalWrite(G26, HIGH);
    digitalWrite(G0, LOW);

    pinMode(G37, INPUT_PULLUP);
    pinMode(G35, INPUT_PULLUP);
    pinMode(G39, INPUT_PULLUP);

    ledcSetup(TFT_BRIGHT_CHANNEL, TFT_BRIGHT_FREQ, TFT_BRIGHT_Bits);
    ledcAttachPin(G27, TFT_BRIGHT_CHANNEL);
    ledcWrite(TFT_BRIGHT_CHANNEL, 200);
}

bool __attribute__((weak)) isCharging() { return false; }

void __attribute__((weak)) turnOff() { M5.Power.powerOff(); }

void __attribute__((weak)) deepSleep() { M5.Power.deepSleep(); }

void __attribute__((weak)) reboot() { esp_restart(); }

uint8_t __attribute__((weak)) getBatteryPercent() {
    int raw = M5.Power.getBatteryLevel();
    return (raw < 0) ? 100 : (uint8_t)raw;
}
