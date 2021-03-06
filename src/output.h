#ifndef _OUTPUT_H
#define _OUTPUT_H

#include <Adafruit_SSD1306.h>

class Output {
public:
  Output();
  virtual ~Output() {}
  void println(String message);
  void print(String message);
  void splashScreen();
  Adafruit_SSD1306 display = Adafruit_SSD1306(D0);
};

extern Output output;

#endif
