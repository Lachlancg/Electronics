#include <Adafruit_NeoPixel.h>
#define PIN 8
int stripLength = 88;
byte red = 94;
byte green = 21;
byte blue = 89;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(stripLength, PIN, NEO_GRB + NEO_KHZ800);

int button1Pin = 0;
int button2Pin = 1;

int button1State = 0;
int button2State = 0;
int lastButton1State = 0;
int lastButton2State = 0;
boolean state = false;

long lastTimeMillis;
long currentTimeMillis;
const long timeSeconds = 4;

int D1 = 0; //variable for single seconds up to 9
int D2 = 0; //variable for 10s of seconds up to 5
int D3 = 0; //variable for single min up to 9
int D4 = 0; //variable for 10s of min up to 5

void setup() {
  strip.begin();
  lastTimeMillis = millis();
}

void loop() {
  button1State = digitalRead(button1Pin);
  if (button1State != lastButton1State) {
    if (button1State == LOW) {
      reset();
      state = !state;
      delay(125);
    }
  }
  lastButton1State = button1State;

  button2State = digitalRead(button2Pin);
  if (button2State != lastButton2State) {
    if (button2State == LOW) {
      reset();
      D1 = 0;
      D2 = 0;
      D3 = 0;
      D4 = 0;
      state = false;
      reset();
      delay(125);
    }
  }
  lastButton2State = button2State;

  if (state == true)
  {
    currentTimeMillis = millis();
    if (currentTimeMillis > lastTimeMillis + timeSeconds) {
      lastTimeMillis = currentTimeMillis;
      D1++;
      if (D1 > 9) {
        D1 = 0;
        D2++;
        if (D2 > 9) {
          D2 = 0;
          D3++;
          if (D3 > 9) {
            D3 = 0;
            D4++;
            if (D4 > 5) {
              D4 = 0;
            }
          }
        }
      }
    }
    reset();
    pickNumber(D4, 0);
    pickNumber(D3, 21);
    pickNumber(D2, 42);
    pickNumber(D1, 63);
  }
  if (state == false) {
    reset();
    pickNumber(D4, 0);
    pickNumber(D3, 21);
    pickNumber(D2, 42);
    pickNumber(D1, 63);
  }

}
void pickNumber(int num, int segment)
{
  switch (num)
  {
    default:
      zero(segment);
      break;
    case 1:
      one(segment);
      break;
    case 2:
      two(segment);
      break;
    case 3:
      three(segment);
      break;
    case 4:
      four(segment);
      break;
    case 5:
      five(segment);
      break;
    case 6:
      six(segment);
      break;
    case 7:
      seven(segment);
      break;
    case 8:
      eight(segment);
      break;
    case 9:
      nine(segment);
      break;
  }
}
void reset() {
  for (int i = 0; i <= 87; i++) {
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();
}

void zero(int segment) {
  strip.setPixelColor(0 + segment, red, green, blue); //Segment B
  strip.setPixelColor(1 + segment, red, green, blue); //Segment B
  strip.setPixelColor(2 + segment , red, green, blue); //Segment B
  strip.setPixelColor(3 + segment, red, green, blue); //Segment B
  strip.setPixelColor(4 + segment, red, green, blue); //Segment B
  strip.setPixelColor(5 + segment , red, green, blue); //Segment B
  strip.setPixelColor(15 + segment, red, green, blue); //Segment D
  strip.setPixelColor(16 + segment, red, green, blue); //Segment D
  strip.setPixelColor(17 + segment, red, green, blue); //Segment D
  strip.setPixelColor(12 + segment, red, green, blue); //Segment D
  strip.setPixelColor(13 + segment, red, green, blue); //Segment D
  strip.setPixelColor(14 + segment, red, green, blue); //Segment D
  strip.setPixelColor(6 + segment, red, green, blue); //Segment D
  strip.setPixelColor(7 + segment, red, green, blue); //Segment D
  strip.setPixelColor(8 + segment, red, green, blue); //Segment D
  strip.setPixelColor(9 + segment, red, green, blue); //Segment D
  strip.setPixelColor(10 + segment, red, green, blue); //Segment D
  strip.setPixelColor(11 + segment, red, green, blue); //Segment D
  strip.show();
}
void one(int segment) {
  strip.setPixelColor(3 + segment, red, green, blue); //Segment B
  strip.setPixelColor(4 + segment, red, green, blue); //Segment B
  strip.setPixelColor(5 + segment , red, green, blue); //Segment B
  strip.setPixelColor(6 + segment, red, green, blue); //Segment D
  strip.setPixelColor(7 + segment, red, green, blue); //Segment D
  strip.setPixelColor(8 + segment, red, green, blue); //Segment D
  strip.show();
}
void two(int segment) {
  strip.setPixelColor(0 + segment, red, green, blue); //Segment B
  strip.setPixelColor(1 + segment, red, green, blue); //Segment B
  strip.setPixelColor(2 + segment , red, green, blue); //Segment B
  strip.setPixelColor(3 + segment, red, green, blue); //Segment D
  strip.setPixelColor(4 + segment, red, green, blue); //Segment D
  strip.setPixelColor(5 + segment, red, green, blue); //Segment D
  strip.setPixelColor(18 + segment, red, green, blue); //Segment D
  strip.setPixelColor(19 + segment, red, green, blue); //Segment D
  strip.setPixelColor(20 + segment, red, green, blue); //Segment D
  strip.setPixelColor(12 + segment, red, green, blue); //Segment D
  strip.setPixelColor(13 + segment, red, green, blue); //Segment D
  strip.setPixelColor(14 + segment, red, green, blue); //Segment D
  strip.setPixelColor(9 + segment, red, green, blue); //Segment D
  strip.setPixelColor(10 + segment, red, green, blue); //Segment D
  strip.setPixelColor(11 + segment, red, green, blue); //Segment D
  strip.show();
}
void three(int segment) {
  strip.setPixelColor(0 + segment, red, green, blue); //Segment B
  strip.setPixelColor(1 + segment, red, green, blue); //Segment B
  strip.setPixelColor(2 + segment , red, green, blue); //Segment B
  strip.setPixelColor(3 + segment, red, green, blue); //Segment D
  strip.setPixelColor(4 + segment, red, green, blue); //Segment D
  strip.setPixelColor(5 + segment, red, green, blue); //Segment D
  strip.setPixelColor(18 + segment, red, green, blue); //Segment D
  strip.setPixelColor(19 + segment, red, green, blue); //Segment D
  strip.setPixelColor(20 + segment, red, green, blue); //Segment D
  strip.setPixelColor(6 + segment, red, green, blue); //Segment D
  strip.setPixelColor(7 + segment, red, green, blue); //Segment D
  strip.setPixelColor(8 + segment, red, green, blue); //Segment D
  strip.setPixelColor(9 + segment, red, green, blue); //Segment D
  strip.setPixelColor(10 + segment, red, green, blue); //Segment D
  strip.setPixelColor(11 + segment, red, green, blue); //Segment D
  strip.show();
}
void four(int segment) {
  strip.setPixelColor(15 + segment, red, green, blue); //Segment B
  strip.setPixelColor(16 + segment, red, green, blue); //Segment B
  strip.setPixelColor(17 + segment , red, green, blue); //Segment B
  strip.setPixelColor(18 + segment, red, green, blue); //Segment D
  strip.setPixelColor(19 + segment, red, green, blue); //Segment D
  strip.setPixelColor(20 + segment, red, green, blue); //Segment D
  strip.setPixelColor(3 + segment, red, green, blue); //Segment D
  strip.setPixelColor(4 + segment, red, green, blue); //Segment D
  strip.setPixelColor(5 + segment, red, green, blue); //Segment D
  strip.setPixelColor(6 + segment, red, green, blue); //Segment D
  strip.setPixelColor(7 + segment, red, green, blue); //Segment D
  strip.setPixelColor(8 + segment, red, green, blue); //Segment D
  strip.show();
}
void five(int segment) {
  strip.setPixelColor(0 + segment, red, green, blue); //Segment B
  strip.setPixelColor(1 + segment, red, green, blue); //Segment B
  strip.setPixelColor(2 + segment , red, green, blue); //Segment B
  strip.setPixelColor(15 + segment, red, green, blue); //Segment D
  strip.setPixelColor(16 + segment, red, green, blue); //Segment D
  strip.setPixelColor(17 + segment, red, green, blue); //Segment D
  strip.setPixelColor(18 + segment, red, green, blue); //Segment D
  strip.setPixelColor(19 + segment, red, green, blue); //Segment D
  strip.setPixelColor(20 + segment, red, green, blue); //Segment D
  strip.setPixelColor(6 + segment, red, green, blue); //Segment D
  strip.setPixelColor(7 + segment, red, green, blue); //Segment D
  strip.setPixelColor(8 + segment, red, green, blue); //Segment D
  strip.setPixelColor(9 + segment, red, green, blue); //Segment D
  strip.setPixelColor(10 + segment, red, green, blue); //Segment D
  strip.setPixelColor(11 + segment, red, green, blue); //Segment D
  strip.show();
}
void six(int segment) {
  strip.setPixelColor(0 + segment, red, green, blue); //Segment B
  strip.setPixelColor(1 + segment, red, green, blue); //Segment B
  strip.setPixelColor(2 + segment , red, green, blue); //Segment B
  strip.setPixelColor(15 + segment, red, green, blue); //Segment D
  strip.setPixelColor(16 + segment, red, green, blue); //Segment D
  strip.setPixelColor(17 + segment, red, green, blue); //Segment D
  strip.setPixelColor(12 + segment, red, green, blue); //Segment D
  strip.setPixelColor(13 + segment, red, green, blue); //Segment D
  strip.setPixelColor(14 + segment, red, green, blue); //Segment D
  strip.setPixelColor(6 + segment, red, green, blue); //Segment D
  strip.setPixelColor(7 + segment, red, green, blue); //Segment D
  strip.setPixelColor(8 + segment, red, green, blue); //Segment D
  strip.setPixelColor(9 + segment, red, green, blue); //Segment D
  strip.setPixelColor(10 + segment, red, green, blue); //Segment D
  strip.setPixelColor(11 + segment, red, green, blue); //Segment D
  strip.setPixelColor(18 + segment, red, green, blue); //Segment D
  strip.setPixelColor(19 + segment, red, green, blue); //Segment D
  strip.setPixelColor(20 + segment, red, green, blue); //Segment D
  strip.show();
}
void seven(int segment) {
  strip.setPixelColor(0 + segment, red, green, blue); //Segment B
  strip.setPixelColor(1 + segment, red, green, blue); //Segment B
  strip.setPixelColor(2 + segment , red, green, blue); //Segment B
  strip.setPixelColor(3 + segment, red, green, blue); //Segment D
  strip.setPixelColor(4 + segment, red, green, blue); //Segment D
  strip.setPixelColor(5 + segment, red, green, blue); //Segment D
  strip.setPixelColor(6 + segment, red, green, blue); //Segment D
  strip.setPixelColor(7 + segment, red, green, blue); //Segment D
  strip.setPixelColor(8 + segment, red, green, blue); //Segment D
  strip.show();
}
void eight(int segment) {
  strip.setPixelColor(0 + segment, red, green, blue); //Segment B
  strip.setPixelColor(1 + segment, red, green, blue); //Segment B
  strip.setPixelColor(2 + segment , red, green, blue); //Segment B
  strip.setPixelColor(3 + segment, red, green, blue); //Segment B
  strip.setPixelColor(4 + segment, red, green, blue); //Segment B
  strip.setPixelColor(5 + segment , red, green, blue); //Segment B
  strip.setPixelColor(15 + segment, red, green, blue); //Segment D
  strip.setPixelColor(16 + segment, red, green, blue); //Segment D
  strip.setPixelColor(17 + segment, red, green, blue); //Segment D
  strip.setPixelColor(12 + segment, red, green, blue); //Segment D
  strip.setPixelColor(13 + segment, red, green, blue); //Segment D
  strip.setPixelColor(14 + segment, red, green, blue); //Segment D
  strip.setPixelColor(6 + segment, red, green, blue); //Segment D
  strip.setPixelColor(7 + segment, red, green, blue); //Segment D
  strip.setPixelColor(8 + segment, red, green, blue); //Segment D
  strip.setPixelColor(9 + segment, red, green, blue); //Segment D
  strip.setPixelColor(10 + segment, red, green, blue); //Segment D
  strip.setPixelColor(11 + segment, red, green, blue); //Segment D
  strip.setPixelColor(18 + segment, red, green, blue); //Segment D
  strip.setPixelColor(19 + segment, red, green, blue); //Segment D
  strip.setPixelColor(20 + segment, red, green, blue); //Segment D
  strip.show();
}
void nine(int segment) {
  strip.setPixelColor(0 + segment, red, green, blue); //Segment B
  strip.setPixelColor(1 + segment, red, green, blue); //Segment B
  strip.setPixelColor(2 + segment , red, green, blue); //Segment B
  strip.setPixelColor(3 + segment, red, green, blue); //Segment B
  strip.setPixelColor(4 + segment, red, green, blue); //Segment B
  strip.setPixelColor(5 + segment , red, green, blue); //Segment B
  strip.setPixelColor(15 + segment, red, green, blue); //Segment D
  strip.setPixelColor(16 + segment, red, green, blue); //Segment D
  strip.setPixelColor(17 + segment, red, green, blue); //Segment D
  strip.setPixelColor(6 + segment, red, green, blue); //Segment D
  strip.setPixelColor(7 + segment, red, green, blue); //Segment D
  strip.setPixelColor(8 + segment, red, green, blue); //Segment D
  strip.setPixelColor(18 + segment, red, green, blue); //Segment D
  strip.setPixelColor(19 + segment, red, green, blue); //Segment D
  strip.setPixelColor(20 + segment, red, green, blue); //Segment D
  strip.show();
}
