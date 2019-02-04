#ifndef _OTA_H
#define _OTA_H

#include <Arduino.h>

class OTA {
public:
  OTA() {};
  virtual ~OTA() {}
  void begin();
  void tick();
private:
  void bluescreen(String message);
};

#endif
