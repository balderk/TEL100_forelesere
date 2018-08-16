/*
   Simulates traffic light with cars and pedestrians
*/

#define WAIT_PED 5000    // Defines minimum crossing time for pedestrian
#define WAIT_CAR 8000    // Same for cars

#define PED_BLINKS 20    // How many blinks before green light goes to red

#define SWITCH_TIME 2000  // Time on light switch

int carPin[] = {3, 4, 5}; // red, yellow, green
int pedPin[] = {6, 7, 8}; // red, green, and waiting light (pedestrian)
int btnPin = 2;           // button pin


int carGreen = 1;         // True if cars have green light
int pedGreen = 0;         // True if pedestrians have green light

volatile int pedWaiting = 0;       // True if a pedestrian has pushed the button

void setup() {
  pinMode(btnPin, INPUT);

  for (int i = 0; i < 3; i++) {
    pinMode(carPin[i], OUTPUT);
    pinMode(pedPin[i], OUTPUT);
  }

  digitalWrite(carPin[2], HIGH);  // Starts with green light for car, and red for pedestrians
  digitalWrite(pedPin[0], HIGH);

  // Attach interrupt to button when pressed
  attachInterrupt(digitalPinToInterrupt(btnPin), togglePed, RISING);
}

void loop() {
  if (pedWaiting) {
    switchCarLight();
    switchPedLight();
    switchCarLight();
  }
}

void switchCarLight() {
  if (carGreen) {
    digitalWrite(carPin[2], LOW);
    digitalWrite(carPin[1], HIGH);
    delay(SWITCH_TIME);
    digitalWrite(carPin[1], LOW);
    digitalWrite(carPin[0], HIGH);
    delay(SWITCH_TIME);
  }
  else {
    digitalWrite(carPin[0], LOW);
    digitalWrite(carPin[1], HIGH);
    delay(SWITCH_TIME);
    digitalWrite(carPin[1], LOW);
    digitalWrite(carPin[2], HIGH);
    delay(WAIT_CAR);
  }
  carGreen = !carGreen;
}

void switchPedLight() {
  digitalWrite(pedPin[2], LOW);
  digitalWrite(pedPin[1], HIGH);
  digitalWrite(pedPin[0], LOW);
  delay(WAIT_PED);

  for (int i = 0; i < PED_BLINKS; i++) {
    digitalWrite(pedPin[1], LOW);
    delay(100);
    digitalWrite(pedPin[1], HIGH);
    delay(100);
  }
  digitalWrite(pedPin[1], LOW);
  digitalWrite(pedPin[0], HIGH);

  // Light is red, and pedestrians can push the button
  pedWaiting = 0;
  delay(SWITCH_TIME);
}

void togglePed() {
  if (!pedWaiting) {                // Toggle only if pedestrian crossing is complete
    digitalWrite(pedPin[2], HIGH);  // Turn on waiting light
    pedWaiting = 1;
  }
}

