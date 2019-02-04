#include <Arduino.h>
#include "defs.h"
#include "performer.h"

Performer::Performer() {
  tickcount = 0;
  tps = 0;
  beat = millis();
}

void Performer::tick() {
  #ifdef _DEBUG
    tickcount++;
    if (millis() > beat + 1000) {
      beat = millis();
      tps = tickcount;
      tickcount = 0;
      Serial.print("Ticks per second: " + String(tps) + "        \r");
    }
  #endif
}
