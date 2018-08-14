// Oppgave 7
#define UP_TO_VAL 100

void setup() {
  Serial.begin(115200);
  uint32_t start = millis();
  for (int i = 2; i < UP_TO_VAL; i++) {
    int check = is_prime(i);
    Serial.print(i);
    Serial.print(": ");

    if (check == 1) {
      Serial.println("primtall");
    } else {
      Serial.println("ikke primtall");
    }
  }
  Serial.print("\nIt took: ");
  Serial.print(millis() - start);
  Serial.println("ms to calculate");
}

void loop() {
}


int is_prime(int number) {
  if (number < 2) {
    return (0);
  }
  int check = 1;
  float lim = sqrt(number);
  for (int j = 2; j < lim; j++) {
    if (number % j == 0) {
      check = 0;
      return (check);
    }
  }
  return (check);
}

