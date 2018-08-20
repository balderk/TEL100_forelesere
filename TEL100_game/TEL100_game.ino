int delayVal;
const int signalPin = 13;

const int scorePin11 = 12;
const int scorePin12 = 11;
const int scorePin21 = 10;
const int scorePin22 = 9;

const int playerButton1 = 7;
const int playerButton2 = 6;
const int resetButton = 2;

volatile uint8_t playerScore1 = 0;
volatile uint8_t playerScore2 = 0;

uint64_t tid;

void setup() {
  Serial.begin(9600);

  pinMode(scorePin11, OUTPUT);
  pinMode(scorePin12, OUTPUT);
  pinMode(scorePin21, OUTPUT);
  pinMode(scorePin22, OUTPUT);

  pinMode(playerButton1, INPUT);
  pinMode(playerButton2, INPUT);
  pinMode(resetButton, INPUT);

  attachInterrupt(digitalPinToInterrupt(resetButton), resetScore, RISING);
}

void loop() {
  while (playerScore1 < 3 && playerScore2 < 3) {
    delayVal = random(1000, 5000);
    tid = millis();
  }
  if (playerScore1 == 3){
    winner(scorePin11, scorePin12);
  } else {
    winner(scorePin21, scorePin22);
  }

}

void resetScore(void) {
  playerScore1 = 0;
  playerScore2 = 0;

  writeScore(playerScore1, scorePin11, scorePin12);
  writeScore(playerScore2, scorePin21, scorePin22);
}

void writeScore(uint8_t score1, int pin1, int pin2) {
  digitalWrite(pin1, score1 & 0b10);
  digitalWrite(pin2, score1 & 0b01);
}

void winner(int pin1, int pin2) {
  for (int i = 100; i < 1000; i += 100) {
    digitalWrite(pin1, 1);
    digitalWrite(pin2, 0);
    delay(i);
    digitalWrite(pin2, 1);
    digitalWrite(pin1, 0);
    delay(i);
  }
  resetScore();
}

