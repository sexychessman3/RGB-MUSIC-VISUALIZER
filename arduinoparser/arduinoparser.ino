
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

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int data;

void setup() {
  Serial.begin(9600); //initialize serial COM at 9600 baudrate
  strip.begin(); // This initializes the NeoPixel library.
}
 
void loop() {
while (Serial.available()){
  data = Serial.read();
}

if (data == '1')
pixels.setPixelColor(2, pixels.Color(0,0,100));

else if (data == '0')
pixels.setPixelColor(2, pixels.Color(100,0,0));

pixels.show();
}
