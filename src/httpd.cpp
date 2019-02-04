#include "html.h"
#include "output.h"
#include "httpd.h"

extern "C" {
  #include <user_interface.h>
}

HTTPD::HTTPD() {
  server = new ESP8266WebServer(80);
}

void HTTPD::begin(Cube *cube) {
  server->on("/", [this]() {
    server->send(200, "text/html", Page_Index());
  });
  server->on("/info", [this]() {
    server->send(200, "text/html", Page_Memory());
  });
  server->on("/api/rotate", [this, cube](){
    cube->rotateCube = true;
    server->send(200, "application/json", "{\"result\": \"rotating\"}");
  });
  server->on("/api/stop", [this, cube]() {
    cube->rotateCube = false;
    server->send(200, "application/json", "{\"result\": \"stopped\"}");
  });
  server->on("/api/clear", [this]() {
    output.display->clearDisplay();
    output.display->display();
    server->send(200, "application/json", "{\"result\": \"cleared\"}");
  });
  server->on("/api/cpuspeed/160", [this]() {
    system_update_cpu_freq(160);
    server->send(200, "application/json", "{\"result\": \"160\"}");
  });
  server->on("/api/cpuspeed/80", [this]() {
    system_update_cpu_freq(80);
    server->send(200, "application/json", "{\"result\": \"80\"}");
  });
  server->onNotFound([this]() {
    server->send(404, "text/html", Page_NotFound(server));
  });
  server->begin();
}

void HTTPD::tick() {
  server->handleClient();
}
