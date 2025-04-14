//code using 3 led sensors 
#include <FastLED.h>

#define LED_STRIP_PIN 12
#define NUM_LEDS 59
#define BRIGHTNESS 50
#define LED_TYPE WS2811
#define COLOR_ORDER GRB

// Pressure sensor pins
#define PRESSURE_SENSOR_1 A0
#define PRESSURE_SENSOR_2 A1
#define PRESSURE_SENSOR_3 A2
#define PRESSURE_SENSOR_4 A3


// Threshold to detect a press
#define PRESS_THRESHOLD 500

CRGB leds[NUM_LEDS];

void setup() {
    pinMode(PRESSURE_SENSOR_1, INPUT);
    pinMode(PRESSURE_SENSOR_2, INPUT);
    pinMode(PRESSURE_SENSOR_3, INPUT);
        pinMode(PRESSURE_SENSOR_4, INPUT);


    Serial.begin(9600);
    FastLED.addLeds<LED_TYPE, LED_STRIP_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(BRIGHTNESS);
}


void loop() {
    int sensor1Value = analogRead(PRESSURE_SENSOR_1);
    int sensor2Value = analogRead(PRESSURE_SENSOR_2);
    int sensor3Value = analogRead(PRESSURE_SENSOR_3);
        int sensor3Value = analogRead(PRESSURE_SENSOR_4);


    Serial.print("Sensor 1: "); Serial.print(sensor1Value);
    Serial.print(" | Sensor 2: "); Serial.print(sensor2Value);
    Serial.print(" | Sensor 3: "); Serial.println(sensor3Value);
        Serial.print(" | Sensor 4: "); Serial.println(sensor4Value);


    if (sensor1Value > 1100) {
        fill_solid(leds, NUM_LEDS, CRGB::Red);
    } else if (sensor2Value > 1200) {
        fill_solid(leds, NUM_LEDS, CRGB::Blue);
    } else if (sensor3Value > 900) {
        fill_solid(leds, NUM_LEDS, CRGB::Green);
    } else if (sensor4Value > 900) {
        fill_solid(leds, NUM_LEDS, CRGB::Random);
    } else {
        FastLED.clear();  // No pressure → turn off
    }

    FastLED.show();
    // delay(100);
}