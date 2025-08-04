#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define trigPin 6
#define echoPin 7
#define buzzerPin 8
#define servoPin 9

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  myServo.attach(servoPin);
  myServo.write(0); // Start in closed position

  Serial.begin(9600);

  // OLED init
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED not found"));
    while (true); // Stop if OLED not found
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Touchless Door Ready");
  display.display();
  delay(1500);
}

void loop() {
  long duration;
  int distance;

  // Trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Display on OLED
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.print("Distance: ");
  display.print(distance);
  display.println(" cm");

  if (distance > 0 && distance < 15) {
    display.setCursor(0, 20);
    display.println("Person Detected!");
    myServo.write(45);
    digitalWrite(buzzerPin, HIGH);
    display.display();
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(3000);
    myServo.write(0);
  } else {
    display.setCursor(0, 20);
    display.println("No one nearby");
    display.display();
  }

  delay(300);
}
