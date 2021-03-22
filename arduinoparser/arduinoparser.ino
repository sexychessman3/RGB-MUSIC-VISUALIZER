
// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      30
#define DB 50

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int data;
long fPH = 0;
int curr_brightness = DB;

void setup() {
  Serial.begin(9600); //initialize serial COM at 9600 baudrate
  strip.begin(); // This initializes the NeoPixel library
  strip.setBrightness(DB);
  strip.clear();
  strip.show();
}

void loop() {
  while (Serial.available()) {
    data = Serial.read();
  }
  if (curr_brightness > DB) {
    curr_brightness -= 10;
  }
  if (data == '2') {
    curr_brightness = 255;
    data = '1';
  }
  for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
    int pixelHue = fPH + (i * 65536L / strip.numPixels());
    strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
  }
  if (fPH > 5 * 65536) {
    fPH = 0;
  }
  fPH += 256;
  
  if (data == '0') {
    strip.clear();
  }
  strip.setBrightness(curr_brightness);
  strip.show();
  delay(10);
}
