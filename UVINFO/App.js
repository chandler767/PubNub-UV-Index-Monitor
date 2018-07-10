/**
 * UV Index
 * https://github.com/chandler767/PubNub-UV-Index-Monitor
 *
 */

import React, {Component} from 'react';
import {Platform, StyleSheet, Text, View, Dimensions, WebView} from 'react-native';

import PubNubReact from 'pubnub-react';

type Props = {};
export default class App extends Component<Props> {
  
  constructor(props) {
    super(props);
    this.state = {
         uvindex: 0,
         uvindexcolor: '#90EE90',
         hidewebview: false,
      }
    // Init PubNub. Use your subscribeKey here.
    this.pubnub = new PubNubReact({
        subscribeKey: 'sub-c-f6b3e9d0-83b9-11e8-ac0f-0e4b9865ddaa'
    });
    this.pubnub.init(this);
  }

  componentWillMount() {
    // Subscribe to uvindex channel and get messages.
    this.pubnub.subscribe({
        channels: ['uvindex']     
    });
    // Update when a new value is received.
    this.pubnub.getMessage('uvindex', (msg) => {
      this.UpdateUV(msg.message.uvindex)
    });
    // Get and display last UV Index value.
    this.pubnub.history(
      {
          channel: 'uvindex',
          count: 1,
      },
      function (status, response) {
        if (status.statusCode == 200) {
          this.UpdateUV(response.messages[0].entry.uvindex)
        }
      }.bind(this)
    );
  }

  componentWillUnmount() {
    // Unubscribe to uvindex channel.
    this.pubnub.unsubscribe({
        channels: ['uvindex']
    });
  }

  componentDidMount(){
    // Check the device orientation on load.
    this.DetectOrientation();
  }

  DetectOrientation(){
    // Hide and show webview.
    if(Dimensions.get('window').width > Dimensions.get('window').height) // Landscape - Show webview.
    {
      this.setState({
        hidewebview: true,
      });
    } else { // Portrait - Hide webview.
      this.setState({
        hidewebview: false,
      });
    }
  }

  // Update the UV Index label and set background color.
  UpdateUV(uvindex){
    this.setState({uvindex: uvindex})
    if (uvindex < 3) { // Low 0-2
      this.setState({uvindexcolor: '#90EE90'}); // Green
    } else if ((uvindex >= 3) && (uvindex < 6)) { // Moderate 3-5
      this.setState({uvindexcolor: '#FFFF00'}); // Yellow
    } else if ((uvindex >= 6) && (uvindex < 8)) { // High 6-7
      this.setState({uvindexcolor: '#FFBE4D'}); // Orange
    } else if ((uvindex >= 8) && (uvindex < 11)) { // Very High 8-10
      this.setState({uvindexcolor: '#FF9999'}); // Red
    } else if (uvindex >= 11) { // Extreme 11+
      this.setState({uvindexcolor: '#FF99FF'}); // Purple
    };
  }

  render() {
    return (
      //Display the UV Index
      <View style={[styles.container, {backgroundColor: this.state.uvindexcolor}]} onLayout={(event) => this.DetectOrientation()}>
        <Text style={styles.welcome}>UV Index</Text>
        <Text style={styles.uvindex}>{this.state.uvindex}</Text>
        {
          this.state.hidewebview ? 
          <View style={styles.webcontainer}>
            <WebView
              style={styles.webview}
              source={{uri: 'https://uvindex.chandlermayo.com/'}}
              scalesPageToFit
              javaScriptEnabled
              domStorageEnabled
              startInLoadingState/>
          </View> : null
        }
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
  welcome: {
    fontSize: 45,
    textAlign: 'center',
    margin: 10,
    paddingTop: 25,
  },
  uvindex: {
    textAlign: 'center',
    fontSize: 60,
    marginBottom: 15,
  },
  webcontainer: {
    top: 0,
    left: 0,
    bottom: 0,
    right: 0,
    position: 'absolute',
    alignItems: 'flex-start',
  },
  webview: {
    top: 0,
    left: 0,
    position: 'absolute',
    height: '100%',
    width: '100%',
  },
});
