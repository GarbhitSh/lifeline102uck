import React from 'react';
import { StyleSheet, View, Text } from 'react-native';
import { WebView } from 'react-native-webview';
import Constants from 'expo-constants';
import { NavigationContainer } from '@react-navigation/native';

export default function App() {
  return (
    <NavigationContainer>
      <View style={styles.container}>
        <View style={styles.header}>
          <Text style={styles.headerText}>Lifeline</Text>
        </View>
        <WebView
          source={{ uri: 'https://app.arduino.cc/dashboards/4ce1880c-134f-4a24-9dd4-905e47fa41db?mode=edit' }}
          style={styles.webview}
        />
        <View style={styles.footer}>
          <Text style={styles.footerText}>Buddy</Text>
        </View>
      </View>
    </NavigationContainer>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    paddingTop: Constants.statusBarHeight,
  },
  header: {
    backgroundColor: 'blue',
    paddingVertical: 10,
    alignItems: 'center',
  },
  headerText: {
    color: '#fff',
    fontSize: 18,
    fontWeight: 'bold',
  },
  webview: {
    flex: 1,
    width: '100%',
  },
  footer: {
    backgroundColor: 'blue',
    paddingVertical: 10,
    alignItems: 'center',
  },
  footerText: {
    color: '#fff',
    fontSize: 18,
    fontWeight: 'bold',
  },
});
