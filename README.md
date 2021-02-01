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
  
 
