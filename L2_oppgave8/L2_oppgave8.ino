// Oppgave 8
void setup() {
  Serial.begin(115200);
}

void loop() {
  uint32_t num = get_number();
  Serial.print("Number given: ");
  Serial.println(num);

  uint32_t start = millis();
  uint32_t check = is_prime(num);

  Serial.print(num);
  if (check == 1) {
    Serial.println(" is a prime");
  } else {
    Serial.println(" is not a prime");
  }

  Serial.print("It took ");
  Serial.print(millis() - start);
  Serial.println("ms to calculate");
  Serial.println();
}


uint32_t get_number() {
  while (!Serial.available());
  byte val;
  int8_t BUFF[50], index = 0;

  do {
    if (Serial.available()) {
      val = Serial.read();
      if ((val >= '0') && (val <= '9')) {
        int tempnum = val - '0';
        BUFF[index++] = tempnum;
      }
    }
  } while (val != ' ');

  uint32_t num = 0, temp = 1;
  for (index--; index >= 0; index--) {
    num += BUFF[index] * temp;
    temp *= 10;
  }
  return(num);
}

uint32_t is_prime(uint32_t number) {
  if(number < 2){
    return(0);
  }
  uint32_t check = 1;
  float lim = sqrt(number);
  for (uint32_t j = 2; j < number; j++) {
    if (number % j == 0) {
      check = 0;
      return(check);
    }
  }
  return(check);
}

