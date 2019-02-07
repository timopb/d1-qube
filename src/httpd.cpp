#include "httpd.h"
 
HTTPD::HTTPD(Cube *cubeRef, Performer *performerRef) {
  server = new ESP8266WebServer(80);
  Pages pages;

  server->on("/", [this, &pages]() {
    server->send(200, "text/html", pages.Index());
  });
  server->on("/info", [this, &pages, performerRef]() {
    server->send(200, "text/html", pages.Info(performerRef));
  });
  server->on("/api/rotate", [this, cubeRef](){
    cubeRef->rotateCube = true;
    server->send(200, "application/json", "{\"result\": \"rotating\"}");
  });
  server->on("/api/stop", [this, cubeRef]() {
    cubeRef->rotateCube = false;
    server->send(200, "application/json", "{\"result\": \"stopped\"}");
  });
  server->on("/api/clear", [this]() {
    output.display.clearDisplay();
    output.display.display();
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
  server->onNotFound([this, &pages]() {
    server->send(404, "text/html", pages.NotFound(server));
  });
  server->begin();
}

void HTTPD::tick() {
  server->handleClient();
}
