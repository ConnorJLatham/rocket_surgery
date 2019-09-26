/* ROCKET SURGERY
 *  This code is for the rocket surgery educational outreach activity. This code mainly controls the interactions between the user and the LED's on the rocket and the display board. 
 *  
 *  This code does do: LED control for the fast video and the slow video
 *  This code does not do: movie control (the movie simply needs to be played at the same time as the buttons on the rocket are pressed
 *  
 *  Comments throughout the code should make it clear what is happening and what each variable does. 
 *  
 *  More information about the lights and their setup can be found here: https://www.tweaking4all.com/hardware/arduino/arduino-ws2812-led/
 *  
 *  Connor Latham 06 March 2019
 */
// include the adafruit provided library (check the examples to find out more)
#include <Adafruit_NeoPixel.h>
#include <Sequence.h>

// define input parameters for the different LED strips
#define rocketPin 6 // pin that the rocket led strip is connected to
#define rocketLEDCount 50 // number of leds on that strip
#define boardPin 7 // pin that the board led strip is connected to
#define boardLEDCount 20 // number of leds on that board strip

// define the button pins
#define beginButtonPin 9 // pin for the begin button
#define slowTogglePin 8 // toggles slow or fast mode

// define full speed full video time intervals
#define ignitionDelay 6.33 // time from start of video to ignition
#define drogueDelay 18.66 // time from start of video to drogue deployment
#define drogueBackupDelay 21.8 // time from start of video to backup drogue charge

// declare the strip outside so other functions can see it
/* Input parameters for the library
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
*/

// init the strip with the rocket LED strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(rocketLEDCount, rocketPin, NEO_RGB + NEO_KHZ800); // make sure it is NEO_RGB and not the default GRB

void setup() {
strip.begin(); // actually begins the object
strip.show(); // updates the LEDs (turns them all off, since none have been turned on yet)

colorWipe(strip.Color(120, 120, 120), 50); // test all rocket LEDs by turning on all colors (white)
colorWipe(strip.Color(0,0,0),50); // turn them all off 

strip.setPin(boardPin); // update the pin number to be the board set of LEDs
strip.updateLength(boardLEDCount); // update the length of the strip to the board set

colorWipe(strip.Color(120, 120, 120), 50); // test all board LEDs by turning on all colors (white)
colorWipe(strip.Color(0, 0, 0), 50); // turn them all off 

// set up the different toggles
boolean beginSeq = false; /* begins or resets the regular speed sequence (if pressed once, will start sequence, 
and if pressed again while sequence is still happening, it will start at the beginning but not play again (0->1->0) */
boolean slowSeq = false; // turns on slow mode, can be initiated at any point in the sequence
pinMode(beginButtonPin, INPUT); // set the pinmode for the push buttons
pinMode(slowTogglePin, INPUT);
}

void loop() {

}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void blinkLED(int n, uint32_t c) {
  for(int i=0;i<10;i++){
    strip.setPixelColor(n,c);
    strip.show();
    delay(200);
    strip.setPixelColor(n,(0,0,0));
    strip.show();
    delay(200);
  }
}


