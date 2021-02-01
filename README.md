# Overview
Connect a DHT22 temperature/humidity sensor to an ESP8266 (NodeMCU) and display the values to a self-hosted webpage.

## Part List
- DHT22 (Temperature / Humidity Sensor)
- ESP8266 (NodeMCU)

## Setup
1. Download and install the latest version of Arduino.
1. Open `esp8266-dh22.ino` using Arduino.
1. Open preferences and include the additional board manager url: `https://arduino.esp8266.com/stable/package_esp8266com_index.json`
1. Open board manager and search for and install [esp8266](https://github.com/esp8266/Arduino).
1. Select select your compatabible esp8266 board and verify COM port
1. Using the library manager, search for and install [DHT sensor library by Adafruit](https://github.com/adafruit/DHT-sensor-library) and [PageBuilder by Hieromon Ikasamo](https://github.com/Hieromon/PageBuilder).
1. Update code to use desired credentials for wifi.
1. Verify, compile and upload code to ESP8266.

## Testing
1. After uploading the code to ESP8266, open the serial monitor.
1. Make note of the IP address listed for the device.
1. Verify temperature and humidity readings are displayed to the serial monitor.
1. Open a browser and navigate to the IP address of the device.
1. You should see the temperature and humidity values printed to the webpage.

## Wiring
![DHT22 ESP8266 Wiring Diagram](https://i.imgur.com/EkWpx8M.jpg)

## Built-in web server display
![Temperature and humidity reading displayed on a built-in webserver hosted by the esp8266](https://i.imgur.com/DkiFGr3.png)
