#include <ESP8266WiFi.h>
#define PubNub_BASE_CLIENT WiFiClient
#include <PubNub.h>
 
const static char ssid[] = "Sensor Network";
const static char pass[] = "sens0rpassw0rd"; 
 
void setup() {
    Serial.begin(9600);
    WiFi.begin(ssid, pass);
    if(WiFi.waitForConnectResult() == WL_CONNECTED){
      PubNub.begin("pub-c-55f69e96-38f2-4f39-9271-084022b8327e", "sub-c-f6b3e9d0-83b9-11e8-ac0f-0e4b9865ddaa");
    } else {
      Serial.println("Couldn't get a wifi connection");
      while(1) delay(100);
    }
}
 
void loop() {
    PubNub_BASE_CLIENT *client;
 
    Serial.println("publishing a message");
    client = PubNub.publish("uvindex", "\{\"eon\":\{\"uvindex\":10\}\}");
    if (!client) {
        Serial.println("publishing error");
        delay(1000);
        return;
    }
    while (client->connected()) {
        while (client->connected() && !client->available());
        char c = client->read();
        Serial.print(c);
    }
    client->stop();
    Serial.println();
 
    Serial.println("waiting for a message (subscribe)");
    PubSubClient *pclient = PubNub.subscribe("uvindex");
    if (!pclient) {
        Serial.println("subscription error");
        delay(1000);
        return;
    }
    while (pclient->wait_for_data()) {
        char c = pclient->read();
        Serial.print(c);
    }
    pclient->stop();
    Serial.println();
    delay(1000);
}

