void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  for(int i = 0; i < 101; i+=2){
    Serial.println(i);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
