# UV Index Monitor Powered By [PubNub](https://www.pubnub.com/)

<img align="right" src="https://uvindex.chandlermayo.com/pics/app/ios/IMG-6918.JPG" height="300">

Sunscreen kinda sucks. It’s sticky, oily, and somehow you always manage to miss a spot on your back only to realize it, painfully, later. What if there was another way? What if you knew when it was safe to be in the open and when to retreat to the shade? What if you had a way to reliably know the current UV index at a glance? Here’s your solution.

Read the rest of the blog post here: (coming soon).

<img src="https://uvindex.chandlermayo.com/pics/sensor/IMG-6987.JPG" height="200">

## Features
- UV index sensor and a ESP2866 development board publishes UV index values to PubNub.
- A second ESP2866 development board retrieves UV index values from PubNub and indicates the current UV index with a RGB LED.
- UV index graph powered by [Project EON](https://www.pubnub.com/developers/eon/) hosted on GitHub Pages: https://uvindex.chandlermayo.com/
- ReactNative app that displays current UV index and when the app is turned landscape the UV index graph from GitHub Pages is displayed.
- Push notifications (coming soon).

<img align="right" src="https://uvindex.chandlermayo.com/pics/app/android/Screenshot_1531322689.png" height="300">

### PubNub Features
- [PubNub React V4 SDK](https://www.pubnub.com/docs/react-native-javascript/pubnub-javascript-sdk) - Publish, subscribe, and history.
- [PubNub Arduino SDK](https://www.pubnub.com/docs/arduino/pubnub-arduino-sdk) - Publish and subscribe with ESP8266.
- [PubNub Push Notifications](https://www.pubnub.com/developers/tech/push-notifications/) - APNS and GCM push notifications.
- [Project EON](https://www.pubnub.com/developers/eon/) - Open-source charts.

<img align="right" src="https://uvindex.chandlermayo.com/pics/indicator/IMG-7001.JPG" height="200">

### Hardware Used for Sensor and Indicator 
- [ESP8266 ESP-12E NodeMcu Development Board](https://www.amazon.com/HiLetgo-Internet-Development-Wireless-Micropython/dp/B010N1SPRK/)
- [Analog UV Light Sensor](https://www.amazon.com/gp/product/B00LEVTOB0)
- Breadboard and Breadboard Jumper Wires
- RGB LED (common cathode)

## How To Get Started
Want to learn more about this project and how it was built? Check out the blog post (coming soon).

You’ll first need to sign up for a [PubNub account](https://dashboard.pubnub.com/signup). Once you sign up, you can get your unique PubNub keys in the [PubNub Developer Portal](https://admin.pubnub.com/).
### Setting Up The UV Index Sensor and UV Index Indicator
1. Download the latest [Arduino IDE](https://www.arduino.cc/en/Main/Software).
2. Install [Silicon Labs CP210x USB to UART Bridge driver](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers) for your OS.
3. You'll need to update the Arduino Board Manager with a custom URL. Open up Arduino and then go to the Preferences (File > Preferences). Then, towards the bottom of the window, copy this URL into the “Additional Board Manager URLs” text box:
```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```
4. Navigate to the Board Manager by going to Tools > Boards > Boards Manager. Search for ESP8266. Click on that entry, then select Install.
5. Connect your ESP8266 Development board and select it by going to Tools > Boards menu. You may need to select the correct port.
6. Verify that everything works by uploading the blink sketch.
7. Install the PubNub Arduino SDK by going to Sketch > Include Library > Manage Libraries. Search for PubNub. Click on that entry, then select Install.
#### UV Index Sensor
The UV index sensor reads the current UV index levels one per minute and publishes the values to PubNub when the value changes and at least once every 10 minutes.

1. Connect the positive pin of the UV sensor to a 3.3v pin on your development board and connect the ground pin of the UV sensor to a ground pin on your development board. Connect the output of the UV sensor to the analog input on your development board (A0).
2. Test the sensor by going to File > Examples > 01.Basics > AnalogReadSerial. Upload the sketch and check the Serial Monitor for values.
3. Open sensor/sensor.ino in Arduino.
4. Replace "Sensor Network" and "sens0rpassw0rd" with the SSID and password for your WiFi network.
5. Get your unique PubNub keys in the [PubNub Developer Portal](https://admin.pubnub.com/). If you don't have a PubNub account, you can [sign up for a PubNub account](https://dashboard.pubnub.com/signup) for free. Replace "pub-key" and "sub-key" with your keys.
6. Upload the sketch. You can use the Serial Monitor to verify you're able to connect to WiFi and publish your sensor readings to PubNub.
7. Verify the sensor readings are making it to PubNub by going to your [PubNub Developer Portal](https://admin.pubnub.com/), select the keys your created previously, and create a client in the Debug Console. Set the 'Default Channel' to 'uvindex' and leave the other fields blank. Click 'ADD CLIENT'. You should see a message with the current UV index within 10 minutes or if the sensor reading changes. You can also reset the development board to force it to resend the current UV index value. 

More coming soon.
