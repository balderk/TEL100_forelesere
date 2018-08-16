// Oppgave 4
/*
   Connect a button with a pull down resistor to port 4 on the arduino

   Connect a LED to port number 8, 9 and 10
*/
#define BUTTPIN 4

#define NUM_LEDS 3
const int ledpins[NUM_LEDS] = {8, 9, 10};

int current_index = 0;
int current_LED;
void setup() {
  
  for (int i = 0; i < NUM_LEDS; i++) {
    int pin = ledpins[i];
    pinMode(pin, OUTPUT);
  }
  
  pinMode(BUTTPIN, INPUT);

  current_LED = ledpins[current_index];
  digitalWrite(current_LED, HIGH);
}

void loop() {
  int readval = digitalRead(BUTTPIN);

  if (readval == 1) {
    digitalWrite(current_LED, LOW);

    current_index++;
    current_index %= NUM_LEDS;

    current_LED = ledpins[current_index];
    digitalWrite(current_LED, HIGH);
  }
  
  delay(150);
}
