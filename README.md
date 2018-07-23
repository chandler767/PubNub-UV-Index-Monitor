# UV Index Monitor Powered By [PubNub](https://www.pubnub.com/?devrel_gh=PubNub-UV-Index-Monitor )

<img align="right" src="https://uvindex.chandlermayo.com/pics/app/ios/IMG-6918.JPG" height="330">

Sunburns are terrible for you. The high energy UVB rays from the sun can cause mutations in your genes and a single sunburn is enough to increase your risk for melanoma. As few as five sunburns nearly doubles your risk for melanoma. The damage to your DNA stacks up over time and it's important you use protection when you go outside to mitigate the damage to your skin. Unfortunately, sunscreen sucks. It’s sticky, oily, and somehow you always manage to miss a spot on your back only to realize it, painfully, later. What if there was another way? What if you knew when it was safe to be in the open and when to retreat to the shade?

Read the rest of the blog post here: (coming soon).

<img src="https://uvindex.chandlermayo.com/pics/pubnub/pubnub.png" width="450">


## About

This project uses a UV index sensor and a ESP8266 development board to read the current UV index level and then publishes the UV index value to [PubNub](https://www.pubnub.com/?devrel_gh=PubNub-UV-Index-Monitor). A second ESP8266 development board with a RGB LED subscribes to the messages published by the sensor and displays the most recent value using color. 0 = off, 1-2 = green, 3-5 = yellow, 6-7 = orange, 8-10 = red, and 11+ = purple. A React Native app for iOS and Android shows the last reported or current UV index and the app receives push notifications if the UV index is excessive. Additionally, the app displays a realtime chart of the UV index values powered by [Project EON](https://www.pubnub.com/developers/eon/?devrel_gh=PubNub-UV-Index-Monitor) and hosted on the [GitHub Pages site](https://uvindex.chandlermayo.com/) for this repo.

<img align="right" src="https://uvindex.chandlermayo.com/pics/app/android/Screenshot_1531322689.png" height="250">

### PubNub Features 

- [PubNub React V4 SDK](https://www.pubnub.com/docs/react-native-javascript/pubnub-javascript-sdk/?devrel_gh=PubNub-UV-Index-Monitor) - Publish, subscribe, and history in React Native.

- [PubNub Arduino SDK](https://www.pubnub.com/docs/arduino/pubnub-arduino-sdk/?devrel_gh=PubNub-UV-Index-Monitor) - Publish and subscribe with ESP8266.

- [PubNub Push Notifications](https://www.pubnub.com/developers/tech/push-notifications/?devrel_gh=PubNub-UV-Index-Monitor ) - APNS and GCM push notifications with React Naive.

- [Project EON](https://www.pubnub.com/developers/eon/?devrel_gh=PubNub-UV-Index-Monitor) - Realtime data visualization for UV index.

<img align="right" src="https://uvindex.chandlermayo.com/pics/indicator/IMG-7001.JPG" height="200">

### Hardware

- [ESP8266 ESP-12E NodeMcu Development Board](https://www.amazon.com/HiLetgo-Internet-Development-Wireless-Micropython/dp/B010N1SPRK/)

- [Analog UV Light Sensor](https://www.amazon.com/gp/product/B00LEVTOB0)

- Breadboard and Breadboard Jumper Wires

- RGB LED (common cathode)


## How To Get Started

Want to learn more about this project, how it was built, or get started from scratch? Check out the blog post (coming soon). You’ll first need to sign up for a [PubNub account](https://dashboard.pubnub.com/signup/?devrel_gh=PubNub-UV-Index-Monitor). Once you sign up, you can get your unique PubNub keys from the [PubNub Developer Portal](https://admin.pubnub.com/?devrel_gh=PubNub-UV-Index-Monitor).

### Setup UV Index Sensor and UV Index Indicator

1. Download the latest [Arduino IDE](https://www.arduino.cc/en/Main/Software).

2. Install [Silicon Labs CP210x USB to UART Bridge driver](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers) for your OS.

3. You'll need to update the Arduino Board Manager with a custom URL. Open up Arduino and then go to the Preferences (File > Preferences). Then, towards the bottom of the window, copy this URL into the “Additional Board Manager URLs” text box:
`http://arduino.esp8266.com/stable/package_esp8266com_index.json`

4. Navigate to the Board Manager by going to Tools > Boards > Boards Manager. Search for ESP8266. Click on that entry, then select Install.

5. Connect your ESP8266 Development board and select it by going to Tools > Boards menu. You may need to select the correct port.

6. Verify that everything works by uploading the blink sketch. The built-in led should be blinking.

7. Install the [PubNub Arduino SDK](https://www.pubnub.com/docs/arduino/pubnub-arduino-sdk/?devrel_gh=PubNub-UV-Index-Monitor ) by going to Sketch > Include Library > Manage Libraries. Search for PubNub. Click on that entry, then select Install.

8. You can test the ability for your ESP8266 Development board to connect to PubNub by uploading [this gist](https://gist.github.com/chandler767/472a93fac406af096d00c8377aa3fb17) to your development board with the Arduino IDE. Replace "your-ssid" and "your-password" with the SSID and password for your WiFi network. Get your unique PubNub keys from the [PubNub Developer Portal](https://admin.pubnub.com/?devrel_gh=PubNub-UV-Index-Monitor ). If you don't have a PubNub account, you can [sign up for a PubNub account](https://dashboard.pubnub.com/signup/?devrel_gh=PubNub-UV-Index-Monitor) for free. Replace "pub-key" and "sub-key" with your keys.

#### UV Index Sensor

<img align="right" src="https://uvindex.chandlermayo.com/pics/sensor/IMG-6992.JPG" height="250">

The UV index sensor reads the current UV index levels once per minute and publishes the values to PubNub when the value changes and at least once every 10 minutes.

1. Connect the positive pin of the UV sensor to a 3.3v pin on your development board and connect the ground pin of the UV sensor to a ground pin on your development board. Connect the output of the UV sensor to the analog input on your development board (A0).

2. Test the sensor by going to File > Examples > 01.Basics > AnalogReadSerial. Upload the sketch and check the Serial Monitor for values.

3. Open [sensor/sensor.ino](https://github.com/chandler767/PubNub-UV-Index-Monitor/tree/master/sensor) in Arduino.

4. Replace "Sensor Network" and "sens0rpassw0rd" with the SSID and password for your WiFi network.

5. Get your unique PubNub keys from the [PubNub Developer Portal](https://admin.pubnub.com/?devrel_gh=PubNub-UV-Index-Monitor ). If you don't have a PubNub account, you can [sign up for a PubNub account](https://dashboard.pubnub.com/signup/?devrel_gh=PubNub-UV-Index-Monitor) for free. Replace "pub-key" and "sub-key" with your keys.

6. Upload the sketch. You can use the Serial Monitor to verify you're able to connect to WiFi and publish your sensor readings to PubNub.
<img align="right" src="https://uvindex.chandlermayo.com/pics/pubnub/debug_client.png" height="250">

7. Verify the sensor readings are making it to PubNub by going to your [PubNub Developer Portal](https://admin.pubnub.com/?devrel_gh=PubNub-UV-Index-Monitor ), select the keys your created previously, and create a client in the Debug Console. Set the 'Default Channel' to 'uvindex' and leave the other fields blank. Click 'ADD CLIENT'. You should see a message with the current UV index within 10 minutes or if the sensor reading changes. You can also reset the development board to force it to resend the current UV index value.

8. Move your UV index sensor to a sunny location within range of WiFi. If you need to place your sensor in a place without power you could use a USB power bank to deliver power to your development board.

#### UV Index Indicator

<img align="right" src="https://uvindex.chandlermayo.com/pics/indicator/IMG-6999.JPG" height="200">

The UV Index Indicator subscribes to the 'uvindex' channel and displays the UV index value using color. 0 = off, 1-2 = green, 3-5 = yellow, 6-7 = orange, 8-10 = red, and 11+ = purple.

1. Connect the common ground on the RGB LED to ground on your development board. Connect the red pin to pin 14, green pin to pin 12, and blue pin to pin 15.

2. Open [indicator/indicator.ino](https://github.com/chandler767/PubNub-UV-Index-Monitor/tree/master/indicator) in Arduino.

3. Replace "Sensor Network" and "sens0rpassw0rd" with the SSID and password for your WiFi network.

4. Get your unique PubNub keys from the [PubNub Developer Portal](https://admin.pubnub.com/?devrel_gh=PubNub-UV-Index-Monitor ). If you don't have a PubNub account, you can [sign up for a PubNub account](https://dashboard.pubnub.com/signup/?devrel_gh=PubNub-UV-Index-Monitor) for free. Replace "sub-key" with your key.

5. Upload the sketch. You can use the Serial Monitor to verify you're able to connect to WiFi and receive your sensor readings from PubNub. You should see a message with the current UV index within 10 minutes or if the sensor reading changes. You can also reset the sensor development board to force it to resend the current UV index value after a 60 second delay.

### Setup Dashboard

<img align="right" src="https://uvindex.chandlermayo.com/pics/app/ios/IMG-6919.JPG" height="250">

The dashboard is powered by [Project EON](https://www.pubnub.com/developers/eon/?devrel_gh=PubNub-UV-Index-Monitor) and shows the last five values from the UV index sensor. To setup your own dashboard you'll need to fork this repo and setup a new gh-pages site. Alternatively, you can host [index.html](https://github.com/chandler767/PubNub-UV-Index-Monitor/blob/gh-pages/index.html) in another location and follow step 3 below to configure. The dashboard for this repo is located here: https://uvindex.chandlermayo.com/ 

1. Fork this repo and clone.

2. Switch to the gh-pages branch.
```
git checkout gh-pages
```

3. Get your unique PubNub keys from the [PubNub Developer Portal](https://admin.pubnub.com/?devrel_gh=PubNub-UV-Index-Monitor ). If you don't have a PubNub account, you can [sign up for a PubNub account](https://dashboard.pubnub.com/signup/?devrel_gh=PubNub-UV-Index-Monitor) for free. Edit index.html and replace the subscribe key with your key.

4. Commit to the gh-pages branch to update your subscribe key and trigger a page build:
```
git add index.html
git push origin gh-pages
```

5. Your copy of the dashboard should now be online. Learn more about how to setup a GitHub Pages site [here.](https://help.github.com/categories/github-pages-basics/)

### Setup UVINFO React Native App

<img align="right" src="https://uvindex.chandlermayo.com/pics/app/ios/IMG-6917.JPG" height="330">

When the app is first opened it retrieves the last UV index value and displays that value so the user doesn't have to wait for the sensor to send a new message. Then each time the UV index is updated the app should refresh to display the new value. The app also displays the dashboard chart when the app is in landscape.

1. [Install React Native](https://facebook.github.io/react-native/docs/getting-started.html). Be sure to follow the guide for 'Building Projects with Native Code' to be able to install on a device. 

2. Get your unique PubNub keys from the [PubNub Developer Portal](https://admin.pubnub.com/?devrel_gh=PubNub-UV-Index-Monitor). If you don't have a PubNub account, you can [sign up for a PubNub account](https://dashboard.pubnub.com/signup/?devrel_gh=PubNub-UV-Index-Monitor) for free. 

3. Edit [UVINFO/App.js](https://github.com/chandler767/PubNub-UV-Index-Monitor/tree/master/UVINFO) and replace "sub-key" with your key and replace 'https://uvindex.chandlermayo.com/' with the url for your dashboard. Save the file.

4. Make sure you're in the UVINFO directory.
```
cd UVINFO
```

5. Install project dependencies.
```
npm install
```

6. Test the app in the iOS simulator. It may take some time to build the project.
```
react-native run-ios
```

7. [Follow this guide](https://facebook.github.io/react-native/docs/running-on-device.html) to install on your device (iOS or Android).

### iOS Push Notifications

<img align="right" src="https://uvindex.chandlermayo.com/pics/app/ios/IMG-7038.png" height="300">

Bridge native PubNub publishing with Apple Push Notification Service for iOS push notifications with React Native. Requires paid enrollment in the [Apple Developer Program](https://developer.apple.com/programs/). Receive push notifications when the UV index is very high (>7) and a maximum of once every 15 hours.

1. Using the [iOS push notification enabled fork of the repo](https://github.com/chandler767/PubNub-UV-Index-Monitor/tree/push-notifications-ios) follow the 'UV Index Sensor' instructions above.

2. Using the [iOS push notification enabled fork of the repo](https://github.com/chandler767/PubNub-UV-Index-Monitor/tree/push-notifications-ios) follow the 'Setup UVINFO React Native App' instructions above.

3. Provision [APNS and PubNub with tokens](https://www.pubnub.com/docs/web-javascript/mobile-gateway#apns-prerequisites-tokens?devrel_gh=PubNub-UV-Index-Monitor).

4. [Manually link](https://facebook.github.io/react-native/docs/pushnotificationios.html) the PushNotificationIOS library.

5. Install the app on a iOS device to test push notifications.

### Android Push Notifications

<img align="right" src="https://uvindex.chandlermayo.com/pics/app/android/Screenshot_1532055107.png" height="300">

Bridge native PubNub publishing with Firebase Cloud Messaging for Android push notifications with React Native. Receive push notifications when the UV index is very high (>7) and a maximum of once every 15 hours.

1. Using the [Android push notification enabled fork of the repo](https://github.com/chandler767/PubNub-UV-Index-Monitor/tree/push-notifications-android) follow the 'UV Index Sensor' instructions above.

2. Using the [Android push notification enabled fork of the repo](https://github.com/chandler767/PubNub-UV-Index-Monitor/tree/push-notifications-android) follow the 'Setup UVINFO React Native App' instructions above.

3. Visit the [Firebase console](https://firebase.google.com/console).

4. Click on the 'Add project' box.

5. Enter project details and press the continue button.

6. Go to your [PubNub Developer Portal](https://admin.pubnub.com/?devrel_gh=PubNub-UV-Index-Monitor) and enable Mobile Push Notifications for the key you created for setting up the app. Enter your API key from the project you created in the [Firebase console](https://firebase.google.com/console).

7. Run the app in the Android Emulator or on a device to test push notifications.
