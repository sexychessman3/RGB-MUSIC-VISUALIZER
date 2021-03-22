
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN            6

#define NUMPIXELS      30
#define DB 50

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
