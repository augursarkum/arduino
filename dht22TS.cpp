#include <SPI.h>
#include <Ethernet.h>
#include <DHT.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
char server[] = "api.thingspeak.com";
char channelID[] = "YOUR_CHANNEL_ID";
char writeAPIKey[] = "YOUR_WRITE_API_KEY";

#define DHTPIN A0
#define DHTTYPE DHT22
DHT_Unified dht(DHTPIN, DHTTYPE);
float temperature, humidity;

void setup() {
  Serial.begin(9600);
  dht.begin();
  Ethernet.begin(mac);
}

void loop() {
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  temperature = event.temperature;
  dht.humidity().getEvent(&event);
  humidity = event.relative_humidity;
  String dataString = String(temperature) + "," + String(humidity);
  if (Ethernet.begin(mac) == 1) {
    EthernetClient client;
    if (client.connect(server, 80)) {
      client.println("POST /update HTTP/1.1");
      client.println("Host: api.thingspeak.com");
      client.println("Connection: close");
      client.println("X-THINGSPEAK-CHANNEL-ID: " + channelID);
      client.println("X-THINGSPEAK-WRITE-API-TOKEN: " + writeAPIKey);
      client.println("Content-Type: application/x-www-form-urlencoded");
      client.print("field1=");
      client.print(dataString);
      client.println("&version=1.0");
      client.println();
      client.stop();
    }
  }
  delay(2000);
}
