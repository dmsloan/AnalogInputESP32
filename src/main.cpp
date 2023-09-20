#include <Arduino.h>

// Potentiometer is connected to GPIO 34 (Analog ADC1_CH6) 
const int potPin = 34;

// variable for storing the potentiometer value
int potValue = 0;

// variable for storing the mapped potentiometer voltage
int potVoltage = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
    // Reading potentiometer value
  potValue = analogRead(potPin);
  potVoltage = map(potValue, 0, 4096, 0, 3300);
  Serial.print("\033[32m"); //Set terminal text color to green 32. Standard escape codes are prefixed with Escape: Octal: \033
  Serial.print(potValue);
  Serial.print(" Pot value\033[0m\n"); //Set terminal color back to default and insert a carrage return.
//  Serial.println("\033[1;32mbold green text\033[0m plain text\n");

  Serial.print("\033[1;31m"); //Set terminal text color to bold 1 red 31
  Serial.print(potVoltage);
  Serial.print(" Pot voltage\033[0m\n\n\a"); //Set terminal color back to white and insert a carrage return. \a is the Terminal bell. It works with Putty but not with the terminal built into PlatformIO
//Serial.println(); Not needed because of the /n above

  delay(500);
}

