#include <ESP8266WiFi.h>
#include "defs.h"
#include "output.h"

Output::Output() {
  display = new Adafruit_SSD1306(D0);
  display->begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display->clearDisplay();
  display->setTextSize(1);
  display->setCursor(0,0);
  display->setTextColor(BLACK, WHITE);
  display->println("= D1Mini =");
  display->setTextColor(WHITE);
  #ifdef _DEBUG
    Serial.begin(115200);
  #endif
}

void Output::println(String message) {
  #ifdef _DEBUG
    Serial.println(message);
  #endif
   display->println(message);
   display->display();
}

void Output::print(String message) {
  #ifdef _DEBUG
    Serial.print(message);
  #endif
   display->print(message);
   display->display();
}

void Output::splashScreen() {
  display->clearDisplay();
  display->setCursor(0, 0);
  display->println("D1 Ready!\n");
  display->print("IP: ");
  display->println(WiFi.localIP());
  display->display();
}

Output output;
