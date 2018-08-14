// Oppgave 6
void setup() {
  Serial.begin(115200);
  print_word(3, "TEL100 er det beste emnet på NMBU!!");
}

void loop() {

}

void print_word(int n, String Word){
  for (int i = 0; i < n; i++){
    Serial.println(Word);
  }
}









