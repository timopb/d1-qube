#include "html.h"

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

const String HTML_BEGIN =
  "<!DOCTYPE html>"
  "<html>"
  "  <head>"
  "    <meta charset=\"utf-8\">"
  "    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">"
  "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">"
  "    <title>D1 Mini</title>"
  "    <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.5/css/bootstrap.min.css\" crossorigin=\"anonymous\">"
  "    <style>"
  "      .footer,body{padding-top:1.0rem}.header,.jumbotron{border-bottom:.05rem solid #e5e5e5}body{padding-bottom:1.5rem}.lead{padding-top:1rem; padding-bottom:1.5rem}"
  "      .footer,.header{padding-right:1rem;padding-left:1rem}.header{padding-bottom:1rem}.header h3{margin-top:0;margin-bottom:0;line-height:3rem}"
  "      .footer{color:#777;border-top:.05rem solid #e5e5e5}@media (min-width:48em){.container{max-width:46rem}}.container-narrow>hr{margin:2rem 0}"
  "      .jumbotron{text-align:center}.jumbotron .btn{padding:.75rem;font-size:1.5rem; margin:5px;width:200px}@media screen and (min-width:48em){.footer,"
  "      .header{padding-right:0;padding-left:0}.header{margin-bottom:2rem}.jumbotron{border-bottom:0}}p{margin:0px}"
  "    </style>"
  "  </head>"
  "  <body>";

const String HTML_END =
  "</body></html>";

const String divFooter =
  "  <footer class=\"footer\">"
  "    <p>&copy; <a href=\"https://twitter.com/herrbausm\">HerrBausM</a></p>"
  "  </footer>";

String divNavBar(String title) {
  return
    "  <div class=\"header clearfix\">"
    "    <nav>"
    "      <ul class=\"nav nav-pills float-xs-right\">"
    "        <li class=\"nav-item\">"
    "          <a class=\"nav-link" + String(title=="D1 Mini" ? " active\" href=\"#" : "\" href=\"/") + "\">Home</a>"
    "        </li>"
    "        <li class=\"nav-item\">"
    "          <a class=\"nav-link" + String(title=="Info" ? " active\" href=\"#" : "\" href=\"/info") + "\">Info</a>"
    "        </li>"
    "      </ul>"
    "    </nav>"
    "    <h3 class=\"text-muted\">" + title + "</h3>"
    "  </div>";
}

String Page_Index() {
  return
    HTML_BEGIN +
    "<script>"
    "function call(message) {"
    "  var xhttp = new XMLHttpRequest();"
    "  xhttp.open(\"GET\", message, true);"
    "  xhttp.send();"
    "}"
    "</script>"
    "<div class=\"container\">" +
    divNavBar("D1 Mini") +
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
    divFooter +
    "</div>" +
    HTML_END;
}

String Page_Memory() {
  uint32_t realSize = ESP.getFlashChipRealSize();
  uint32_t ideSize = ESP.getFlashChipSize();
  FlashMode_t ideMode = ESP.getFlashChipMode();

  String message =
    HTML_BEGIN +
    "<div class=\"container\">" +
    divNavBar("Info") +
    "  <div class=\"table-responsive\">"
    "  <table class=\"table\">"
    "    <tr><td>CPU Speed</td><td>" + String(ESP.getCpuFreqMHz()) + " MHz</td></tr>"
    "    <tr><td>Flash chip Id</td><td>" + String(ESP.getFlashChipId()) + "</td></tr>"
    "    <tr><td>Flash real size</td><td>" +  readable_size(realSize)  + "</td></tr>"
    "    <tr><td>Flash ide size</td><td>" + readable_size(ideSize) + "</td></tr>"
    "    <tr><td>Flash ide speed</td><td>" + String(ESP.getFlashChipSpeed()/1000000) + " MHz</td></tr>"
    "    <tr><td>Flash ide mode</td><td>" + String(ideMode == FM_QIO ? "QIO" : ideMode == FM_QOUT ? "QOUT" : ideMode == FM_DIO ? "DIO" : ideMode == FM_DOUT ? "DOUT" : "UNKNOWN") + "</td></tr>"
    "    <tr><td>Sketch size</td><td>" + readable_size(ESP.getSketchSize()) + "</td></tr>"
    "    <tr><td>Free sketch space</td><td>" + readable_size(ESP.getFreeSketchSpace()) + "</td></tr>"
    "  </table>"
    "  </div>";

  if(ideSize != realSize) {
    message +=
    "  <div class=\"alert alert-danger\" role=\"alert\">"
    "    Flash chip configuration is wrong!"
    "  </div>";
  } else {
    message +=
    "  <div class=\"alert alert-success\" role=\"alert\">"
    "    Flash chip configuration is ok."
    "  </div>";
  }

  message +=
    divFooter +
    "</div>" +
    HTML_END;

  return message;
}

String Page_NotFound(ESP8266WebServer *server) {
  String message =
    HTML_BEGIN +
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
    HTML_END;
  return message;
}
