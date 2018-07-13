#include <ESP8266WiFi.h>
#define PubNub_BASE_CLIENT WiFiClient
#include <PubNub.h>
 
const static char ssid[] = "Sensor Network";
const static char pass[] = "sens0rpassw0rd"; 

int rled = 14; // The PWM pins the LED is attached to.
int gled = 12;
int bled = 15;


void setup() {
    pinMode(rled, OUTPUT);
    pinMode(gled, OUTPUT);
    pinMode(bled, OUTPUT);

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
    
    Serial.println("waiting for a message (subscribe)");
    PubSubClient *pclient = PubNub.subscribe("uvindex");
    if (!pclient) {
        Serial.println("subscription error");
        delay(1000);
        return;
    }
    String uvindex;
    while (pclient->wait_for_data()) {
        char c = pclient->read();
        //Serial.print(c);
        uvindex = uvindex+String(c);
    }
    pclient->stop();

    // Alternatively parse the JSON, however only one value is needed and the location of the value is known in the string. No need for another package. 
    uvindex.remove(0, 19); // Remove string before value.
    uvindex = uvindex.substring(0, uvindex.length() - 4); // Remove string after value.
    Serial.print("UV Index:"+uvindex);
    int uvindexvalue = uvindex.toInt();

    Serial.println();
    delay(1000);
}

