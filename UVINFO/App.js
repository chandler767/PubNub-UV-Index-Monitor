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
    this.pubnub = new PubNubReact({
        subscribeKey: 'sub-c-f6b3e9d0-83b9-11e8-ac0f-0e4b9865ddaa'
    });
    this.pubnub.init(this);
  }

  componentWillMount() {
    this.pubnub.subscribe({
        channels: ['uvindex'],
        withPresence: true       
    });

    this.pubnub.getMessage('uvindex', (msg) => {
        this.setState({uvindex: msg.message.uvindex})
    });
  }

  componentWillUnmount() {
    this.pubnub.unsubscribe({
        channels: ['uvindex']
    });
  }

  render() {
    return (
      <View style={styles.container}>
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
    backgroundColor: {this.state.uvindexcolor},
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
