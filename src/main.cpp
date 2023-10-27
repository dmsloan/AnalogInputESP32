#include <Arduino.h>
#include <FastLED.h>

FASTLED_USING_NAMESPACE

// Potentiometer is connected to GPIO 34 (Analog ADC1_CH6) 
const int potPin = 34;

// variable for storing the potentiometer value
int potValue = 0;

// variable for storing the mapped potentiometer voltage
int potVoltage = 0;

// variable for storing the mapped potentiometer percent
int potPercentage = 0;

#define DATA_PIN 33 // LED strip data pin
#define LED_TYPE WS2812B // LED strip type
#define COLOR_ORDER GRB
#define NUM_LEDS 16 // number of LEDs in strip
CRGB leds[NUM_LEDS];

#define BRIGHTNESS 96
#define FRAMES_PER_SECOND 60

uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0;                  // rotating "base color" used by many of the patterns

void ringRotateFade()
{
    static int lNumber = 0;
    for (lNumber = 0; lNumber < NUM_LEDS * 6; lNumber++) 
    {
    const byte fadeAmt = 128;
    const int cometSize = 1;
    static int iDirection = -1;
    static int iPos = NUM_LEDS-1;

    if (iPos == (-1))
      iPos = NUM_LEDS - cometSize;
//        iDirection *= -1;
    
    for (int i = 0; i < cometSize; i++)
//        g_LEDs[iPos + i].setColorCode(0xFFFFFF); // set to pure white via hex
          leds[iPos] = CRGB( 255, 0, 0) ; // set to pure red via RGB
//       Randomly fade the LEDs
//        if (random(10) > 5)
    for (int j = 0; j < NUM_LEDS; j++)
            leds[j] = leds[j].fadeToBlackBy(fadeAmt);  
    iPos += iDirection;
    FastLED.show();
    Serial.printf("The loop number is %i.\n", lNumber);
    delay(100);
    }
}

void ringRedFade()
{
  // hue - red
  // saturation - max
  // value - 0-255

  fill_solid(leds, NUM_LEDS, CRGB::Red);
  //  fill_gradient_RGB(leds, NUM_LEDS/2, CRGB::Red, CRGB::Black );
  for (byte i = 0; i < 200; i++)
  {
    fadeToBlackBy(leds, NUM_LEDS, 10);
    //  fill_gradient_RGB(leds[7], NUM_LEDS/2, CRGB::Red, CRGB::Black );
    //  int position = 0;
    //  for (int i = 0; i < NUM_LEDS; i++)
    //    FastLED.setPixelColor((i + position) % NUM_LEDS, getPixelColorHsv(i, 0, 255, FastLED.gamma8(i * (255 / NUM_LEDS))));
    FastLED.show();
    //  position++;
    //  position %= NUM_LEDS;
    delay(50);
  }
}

void pulseRed()
{
  //  fill_solid( leds, NUM_LEDS, CRGB( 255, 0, 0));
  for (int redLed = 0; redLed < (NUM_LEDS / 4); redLed = redLed + 1)
  {
    // Turn our current led on to red, then show the leds
        for (int i = 0; i < NUM_LEDS; i += 4){
        leds[redLed+i] = CRGB::Red;
//        Serial.printf("%i\n", i);
    }
    // Show the leds (only one of which is set to red, from above)
    FastLED.show();

    // Wait a little bit
    delay(100);

    // Turn our current led back to black for the next loop around
        for (int i = 0; i < NUM_LEDS; i += 4){
        leds[redLed+i] = CRGB::Black;
    }
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.printf("Sketch name is AnalogInputESP32");
  delay(3000); // 3 second delay for recovery

  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  // FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // put your main code here, to run repeatedly:
    // Reading potentiometer value
  potValue = analogRead(potPin);
  Serial.print("\033[32m"); //Set terminal text color to green 32. Standard escape codes are prefixed with Escape: Octal: \033
  Serial.print(potValue);
  Serial.print(" Pot value\033[0m\n"); //Set terminal color back to default and insert a carrage return.
//  Serial.println("\033[1;32mbold green text\033[0m plain text\n");

  potVoltage = map(potValue, 0, 4096, 0, 3300);
  Serial.print("\033[1;31m"); //Set terminal text color to bold 1 red 31
  Serial.print(potVoltage);
  Serial.print(" Pot voltage\033[0m\n\n\a"); //Set terminal color back to white and insert a carrage return. \a is the Terminal bell. It works with Putty but not with the terminal built into PlatformIO
//Serial.println(); Not needed because of the /n above

  potPercentage = map(potValue, 0, 4096, 0, 100); // min read value, max read value, min scaled value, max scaled value
  Serial.print("\033[1;31m"); //Set terminal text color to bold 1 red 31
  Serial.print(potPercentage);
  Serial.print(" Pot percentage\033[0m\n\n\a"); //Set terminal color back to white and insert a carrage return. \a is the Terminal bell. It works with Putty but not with the terminal built into PlatformIO
//  ringRedFade();
//  pulseRed();
  ringRotateFade();
//  delay(500);
}

