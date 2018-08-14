void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  print_hello(5);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void print_hello(int n){
  for (int i = 0; i < n; i++){
    Serial.println("Hello!");
  }
}

