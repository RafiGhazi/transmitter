#include <arduino.h>

const int BUTTON_PRESSED = LOW;
const int BUTTON_NOT_PRESSED = HIGH;

int ButtonX1State, ButtonX2State, ButtonY1State, ButtonY2State;

const int ButtonX1 = 2;
const int ButtonX2 = 3;
const int ButtonY1 = 4;
const int ButtonY2 = 5;
const int LEDX1 = A0;
const int LEDY1 = A1;

int x = 0;
int y = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ButtonX1, INPUT);
  pinMode(ButtonX2, INPUT);
  pinMode(ButtonY1, INPUT);
  pinMode(ButtonY2, INPUT);
  pinMode(LEDX1, OUTPUT);
  pinMode(LEDY1, OUTPUT);
}

void loop() {
  ButtonX1State = digitalRead(ButtonX1);
  ButtonX2State = digitalRead(ButtonX2);
  ButtonY1State = digitalRead(ButtonY1);
  ButtonY2State = digitalRead(ButtonY2);

  if (ButtonX1State == BUTTON_PRESSED) {
    x++;
  } else if (ButtonX2State == BUTTON_PRESSED) {
    x--;
    
  }

  if (ButtonY1State == BUTTON_PRESSED) {
    y++;
  } else if (ButtonY2State == BUTTON_PRESSED) {
    y--;
  }

  digitalWrite(LEDX1, (ButtonX1State == BUTTON_PRESSED || ButtonX2State == BUTTON_PRESSED) ? HIGH : LOW);
  digitalWrite(LEDY1, (ButtonY1State == BUTTON_PRESSED || ButtonY2State == BUTTON_PRESSED) ? HIGH : LOW);

 
  uint8_t checksum = ((x >> 8 ) & 0xFF) + (x & 0xFF) + ((y >> 8 ) & 0xFF) + (y & 0xFF);
  Serial.write((x >> 8 ) & 0xFF);
  Serial.write(x & 0xFF);
  Serial.write((y >> 8 ) & 0xFF);
  Serial.write(y & 0xFF);
  Serial.write(checksum);
  delay(50);
}


