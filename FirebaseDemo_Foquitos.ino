//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "periodico-1526305808923.firebaseio.com"
#define FIREBASE_AUTH "dXPG7cRyS5OmAenCsnIK9QABNjuRwdQRXLKK66Mj"
#define WIFI_SSID "COMTECO-N2840396"
#define WIFI_PASSWORD "DIMQR13816"


void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  pinMode(2, OUTPUT);

  pinMode(16, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(14, INPUT); //BOTONES
  pinMode(12, INPUT);
}

int n = 0;
int estado=0;
int estado2=0;

void loop() {
  estado=digitalRead(14);
  Firebase.setFloat("led1", estado);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  
  // leds 
  if(Firebase.getFloat("led1"))
  {
    digitalWrite(16, LOW);
  }
  else{
    digitalWrite(16, HIGH);
  }

  estado2=digitalRead(12);
  Firebase.setFloat("led2", estado2);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  
  // leds 
  if(Firebase.getFloat("led2"))
  {
    digitalWrite(5, LOW);
  }
  else{
    digitalWrite(5, HIGH);
  }

   // get value 
  if(Firebase.getFloat("led"))
  {
    digitalWrite(2, LOW);
  }
  else{
    digitalWrite(2, HIGH);
  }
  
  // set value
  /*Firebase.setFloat("number", 7);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(500);
  
  // update value
  Firebase.setFloat("number", 27.0);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  
  /*delay(500);

 
  // remove value
  Firebase.remove("number");
  delay(100);

  // set string value
  Firebase.setString("message", "Alex7 Tutoriales");
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /message failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(500);

  
  // set string value
  Firebase.setString("message", "Suscribete");
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /message failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(500);
  
  // set bool value
  Firebase.setBool("truth", false);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /truth failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  // append a new value to /logs
  String name = Firebase.pushInt("logs", n++);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
  }
  Serial.print("pushed: /logs/");
  Serial.println(name);
  delay(1000);*/
  
}
