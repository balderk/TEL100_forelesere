#include <Servo.h>

#define INCREMENTVAL 1

const int servoPin = 3;
const int button1 = 7;
const int button2 = 8;


Servo myServo;

void setup() {
  Serial.begin(115200);

  myServo.attach(servoPin);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  static int servoVal = 0;
  int buttonval1 = digitalRead(button1);
  int buttonval2 = digitalRead(button2);

  servoVal += buttonval1 * INCREMENTVAL -
              buttonval2 * INCREMENTVAL;

  if (servoVal < 0) {
    servoVal = 0;
  } else if (servoVal > 180) {
    servoVal = 180;
  }

  myServo.write(servoVal);

  Serial.print("servo value: ");
  Serial.print(servoVal);

  Serial.print("\tbutton1 value: ");
  Serial.print(buttonval1);
  Serial.print("\tbutton2 value: ");
  Serial.println(buttonval2);

  delay(15);
}
