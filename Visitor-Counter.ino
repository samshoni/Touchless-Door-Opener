#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pins
#define ENTRY_SENSOR 2
#define EXIT_SENSOR 3
#define BUZZER 8

int count = 0;
bool entryDetected = false;
bool exitDetected = false;

void setup() {
  pinMode(ENTRY_SENSOR, INPUT);
  pinMode(EXIT_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED failed"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 10);
  display.print("Visitor:");
  display.setCursor(0, 35);
  display.print(count);
  display.display();
}

void loop() {
  int entryState = digitalRead(ENTRY_SENSOR);
  int exitState = digitalRead(EXIT_SENSOR);

  // Entry detection
  if (entryState == LOW && !entryDetected) {
    entryDetected = true;
  }
  if (entryState == HIGH && entryDetected) {
    count++;
    buzz();
    updateDisplay();
    entryDetected = false;
  }

  // Exit detection
  if (exitState == LOW && !exitDetected) {
    exitDetected = true;
  }
  if (exitState == HIGH && exitDetected) {
    if (count > 0) count--;
    buzz();
    updateDisplay();
    exitDetected = false;
  }

  delay(50);
}

void buzz() {
  digitalWrite(BUZZER, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);
}

void updateDisplay() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 10);
  display.print("Visitor:");
  display.setCursor(0, 35);
  display.print(count);
  display.display();
}
