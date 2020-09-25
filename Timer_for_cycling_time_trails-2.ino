#include <Adafruit_NeoPixel.h>
#include <TimerOne.h>
#define PIN 8
int stripLength = 88;
byte red = 94;
byte green = 21;
byte blue = 89;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(stripLength, PIN, NEO_GRB + NEO_KHZ800);

int button1Pin = 0;
int button2Pin = 1;

const int buzzerPin =  2;

const int sensor = 3;
int sensorVal = 0;
boolean sensorState = true;

const int motorPin1 = 9;
const int motorPin2 = 10;
const int motorPin3 = 11;
const int motorPin4 = 12;
int motorSpeed = 1200;
int motorCounter = 0;
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

int button1State = 0;
int button2State = 0;
int lastButton1State = 0;
int lastButton2State = 0;
boolean state = false;

long lastTimeMillis;
long currentTimeMillis;
const long timeSeconds = 0;
int countdownTime = 6000;
int countUpTime = 0;

int D1 = 0; //variable for single seconds up to 9
int D2 = 0; //variable for 10s of seconds up to 5
int D3 = 0; //variable for single min up to 9
int D4 = 0; //variable for 10s of min up to 5
int Buzzer = 0;

void setup() {
  strip.begin();
  Timer1.initialize(10000); //TimerOne stuff: triggers interrupt ever 250e3us (.25s)
  Timer1.attachInterrupt(decrement); //More TimerOne stuff
  pinMode(buzzerPin, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(sensor, INPUT);
}
void decrement() {
  if (state == true) {
    countdownTime--;
  }
}
void loop() {
  sensorVal = digitalRead(sensor);

  button1State = digitalRead(button1Pin);
  if (button1State != lastButton1State) {
    if (button1State == LOW) {
      reset();
      state = !state;
    }
  }
  lastButton1State = button1State;

  button2State = digitalRead(button2Pin);
  if (button2State != lastButton2State) {
    if (button2State == LOW) {
      countdownTime = 6000;
      D1 = 0;
      D2 = 0;
      D3 = 0;
      D4 = 0;
      reset();
      state = false;
    }
  }
  lastButton2State = button2State;

  if (state == true)
  {
    if (countdownTime <= 3000 && countdownTime >= 2901 && Buzzer == 0){
      tone(buzzerPin, 5000, 10);
      Buzzer++;
    }
    if (countdownTime <= 1000 && countdownTime >= 901 && Buzzer == 1) {
      tone(buzzerPin, 5000, 10);
      Buzzer++;
    }
    if (countdownTime <= 500 && countdownTime >= 401 && Buzzer == 2) {
      tone(buzzerPin, 5000, 10);
      Buzzer++;
    }
    if (countdownTime <= 400 && countdownTime >= 301 && Buzzer == 3) {
      tone(buzzerPin, 5000, 10);
      Buzzer++;
    }
    if (countdownTime <= 300 && countdownTime >= 201 && Buzzer == 4) {
      tone(buzzerPin, 5000, 10);
      Buzzer++;
    }
    if (countdownTime <= 200 && countdownTime >= 101 && Buzzer == 5) {
      tone(buzzerPin, 5000, 10);
      Buzzer++;
    }
    if (countdownTime <= 100 && countdownTime >= 1 && Buzzer == 6) {
      tone(buzzerPin, 5000, 10);
      Buzzer++;
    }
    if (countdownTime <= 0 && Buzzer == 7)
    {
      tone(buzzerPin, 5000, 50);
      Buzzer++;
    }
    D1 = (countdownTime % 10);
    D2 = ((countdownTime % 100) / 10);
    D3 = ((countdownTime % 1000) / 100);
    D4 = ((countdownTime / 1000));

    if (countdownTime <= 0 && motorCounter < 50) {
      anticlockwise();
      motorCounter++;
    }
    if (countdownTime <= 0) {
      if (sensorVal == HIGH) {
        state = false;
      }
      countUpTime = countdownTime * -1;
      D1 = (countUpTime % 10);
      D2 = ((countUpTime % 100) / 10);
      D3 = ((countUpTime % 1000) / 100);
      D4 = ((countUpTime / 1000));
    }
  }
  displayNumbers();

  if (state == false) {
    displayNumbers();
  }
}
void displayNumbers()
{
  reset();
  displayDecimalPoint();
  pickNumber(D4, 0);
  pickNumber(D3, 21);
  pickNumber(D2, 42);
  pickNumber(D1, 63);
}
void anticlockwise()
{
  for (int i = 0; i < 8; i++)
  {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

void setOutput(int out)
{
  digitalWrite(motorPin1, bitRead(lookup[out], 0));
  digitalWrite(motorPin2, bitRead(lookup[out], 1));
  digitalWrite(motorPin3, bitRead(lookup[out], 2));
  digitalWrite(motorPin4, bitRead(lookup[out], 3));
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
void displayDecimalPoint() {
  strip.setPixelColor(84, red, green, blue); //Segment B
  strip.setPixelColor(87, red, green, blue); //Segment B
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
