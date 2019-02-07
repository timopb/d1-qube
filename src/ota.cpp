#include <ArduinoOTA.h>
#include "defs.h"
#include "output.h"
#include "ota.h"

OTA::OTA() {
  ArduinoOTA.setPassword(OTA_PASSWORD);
  ArduinoOTA.onStart([]() {
  });
  ArduinoOTA.onEnd([]() {
    output.display->setCursor(4,40);
    output.println("Rebooting!");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    char pg[5];
    sprintf(pg, "%u%%\r", (progress / (total / 100)));
    output.display->clearDisplay();
    output.display->setCursor(0,0);
    output.display->setTextColor(BLACK, WHITE);
    output.display->println("OTA Update");
    output.display->setTextColor(WHITE);
    output.display->setCursor(20,20);
    output.println(pg);
#ifdef _DEBUG
    Serial.print(pg);
#endif
  });
  ArduinoOTA.onError([this](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) bluescreen("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) bluescreen("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) bluescreen("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) bluescreen("Receive Failed");
    else if (error == OTA_END_ERROR) bluescreen("End Failed");
  });
  ArduinoOTA.begin();
}

void OTA::bluescreen(String message){
  output.display->clearDisplay();
  output.display->setCursor(0,0);
  output.println(message);
}

void OTA::tick() {
  ArduinoOTA.handle();
}
