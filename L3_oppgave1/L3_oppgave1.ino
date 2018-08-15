// Oppgave 4_5
#define LEDPIN 2
#define POTPIN A0
int ledval = 0x00;
void setup() {
  Serial.begin(115200);
  pinMode(POTPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);

}

void loop() {
  int val = analogRead(POTPIN);
  int delayval = map(val, 0, 1023, 5, 100);
  Serial.print("\n(i, val): ");
  Serial.print(val);
  Serial.print("\n");

  digitalWrite(LEDPIN, ledval);
  ledval ^= 0x01;
  delay(delayval);
}

