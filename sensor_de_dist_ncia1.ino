#include <LiquidCrystal.h>
#include <Ultrasonic.h>

const int trigPin = 2;
const int echoPin = 3;
Ultrasonic ultrasonic(trigPin, echoPin); 
const int buzzer = 12;
LiquidCrystal lcd(7, 8, 9, 10, 11, 4);

void setup() {
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  long distance = ultrasonic.distanceRead();
  if (distance <= 20) {
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(500);
  } else {
    digitalWrite(buzzer, LOW);
  }
  lcd.clear();
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");
  delay(400);
}
