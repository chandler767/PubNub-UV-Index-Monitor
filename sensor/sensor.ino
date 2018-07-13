#include <ESP8266WiFi.h>
#define PubNub_BASE_CLIENT WiFiClient
#include <PubNub.h>
 
const static char ssid[] = "Sensor Network";
const static char pass[] = "sens0rpassw0rd"; 

int sendTimer;   // Timer used to control how often messages are published. Sends a new message once every 10 minutes.
int sensorTimer; // Timer used to control how often sensor is checked. Checked every 60 seconds.
float sensorValue; // Value from sensor.
int lastuvindex; // UV index on previous loop.
int uvindex; // Value from sensor converted to UV index.

void setup() {
    Serial.begin(9600);
    WiFi.begin(ssid, pass);
    if(WiFi.waitForConnectResult() == WL_CONNECTED){
      Serial.println("WiFi connected.");
      PubNub.begin("pub-c-55f69e96-38f2-4f39-9271-084022b8327e", "sub-c-f6b3e9d0-83b9-11e8-ac0f-0e4b9865ddaa");
    } else {
      Serial.println("Couldn't get a wifi connection.");
      while(1) delay(100);
    }
}
 
void loop() {
    sensorTimer = (sensorTimer + 1); // Add a second to the sensor timer.
    if (sensorTimer == 60) { // Check sensor.
      sensorTimer = 0; // Reset timer.
      sendTimer = (sendTimer + 1); // Add a minute to sendTimer. 
      if (sendTimer == 10) { // Reset timer after 10 minutes.
        sendTimer = 0; // Reset timer.
      }
      sensorValue = analogRead(A0); // Read sensor. Convert to UV index.
      if ((sensorValue >= 0) && (sensorValue < 20)) {
        uvindex = 0; 
      }
      else if ((sensorValue >= 20) && (sensorValue < 65)) {
        uvindex = 1;
      }
      else if ((sensorValue >= 65) && (sensorValue < 83)) {
        uvindex = 2;
      }
      else if ((sensorValue >= 83) && (sensorValue < 103)) {
        uvindex = 3;
      }
      else if ((sensorValue >= 103) && (sensorValue < 124)) {
        uvindex = 4;
      }
      else if ((sensorValue >= 124) && (sensorValue < 142)) {
        uvindex = 5;
      }
      else if ((sensorValue >= 142) && (sensorValue < 162)) {
        uvindex = 6;
      }
      else if ((sensorValue >= 162) && (sensorValue < 180)) {
        uvindex = 7;
      }
      else if ((sensorValue >= 180) && (sensorValue < 200)) {
        uvindex = 8;
      }
      else if ((sensorValue >= 200) && (sensorValue < 221)) {
        uvindex = 9;
      }
      else if ((sensorValue >= 221) && (sensorValue < 240)) {
        uvindex = 10;
      }
      else if (sensorValue >= 240) {
        uvindex = 11;
      }
      
      if ((lastuvindex != uvindex) || (sendTimer == 0)) { // Send a new message if sendTimer was reset or if UV index has changed.
        lastuvindex = uvindex; // Save the UV index.
        PubNub_BASE_CLIENT *client;
        Serial.println("publishing a message");
        char msg[64] = "{\"eon\":{\"uvindex\":"; 
        sprintf(msg + strlen(msg), "%d", uvindex);
        strcat(msg, "}}");
        client = PubNub.publish("uvindex", msg);
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
      }
        
    }
    delay(1000);
}

