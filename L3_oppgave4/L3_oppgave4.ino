// Oppgave 4
#define NUM_LEDS 6
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
  //int n_leds = map(val, 0, 1023, 0, NUM_LEDS);
  int frac = 1023 / NUM_LEDS;
  Serial.print("\n(i, val): ");
  for (int i = 0; i < NUM_LEDS; i++) {
    uint8_t state = 0;
    if (val > (i + 1)*frac) {
      state = 255;
    } else if (val < i * frac) {
      state = 0;
    } else {
      state = map(val, i * frac, (i + 1) * frac, 0, 255);
    }
    Serial.print(i);
    Serial.print(",\t");
    Serial.print(state);
    Serial.print(",\t");
    analogWrite(led[i], state);
  }
  delay(10);
}

