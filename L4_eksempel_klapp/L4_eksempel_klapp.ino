const int sensorPin = A0;

const int triggerval = 210;
const int timeLim = 200;

const int ledPin1 = 3;
const int ledPin2 = 8;

uint32_t lastTime;

void setup() {
  Serial.begin(115200);
  pinMode(sensorPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  lastTime = millis();
}

void loop() {
  static int ledVal = 0;
  int sensorVal = analogRead(sensorPin);
  Serial.print("0, 1023, \n");
  Serial.print(", ");
  Serial.println(sensorVal);
  if(sensorVal > triggerval && (millis()-lastTime)>timeLim){
    ledVal = !ledVal;
    lastTime = millis();
  }
  digitalWrite(ledPin1, ledVal);
  digitalWrite(ledPin2, !ledVal);
  delay(10);
}
