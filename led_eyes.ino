//Basic sine wave animation for NeoPixel Ring Bangle Bracelet
//by Dano Wall and Becky Stern for Adafruit Industries
#include <Adafruit_NeoPixel.h>

// PIN defs (change this!)
#define PIN           6

// LED defs
#define TOTAL_LEDS   32
#define HALF_LEDS    16
#define QUARTER_LEDS  8

// Number of LEDS in your model (change this!)
#define NUM_LEDS     32

// Brightness defs
#define DIM          50
#define BRIGHT      150
#define SUPERBRIGHT 255

// Speed defs
#define SLOW        200
#define MED          75
#define FAST         25

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type:
//   NEO_GRB  Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB  Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB);

// Color defs
uint32_t pink = strip.Color(255, 0, 255);   // PINK
uint32_t red = strip.Color(255, 0, 0);      // RED
uint32_t orange = strip.Color(255, 134, 0); // ORANGE
uint32_t yellow = strip.Color(255, 255, 0); // YELLOW
uint32_t green = strip.Color(0, 255, 0);    // GREEN
uint32_t cyan = strip.Color(0, 195, 219);   // CYAN
uint32_t blue = strip.Color(0, 0, 255);     // BLUE
uint32_t purple = strip.Color(110, 0, 110); // PURPLE
uint32_t black = strip.Color(0, 0, 0);      // BLACK

// Assignment  (change this!)
uint32_t c1 = pink;
uint32_t c2 = red;
uint32_t c3 = orange;
uint32_t c4 = yellow;
uint32_t c5 = green;
uint32_t c6 = cyan;
uint32_t c7 = blue;
uint32_t c8 = purple;

// These are the pixels in order of animation-- 36 pixels in total:
uint32_t colors[] = {c1, c2, c3, c4, c5, c6, c7, c8};

// Index to handle offset when looping
int idx = 0;

void setup() {
  strip.begin();
  strip.show();             // Initialize all pixels to 'off'
  strip.setBrightness(DIM); // <x>/255 brightness (about 15%)
}

void loop() {
  // Iterate over all LEDs settng new colors
  //  - Mod against 1/4 of all LEDs as we have 2 patterns in each eye
  for(int i=0; i<TOTAL_LEDS; ++i) {
    strip.setPixelColor(i, colors[(idx+i)%QUARTER_LEDS]);
  }

  // Set a delay to control refresh rate
  delay(MED);
  strip.show();

  // Increment and mod index to prevent overflows
  idx += 1;
  idx %= HALF_LEDS;
}
