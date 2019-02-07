#ifndef _HTTPD_H
#define _HTTPD_H

#include <ESP8266WebServer.h>

#include "cube.h"
#include "performer.h"
#include "output.h"
#include "Web\Pages.h"

class HTTPD {
public:
  HTTPD(Cube *cubeRef, Performer *performerRef);
  virtual ~HTTPD() {}
  void begin();
  void tick();
private:
  ESP8266WebServer *server;
};

#endif
