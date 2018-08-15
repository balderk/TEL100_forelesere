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
  int n_leds = map(val, 0, 1023, 0, NUM_LEDS);
  Serial.print("\n(i, val): ");
  for (int i = 0; i < NUM_LEDS; i++) {
    uint8_t state = (n_leds >= i);
    Serial.print(i);
    Serial.print(",\t");
    Serial.print(state);
    Serial.print(",\t");
    digitalWrite(led[i], state);
  }
  delay(10);
}

