#include <FastLED.h>

#define LED_PIN     12
#define NUM_LEDS    59
#define BRIGHTNESS  50
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB

int sensorValue = 0;
CRGB leds[NUM_LEDS];

void setup() {
    pinMode(A0, INPUT);  // Pressure sensor input
    Serial.begin(9600);  // Start serial monitor
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
    sensorValue = analogRead(A0);  // Read pressure sensor
    Serial.print("Pressure Sensor Value: ");
    Serial.println(sensorValue);

    if (sensorValue > 900) {
        // Light up random LEDs in fun colors
        leds[1] = CRGB::Red;
        leds[35] = CRGB::Blue;
        leds[31] = CRGB::HotPink;
        leds[40] = CRGB::Green;
        leds[4] = CRGB::Purple;
        leds[14] = CRGB::Magenta;
        leds[24] = CRGB::Cyan;
        leds[30] = CRGB::Aqua;
        leds[7] = CRGB::AliceBlue;
        leds[10] = CRGB::Coral;
        leds[20] = CRGB::DarkViolet;
        leds[58] = CRGB::PapayaWhip;
    } else {
        FastLED.clear();  // Turn off LEDs
    }

    FastLED.show();  // Update LEDs
    // delay(100);  // Chill out a sec
}
