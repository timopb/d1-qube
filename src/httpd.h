#ifndef _HTTPD_H
#define _HTTPD_H

#include <ESP8266WebServer.h>
#include "cube.h"

class HTTPD {
public:
  HTTPD();
  virtual ~HTTPD() {}
  void begin(Cube *cubeRef);
  void tick();
private:
  ESP8266WebServer *server;
};

#endif
