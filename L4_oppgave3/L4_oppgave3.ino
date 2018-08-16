// Oppgave 3
/*
   Connect a button with a pull down resistor to port 4 on the arduino

   Connect a LED to port number 8
*/
#define BUTTPIN 4

#define NUM_LEDS 3
const int ledpin = 8;

bool light_status = HIGH;
void setup() {
  pinMode(ledpin, OUTPUT);
  pinMode(BUTTPIN, INPUT);

  digitalWrite(ledpin, light_status);
}

void loop() {
  int readval = digitalRead(BUTTPIN);

  if (readval == 1) {
    light_status = !light_status;
    digitalWrite(ledpin, light_status);
  }

  delay(150);
}
