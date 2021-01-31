#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Uncomment one of the lines below for whatever DHT sensor type you're using!
//#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

/*Put your SSID & Password*/
#define wifi_ssid "NETWORK_SSID" // Change to match your wireless network
#define wifi_password "NETWORK_PASSPHRASE" // Change to match your wireless passphrase

/* Webserver Config */
WiFiClient espClient;
ESP8266WebServer server(80);

// DHT Sensor
uint8_t DHTPin = D4;

// Initialize DHT sensor.
DHT dht(DHTPin, DHTTYPE);
int Temperature;
int Humidity;

void setup() {
  Serial.begin(115200);
  setup_wifi();
  dht.begin();

  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");

  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void setup_wifi() {
  delay(10);
  WiFi.begin(wifi_ssid, wifi_password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

bool checkBound(float newValue, float prevValue, float maxDiff) {
  return newValue < prevValue - maxDiff || newValue > prevValue + maxDiff;
}

long lastMsg = 0;
int temp = 0.0;
int hum = 0.0;
float diff = 1.0;

void loop() {
  server.handleClient();
  long now = millis();
  if (now - lastMsg > 10000) {
    // Wait a few seconds between measurements
    lastMsg = now;
    int newTemp = dht.readTemperature();
    int newHum = dht.readHumidity();
    temp = ((int)newTemp * 9 / 5) + 32;
    Serial.print("New temperature:");
    Serial.println(String(temp).c_str());
    Serial.print("New humidity:");
    Serial.println(String(newHum).c_str());
  }
}

void handle_OnConnect() {
  Temperature = dht.readTemperature(); // Gets the values of the temperature
  Humidity = dht.readHumidity(); // Gets the values of the humidity
  server.send(200, "text/html", SendHTML(Temperature, Humidity));
}

void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}

String SendHTML(float Temperaturestat, float Humiditystat) {
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>DHT22 Temperature/Humidity Sensor</title>\n";
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr += "body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;}\n";
  ptr += "p {font-size: 24px;color: #444444;margin-bottom: 10px;}\n";
  ptr += "</style>\n";
  ptr += "<script>";
  ptr += "function refresh(refreshPeriod)";
  ptr += "{";
  ptr += "setTimeout('location.reload(true)', refreshPeriod);";
  ptr += "}";
  ptr += "window.onload = refresh(5000);";
  ptr += "</script>";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<div id=\"webpage\">\n";
  ptr += "<h1>DHT22 Temperature/Humidity Sensor</h1>\n";
  
  ptr += "<p>Temperature: ";
  ptr += ((int)Temperaturestat * 9 / 5) + 32;
  ptr += "&deg; F</p>";
  ptr += "<p>Humidity: ";
  ptr += (int)Humiditystat;
  ptr += "%</p>";
  
  ptr += "</div>\n";
  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}
