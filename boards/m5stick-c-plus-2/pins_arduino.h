#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>

#define HAS_3_BUTTONS
#define M5STICK

static const uint8_t TX = 1;
static const uint8_t RX = 3;

static const uint8_t SDA = 21;
static const uint8_t SCL = 22;

static const uint8_t SS    = 5;
static const uint8_t MOSI  = 15;
static const uint8_t MISO  = -1;
static const uint8_t SCK   = 13;

static const uint8_t G0  = 0;
static const uint8_t G2  = 2;
static const uint8_t G4  = 4;
static const uint8_t G5  = 5;
static const uint8_t G10 = 10;
static const uint8_t G12 = 12;
static const uint8_t G13 = 13;
static const uint8_t G15 = 15;
static const uint8_t G19 = 19;
static const uint8_t G21 = 21;
static const uint8_t G22 = 22;
static const uint8_t G25 = 25;
static const uint8_t G26 = 26;
static const uint8_t G27 = 27;
static const uint8_t G32 = 32;
static const uint8_t G33 = 33;
static const uint8_t G34 = 34;
static const uint8_t G35 = 35;
static const uint8_t G36 = 36;
static const uint8_t G37 = 37;
static const uint8_t G38 = 38;
static const uint8_t G39 = 39;

static const uint8_t DAC1 = 25;
static const uint8_t DAC2 = 26;

static const uint8_t ADC1 = 35;
static const uint8_t ADC2 = 36;

#define DEEPSLEEP_WAKEUP_PIN 39
#define DEEPSLEEP_PIN_ACT LOW
#endif
