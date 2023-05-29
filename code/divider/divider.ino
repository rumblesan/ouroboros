#define DIV_CV_PIN A0

#define SIG_IN_PIN 1
#define RESET_PIN 10

#define MIN_PULSE_DIVIDE 1
#define MAX_PULSE_DIVIDE 64
float DIVIDE_DELTA = float(MAX_PULSE_DIVIDE - MIN_PULSE_DIVIDE);

int mainPulseCount = 0;
int mainPulseLimit = 1;

#define OUTPUT_COUNT 7
int divOutputPins[OUTPUT_COUNT] = {9, 7, 8, 2, 6, 3, 5};
int divCounts[OUTPUT_COUNT] = {0, 0, 0, 0, 0, 0, 0};
int divLimits[OUTPUT_COUNT] = {2, 3, 4, 5, 6, 7, 8};


int pulseCheck = 1;
int resetCheck = 1;


void setup()
{
  for (int i = 0; i < OUTPUT_COUNT; i++) {
    pinMode(divOutputPins[i], OUTPUT);
  }

  pinMode(SIG_IN_PIN, INPUT_PULLUP);
  pinMode(RESET_PIN, INPUT_PULLUP);
}

void loop()
{
  checkDivisionCount();
  checkPulse();
  checkReset();
}

void checkDivisionCount() {
  float divCV = float(analogRead(DIV_CV_PIN)) / 1023.0;
  mainPulseLimit = MIN_PULSE_DIVIDE + int(DIVIDE_DELTA * divCV);
}

void checkReset() {
  int resetInput = digitalRead(RESET_PIN);
  if (resetInput == LOW) {
    resetCheck = 0;
  } else if (resetCheck == 0 && resetInput == HIGH) {
    resetCheck = 1;
    for (int i = 0; i < OUTPUT_COUNT; i++) {
    clearSubCount(i);
    }
  }
}

void checkPulse() {
  int pulseInput = digitalRead(SIG_IN_PIN);
  if (pulseInput == LOW) {
    pulseCheck = 0;
  } else if (pulseCheck == 0 && pulseInput == HIGH) {
    pulseCheck = 1;
    incrementMainCount();
  }
}

void incrementMainCount() {
  mainPulseCount += 1;
  if (mainPulseCount < mainPulseLimit) { return; }
  mainPulseCount = 0;

  for (int i = 0; i < OUTPUT_COUNT; i++) {
   incrementSubCount(i);
  }
}

void incrementSubCount(int idx) {
  divCounts[idx] += 1;
  if (divCounts[idx] >= divLimits[idx]) {
    divCounts[idx] = 0;
    digitalWrite(divOutputPins[idx], HIGH);
  } else {
    digitalWrite(divOutputPins[idx], LOW);
  }
}

void clearSubCount(int idx) {
  divCounts[idx] = 0;
  digitalWrite(divOutputPins[idx], LOW);
}

