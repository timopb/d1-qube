# D1 Mini Pro / SSD1306 Example (on steroids)


![D1 Mini](https://raw.githubusercontent.com/timopb/d1-qube/master/docs/d1-mini.jpg)

This example demonstrates the use of my customized Adafruit SSD1306 Driver as well as a couple of other technologies unified into one massive sketch:
- OTA Update
- WifiManager
- mDNS Client
- HTTP API Server and HTML Webfrontend using ESP8266WebServer

After you have flashed the firmware use a pc or mobile device to connect to the Wifi access point (ESP?????) provided by the D1. Open a browser and load a random page. The D1 will display the wifi configuration UI. Configure the D1 to connect to your wifi Infrastructure by providing a valid SSID and Password. 

After rebooting the D1 it will connect to your wifi and can be accessed from any device within your network. Use a browser to connect to the IP shown on the D1's display.

![D1 Mini GUI](https://raw.githubusercontent.com/timopb/d1-qube/master/docs/web1.png)

![D1 Mini Info](https://raw.githubusercontent.com/timopb/d1-qube/master/docs/web2.png)
