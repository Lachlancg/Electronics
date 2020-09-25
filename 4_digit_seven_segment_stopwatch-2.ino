
int pinA = 2; //pin 11 on display
int pinB = 3; //pin 7 on display
int pinC = 4; //pin 4 on display
int pinD = 5; //pin 2 on display
int pinE = 6; //pin 1 on display
int pinF = 7; //pin 10 on display
int pinG = 8; //pin 5 on display
const int D1 = 9; //pin 12 on display
const int D2 = 10; //pin 9 on display
const int D3 = 11; //pin 8 on display
const int D4 = 12; //pin 6 on display

int button1Pin = 0;
int button2Pin = 1;

int button1State = 0;
int button2State = 0;
int lastButton1State = 0;
int lastButton2State = 0;
boolean state = false;

int currentNum = 0; // current number on display
long counter = 0;

void setup() {
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  Serial.begin(9600);
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
      counter = 0;
      state = false;
      reset();
      delay(125);
    }
  }
  lastButton2State = button2State;

  if (state == true)
  {
    counter++;
  }
  reset();
  pickDigit(0);
  pickNumber((counter / 10000) % 6);
  delayMicroseconds(70);
  reset();
  pickDigit(1);
  pickNumber((counter / 1000) % 10);
  delayMicroseconds(70);
  reset();
  pickDigit(2);
  pickNumber((counter / 100) % 10);
  delayMicroseconds(70);
  reset();
  pickDigit(3);
  pickNumber((counter / 10 / 5) % 10);
  delayMicroseconds(70);
}

void pickDigit(int digit)
{
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);

  switch (digit)
  {
    case 0:
      digitalWrite(D1, LOW);//Light d1 up
      break;
    case 1:
      digitalWrite(D2, LOW); //Light d2 up
      break;
    case 2:
      digitalWrite(D3, LOW); //Light d3 up
      break;
    case 3:
      digitalWrite(D4, LOW); //Light d4 up
      break;
  }
}

void pickNumber(int num)
{
  switch (num)
  {
    default:
      zero();
      break;
    case 1:
      one();
      break;
    case 2:
      two();
      break;
    case 3:
      three();
      break;
    case 4:
      four();
      break;
    case 5:
      five();
      break;
    case 6:
      six();
      break;
    case 7:
      seven();
      break;
    case 8:
      eight();
      break;
    case 9:
      nine();
      break;
  }
}
void reset()
{
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void zero()
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}
void one()
{
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}
void two()
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}
void three()
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}
void four()
{
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
void five()
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
void six()
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
void seven()
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}
void eight()
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
void nine()
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
