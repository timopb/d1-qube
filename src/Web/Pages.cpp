
#include "Pages.h"

String readable_size(double size) {
  int i = 0;
  const char* units[] = {"B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
  while (size > 1024) {
      size /= 1024;
      i++;
  }
  char buf[10];
  dtostrf(size, 0, 0, buf);
  return String(buf) + " " + units[i];
}

String Pages::Index()
{
    Title = "D1 Mini";

    return this->PageBegin() +
           "<script>"
           "function call(message) {"
           "  var xhttp = new XMLHttpRequest();"
           "  xhttp.open(\"GET\", message, true);"
           "  xhttp.send();"
           "}"
           "</script>"
           "<div class=\"container\">" +
           this->NavBar() +
           "  <div class=\"jumbotron\">"
           "    <h1 class=\"display-3\">Spinning Cube</h1>"
           "    <p class=\"lead\">Press the buttons to control the rotation of the cube on the device</p>"
           "    <p>"
           "      <button onClick=\"call('/api/rotate')\" class=\"btn btn-lg btn-success\" href=\"#\" role=\"button\">Rotate cube</button>"
           "      <button onClick=\"call('/api/stop')\" class=\"btn btn-lg btn-danger\" href=\"#\" role=\"button\">Stop rotation</button>"
           "    </p>"
           "    <hr />"
           "    <p>"
           "      <button onClick=\"call('/api/cpuspeed/80')\" class=\"btn btn-lg btn-primary\" href=\"#\" role=\"button\">80 MHz</button>"
           "      <button onClick=\"call('/api/cpuspeed/160')\" class=\"btn btn-lg btn-primary\" href=\"#\" role=\"button\">160 MHz</button>"
           "   </p>"
           "  </div>" +
           this->PageFooter() +
           "</div>" +
           this->PageEnd();
}

String Pages::Info(Performer *performer)
{

    uint32_t realSize = ESP.getFlashChipRealSize();
    uint32_t ideSize = ESP.getFlashChipSize();
    FlashMode_t ideMode = ESP.getFlashChipMode();

    Title = "Info";

    String message =
        PageBegin() +
        "<div class=\"container\">" +
        NavBar() +
        "  <div class=\"table-responsive\">"
        "  <table class=\"table\">"
        "    <tr><td>CPU Speed</td><td>" + String(ESP.getCpuFreqMHz()) + " MHz</td></tr>"
        "    <tr><td>Loops per second</td><td>" + String(performer->tps) + "</td></tr>"
        "    <tr><td>Flash chip Id</td><td>" + String(ESP.getFlashChipId()) + "</td></tr>"
        "    <tr><td>Flash real size</td><td>" + readable_size(realSize) + "</td></tr>"
        "    <tr><td>Flash ide size</td><td>" + readable_size(ideSize) + "</td></tr>"
        "    <tr><td>Flash ide speed</td><td>" + String(ESP.getFlashChipSpeed() / 1000000) + " MHz</td></tr>"
        "    <tr><td>Flash ide mode</td><td>" + String(ideMode == FM_QIO ? "QIO" : ideMode == FM_QOUT ? "QOUT" : ideMode == FM_DIO ? "DIO" : ideMode == FM_DOUT ? "DOUT" : "UNKNOWN") + "</td></tr>"
        "    <tr><td>Sketch size</td><td>" + readable_size(ESP.getSketchSize()) + "</td></tr>"
        "    <tr><td>Free sketch space</td><td>" + readable_size(ESP.getFreeSketchSpace()) + "</td></tr>"
        "  </table>"
        "  </div>";

    if (ideSize != realSize)
    {
        message +=
            "  <div class=\"alert alert-danger\" role=\"alert\">"
            "    Flash chip configuration is wrong!"
            "  </div>";
    }
    else
    {
        message +=
            "  <div class=\"alert alert-success\" role=\"alert\">"
            "    Flash chip configuration is ok."
            "  </div>";
    }

    message +=
        PageFooter() +
        "</div>" +
        PageEnd();

    return message;
}

String Pages::NotFound(ESP8266WebServer *server) {
  String message =
    PageBegin() +
    "<div class=\"container\">"
    "  <p>"
    "    <h3>404 - Not Found</h3>"
    "    <hr />"
    "    URI: " + server->uri() +
    "    <br>Method: " + (server->method() == HTTP_GET ? "GET" : "POST") +
    "    <br>Arguments: " + server->args() + "<br>";
  for (uint8_t i=0; i<server->args(); i++){
    message += " " + server->argName(i) + ": " + server->arg(i) + "<br>";
  }
  message +=
    "  </p>"
    "</div>" +
    PageEnd();
  return message;
}
