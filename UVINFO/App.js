/**
 * UV Index
 * https://github.com/chandler767/PubNub-UV-Index-Monitor
 *
 */

import React, {Component} from 'react';
import {Platform, StyleSheet, Text, View} from 'react-native';

import PubNubReact from 'pubnub-react';

type Props = {};
export default class App extends Component<Props> {
  
  constructor(props) {
    super(props);
    this.state = {
         uvindex: 0,
         uvindexcolor: '#90EE90'
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
    // Update the UV Index label and set background color.
    this.pubnub.getMessage('uvindex', (msg) => {
        this.setState({uvindex: msg.message.uvindex})
        if (msg.message.uvindex < 3) { // Low 
          this.setState({uvindexcolor: '#90EE90'}) // Green
        } else if ((msg.message.uvindex >= 3) && (msg.message.uvindex < 6)) { // Moderate
          this.setState({uvindexcolor: '#FFFF00'}) // Yellow
        } else if ((msg.message.uvindex >= 6) && (msg.message.uvindex < 8)) { // High
          this.setState({uvindexcolor: '#FFBE4D'}) // Orange
        } else if ((msg.message.uvindex >= 8) && (msg.message.uvindex < 11)) { // Very High
          this.setState({uvindexcolor: '#FF9999'}) // Red
        } else if (msg.message.uvindex >= 11) { // Extreme
          this.setState({uvindexcolor: '#FF99FF'}) // Purple
        }
    });
  }

  componentWillUnmount() {
    // Unubscribe to uvindex channel.
    this.pubnub.unsubscribe({
        channels: ['uvindex']
    });
  }

  render() {
    return (
      //Display the UV Index
      <View style={[styles.container, {backgroundColor: this.state.uvindexcolor}]}>
        <Text style={styles.welcome}>UV Index</Text>
        <Text style={styles.uvindex}>{this.state.uvindex}</Text>
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
});
