void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  print_range(70, 3);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void print_range(int num, int jump){
  for(int i = 0; i <= num; i+=jump){
    Serial.println(i);
  }
}

