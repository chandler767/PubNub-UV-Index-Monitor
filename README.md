# UV Index Monitor Powered By [PubNub](https://www.pubnub.com/)

<img align="right" src="https://uvindex.chandlermayo.com/pics/app/ios/IMG-6918.JPG" height="350">

Sunscreen kinda sucks. It’s sticky, oily, and somehow you always manage to miss a spot on your back only to realize it, painfully, later. What if there was another way? What if you knew when it was safe to be in the open and when to retreat to the shade? What if you had a way to reliably know the current UV index at a glance? Here’s your solution.

Read the rest of the blog post here: (coming soon).

<img src="https://uvindex.chandlermayo.com/pics/sensor/IMG-6987.JPG" height="200">

## About

This project uses a UV index sensor and a ESP8266 development board to read the current UV index level and publishes the values to [PubNub](https://www.pubnub.com/). A second ESP8266 development board with a RGB LED subscribes to the messages published by the sensor and displays the value using color. 0 = off, 1-2 = green, 3-5 = yellow, 6-7 = orange, 8-10 = red, and 11+ = purple. A ReactNative app for iOS and Android shows the last reported or current UV Index and receives push notifications if the UV index is excessive. Additionally, the app displays a realtime chart of the UV index values powered by [Project EON](https://www.pubnub.com/developers/eon/) and hosted on this repos GitHub Pages site: https://uvindex.chandlermayo.com/

<img align="right" src="https://uvindex.chandlermayo.com/pics/app/android/Screenshot_1531322689.png" height="300">

### PubNub Features 

- [PubNub React V4 SDK](https://www.pubnub.com/docs/react-native-javascript/pubnub-javascript-sdk) - Publish, subscribe, and history.

- [PubNub Arduino SDK](https://www.pubnub.com/docs/arduino/pubnub-arduino-sdk) - Publish and subscribe with ESP8266.

- [PubNub Push Notifications](https://www.pubnub.com/developers/tech/push-notifications/) - APNS and GCM push notifications.

- [Project EON](https://www.pubnub.com/developers/eon/) - Realtime data visualization.

<img align="right" src="https://uvindex.chandlermayo.com/pics/indicator/IMG-7001.JPG" height="180">

### Hardware

- [ESP8266 ESP-12E NodeMcu Development Board](https://www.amazon.com/HiLetgo-Internet-Development-Wireless-Micropython/dp/B010N1SPRK/)

- [Analog UV Light Sensor](https://www.amazon.com/gp/product/B00LEVTOB0)

- Breadboard and Breadboard Jumper Wires

- RGB LED (common cathode)

## How To Get Started

Want to learn more about this project, how it was built, or get started from scratch? Check out the blog post (coming soon). You’ll first need to sign up for a [PubNub account](https://dashboard.pubnub.com/signup). Once you sign up, you can get your unique PubNub keys in the [PubNub Developer Portal](https://admin.pubnub.com/).

### Setting Up The UV Index Sensor and UV Index Indicator

1. Download the latest [Arduino IDE](https://www.arduino.cc/en/Main/Software).

2. Install [Silicon Labs CP210x USB to UART Bridge driver](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers) for your OS.

3. You'll need to update the Arduino Board Manager with a custom URL. Open up Arduino and then go to the Preferences (File > Preferences). Then, towards the bottom of the window, copy this URL into the “Additional Board Manager URLs” text box:
`http://arduino.esp8266.com/stable/package_esp8266com_index.json`

4. Navigate to the Board Manager by going to Tools > Boards > Boards Manager. Search for ESP8266. Click on that entry, then select Install.

5. Connect your ESP8266 Development board and select it by going to Tools > Boards menu. You may need to select the correct port.

6. Verify that everything works by uploading the blink sketch. The built-in led should be blinking.

7. Install the PubNub Arduino SDK by going to Sketch > Include Library > Manage Libraries. Search for PubNub. Click on that entry, then select Install.

#### UV Index Sensor

<img align="right" src="https://raw.githubusercontent.com/chandler767/PubNub-UV-Index-Monitor/gh-pages/pics/sensor/IMG-6992.JPG" height="250">

The UV index sensor reads the current UV index levels one per minute and publishes the values to PubNub when the value changes and at least once every 10 minutes.

1. Connect the positive pin of the UV sensor to a 3.3v pin on your development board and connect the ground pin of the UV sensor to a ground pin on your development board. Connect the output of the UV sensor to the analog input on your development board (A0).

2. Test the sensor by going to File > Examples > 01.Basics > AnalogReadSerial. Upload the sketch and check the Serial Monitor for values.

3. Open sensor/sensor.ino in Arduino.

4. Replace "Sensor Network" and "sens0rpassw0rd" with the SSID and password for your WiFi network.

5. Get your unique PubNub keys in the [PubNub Developer Portal](https://admin.pubnub.com/). If you don't have a PubNub account, you can [sign up for a PubNub account](https://dashboard.pubnub.com/signup) for free. Replace "pub-key" and "sub-key" with your keys.

6. Upload the sketch. You can use the Serial Monitor to verify you're able to connect to WiFi and publish your sensor readings to PubNub.
<img align="right" src="https://raw.githubusercontent.com/chandler767/PubNub-UV-Index-Monitor/gh-pages/pics/pubnub/debug_client.png" height="250">

7. Verify the sensor readings are making it to PubNub by going to your [PubNub Developer Portal](https://admin.pubnub.com/), select the keys your created previously, and create a client in the Debug Console. Set the 'Default Channel' to 'uvindex' and leave the other fields blank. Click 'ADD CLIENT'. You should see a message with the current UV index within 10 minutes or if the sensor reading changes. You can also reset the development board to force it to resend the current UV index value.

8. Move your UV index sensor to a sunny location within range of WiFi. If you need to place your sensor in a place without power you could use a USB power bank to deliver power to your development board.

#### UV Index Indicator

<img align="right" src="https://uvindex.chandlermayo.com/pics/indicator/IMG-6999.JPG" height="200">

The UV Index Indicator subscribes to the 'uvindex' channel and displays the uv index value using color. 0 = off, 1-2 = green, 3-5 = yellow, 6-7 = orange, 8-10 = red, and 11+ = purple. 

More coming soon.
