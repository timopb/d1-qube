#include <Wire.h>  // Include Wire if you're using I2C
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <WiFiManager.h>

#include "defs.h"
#include "output.h"
#include "html.h"
#include "ota.h"
#include "cube.h"
#include "httpd.h"
#include "performer.h"

#define DNS_NAME "d1-mini-pro"

bool rotateCube = false;

WiFiManager wifiManager;
MDNSResponder mdns;
OTA ota;
Cube cube;
HTTPD httpd;

Performer performer;

void setup(){

#ifdef CPU_SPEED
  system_update_cpu_freq(CPU_SPEED);
#endif

  output.print("Wifi....");
  wifiManager.autoConnect();
  output.println("Ok");

  output.print("mDNS....");
  if (!mdns.begin(DNS_NAME, WiFi.localIP())) {
    output.println("Error!");
  } else {
    output.println("Ok");
  }

  output.print("HTTPD...");
  httpd.begin(&cube);
  output.println("Ok");

  output.print("OTA.....");
  ota.begin();
  output.println("Ok\n");

  output.splashScreen();
}

void loop(){
  ota.tick();
  httpd.tick();
  cube.tick();
  performer.tick();
}
