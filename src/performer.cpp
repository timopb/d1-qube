#include <Arduino.h>
#include "defs.h"
#include "performer.h"

const unsigned long oneSecond = 1000;

Performer::Performer() {
  tickcount = 0;
  tps = 0;
  beat = millis();
}

void Performer::tick() {
  #ifdef _DEBUG
    tickcount++;
    if (millis() > beat + oneSecond) {
      beat = millis();
      tps = tickcount;
      tickcount = 0;
      Serial.print("Ticks per second: " + String(tps) + "        \r");
    }
  #endif
}
