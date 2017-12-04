#include "FastLED.h"
#include "Button.h"

#define NUM_LEDS 9
#define DATA_PIN 9

#define UPDATES_PER_SECOND 100

CRGB leds[NUM_LEDS];

Button button = Button(10,PULLUP);

byte buttonPresses = 0;

void setup() {
  
  Serial.begin(115200);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(50);

  for(byte x = 0; x < NUM_LEDS; x++) {
    
    leds[x] = CRGB::Black;
    FastLED.show();

    leds[x] = CRGB::DeepPink;
    FastLED.show();

    StartupSeq();
    
    leds[x] = CRGB::Black;
    FastLED.show();
  }  

  for(byte x = 0; x < NUM_LEDS; x++) {
    leds[x] = CRGB::DeepPink;
  }
  FastLED.show();
  delay(100);

  for(byte x = 0; x < NUM_LEDS; x++) {
    leds[x] = CRGB::Black;
    FastLED.show();
  }
  delay(100);
}


void loop() {

  if(button.isPressed()) {
    buttonPresses++;
    delay(500);
    Serial.println(buttonPresses);

    if (buttonPresses == 1) {
      leds[8] = CRGB::Green;
      leds[0] = CRGB::Blue;
      FastLED.show();
    }
    
    if (buttonPresses == 2) {
      leds[1] = CRGB::Blue;
      FastLED.show();
    }
    
    if (buttonPresses == 3) {
      leds[2] = CRGB::Blue;
      FastLED.show();
    }
    
    if (buttonPresses == 4) {
      leds[3] = CRGB::Blue;
      FastLED.show();
    }
    
    if (buttonPresses == 5) {
      leds[4] = CRGB::Blue;
      FastLED.show();
    }
    
    if (buttonPresses == 6) {
      leds[5] = CRGB::Blue;
      FastLED.show();
    }
    
    if (buttonPresses == 7) {
      leds[6] = CRGB::Blue;
      FastLED.show();
    }
    
    if (buttonPresses == 8) {
      leds[7] = CRGB::Blue;
      FastLED.show();
    }

    if (buttonPresses == 9) {
      buttonPresses = 0;
      for(byte x = 0; x < NUM_LEDS; x++) {
        leds[x] = CRGB::Black;
      }
    FastLED.show();
      
    }
  }
}

void StartupSeq() {
  for (int i=20; i <= 80; i++) {
    FastLED.setBrightness( i );
    delay(5);
    FastLED.show();
  }

  for (int i=79; i >= 20; i--) {
    FastLED.setBrightness( i );
    delay(5);
    FastLED.show();
  }
}

