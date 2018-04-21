#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char * ssid = "Startup Zone Wifi";
const char * password = "sz-events-1234";
const int buttonPin = D5;
const int ledPin = D3;
int buttonState = 0;
unsigned long previousMillis = 0;
const long interval = 5000;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval)
    {
      previousMillis = currentMillis;
      if (WiFi.status() == WL_CONNECTED)
      {
        sendMessage();
      }
    }
  } else {
    digitalWrite(ledPin, LOW);
  }
}

void sendMessage() {
  HTTPClient http;
  http.begin("http://codefestfirehost.000webhostapp.com");
  int httpCode = http.GET();
  if (httpCode > 0) {
    String payload = http.getString();
    Serial.println(payload);
  }
  http.end();
}

