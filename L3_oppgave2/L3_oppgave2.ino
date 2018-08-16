// Oppgave 2
#define LEDPIN  2 
#define BUTTPIN 4


void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUTTPIN, INPUT);
}

void loop() {
  int readval = digitalRead(BUTTPIN);
  digitalWrite(LEDPIN, readval);

  delay(100);
}
