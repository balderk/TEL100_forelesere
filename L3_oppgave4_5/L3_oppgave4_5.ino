// Oppgave 4_5
#define NUM_LEDS 6
#define MAXVAL 50
const int PWMLEDS[] = {3, 5, 6, 9, 10, 11};

int led[NUM_LEDS];
int potPin = A0;

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < NUM_LEDS; i++) {
    led[i] = PWMLEDS[i];
    pinMode(PWMLEDS[i], OUTPUT);
  }
}

void loop() {
  int val = analogRead(potPin);
  int frac = 1023 / NUM_LEDS;
  Serial.print("\n(i, val): ");
  Serial.print(val);
  Serial.print(",\t");
  for (int i = 0; i < NUM_LEDS; i++) {
    uint8_t state = 0;
    if (val > (i + 1)*frac) {
      state = MAXVAL;
    } else if (val < i * frac) {
      state = 0;
    } else {
      state = map(val, i * frac, (i + 1) * frac, 0, MAXVAL);
    }
    Serial.print(i);
    Serial.print(",\t");
    Serial.print(state);
    Serial.print(",\t");
    analogWrite(led[i], state);
  }
}

