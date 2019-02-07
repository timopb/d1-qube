#include <Wire.h>  // Include Wire if you're using I2C
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <WiFiManager.h>

#include "defs.h"
#include "input.h"
#include "output.h"
#include "ota.h"
#include "cube.h"
#include "httpd.h"
#include "performer.h"

bool rotateCube = false;

WiFiManager wifiManager;
MDNSResponder mdns;

OTA *ota = new OTA();
Cube *cube = new Cube();
Performer *performer = new Performer();
HTTPD *httpd = new HTTPD(cube, performer);
Input *input = new Input(cube);

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

  output.splashScreen();
}

void loop(){
  ota->tick();
  httpd->tick();
  input->tick();
  cube->tick();
  performer->tick();
}
