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

<img src="https://uvindex.chandlermayo.com/pics/indicator/IMG-7001.JPG" height="200">

### PubNub Features
- [PubNub React V4 SDK](https://www.pubnub.com/docs/react-native-javascript/pubnub-javascript-sdk) - Publish, subscribe, and history.
- [PubNub Arduino SDK](https://www.pubnub.com/docs/arduino/pubnub-arduino-sdk) - Publish and subscribe with ESP8266.
- [PubNub Push Notifications](https://www.pubnub.com/developers/tech/push-notifications/) - APNS and GCM push notifications.

<img src="https://uvindex.chandlermayo.com/pics/app/android/Screenshot_1531322689.png" height="300">

### Hardware Used for Sensor and Indicator 
- [ESP8266 ESP-12E NodeMcu Development Board](https://www.amazon.com/HiLetgo-Internet-Development-Wireless-Micropython/dp/B010N1SPRK/)
- [Analog UV Light Sensor](https://www.amazon.com/gp/product/B00LEVTOB0)
- Breadboard and Breadboard Jumper Wires
- RGB LED (common cathode)
