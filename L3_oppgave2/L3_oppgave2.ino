// Oppgave 2
#define LEDPIN  2 
#define BUTTPIN 4


void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUTTPIN, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  int readval = digitalRead(BUTTPIN);
  digitalWrite(LEDPIN, readval);

  delay(10);
  // put your main code here, to run repeatedly:

}
