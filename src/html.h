#ifndef _HTML_H
#define _HTML_H

#include <ESP8266WebServer.h>

String Page_Index();
String Page_Memory();
String Page_NotFound(ESP8266WebServer *server);

#endif
