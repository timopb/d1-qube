#ifndef _PAGES_H
#define _PAGES_H

#include "PageTemplate.h"
#include "..\Performer.h"
#include <ESP.h>
#include <ESP8266WebServer.h>

class Pages : PageTemplate
{
  public:
    String Index();
    String Info(Performer *performer);
    String NotFound(ESP8266WebServer *server);
};

#endif
