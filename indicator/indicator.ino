#include <ESP8266WiFi.h>
#define PubNub_BASE_CLIENT WiFiClient
#include <PubNub.h>
// #include <ArduinoJson.h> // Uncomment to get UV index value by parsing JSON using v5 of the ArduinoJSON library.
 
const static char ssid[] = "Sensor Network";
const static char pass[] = "sens0rpassw0rd"; 

int rled = 14; // The PWM pins the LED is attached to.
int gled = 12;
int bled = 15;

int uvindex = 0;

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
    PubSubClient *pclient = PubNub.subscribe("uvindex"); // Subscribe to the UV index channel for values.
    if (!pclient) {
        Serial.println("subscription error");
        delay(1000);
        return;
    }
    String message;
    while (pclient->wait_for_data()) {
        char c = pclient->read();
        //Serial.print(c);
        message = message+String(c); // Append to string.
    }
    pclient->stop();
    
    /*
    // Uncomment to get UV index value by parsing JSON using v5 of the ArduinoJSON library.
    message = message.substring(1, message.length() - 2); // Remove extra bracket before and extra brackets after JSON.
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(message);
    if (!root.success()) { // Test if parsing succeeds.
      Serial.println("parseObject() failed");
    }
    else {
      uvindex = root["eon"]["uvindex"];
    }
    //*/

    // Comment to parse JSON for UV index value.
    // Get UV index value without parsing JSON. Only one value is needed and the location of the value is known in the message. No need for the ArduinoJSON library. 
    if(message.indexOf("uvindex") > 0) { // Ensure the message contains the UV iindex (prevents a unexpected message from turning off the led).
      uvindex = message.substring(19, message.length() - 4).toInt(); // Remove characters before and after value.
    };
    //*/

    // Set the color of the led based on the UV index.
    if ((uvindex >= 0)  && (uvindex < 1)) { // None 0 Off
        analogWrite(rled, 0);
        analogWrite(gled, 0);
        analogWrite(bled, 0);
    } else if ((uvindex >= 1) && (uvindex < 3)) { // Low 1-2 Green
        analogWrite(rled, 0);
        analogWrite(gled, 255);
        analogWrite(bled, 0);
    } else if ((uvindex >= 3) && (uvindex < 6)) { // Moderate 3-5 Yellow
        analogWrite(rled, 255);
        analogWrite(gled, 255);
        analogWrite(bled, 0);
    } else if ((uvindex >= 6) && (uvindex < 8)) { // High 6-7 Orange
        analogWrite(rled, 255);
        analogWrite(gled, 120);
        analogWrite(bled, 0);
    } else if ((uvindex >= 8) && (uvindex < 11)) { // Very High 8-10 Red
        analogWrite(rled, 255);
        analogWrite(gled, 0);
        analogWrite(bled, 0);
    } else if (uvindex >= 11) { // Extreme 11+ Purple
        analogWrite(rled, 85);
        analogWrite(gled, 0);
        analogWrite(bled, 85);
    };

    Serial.print("UV Index: ");
    Serial.print(uvindex);
    Serial.println();
    delay(5000);
}

