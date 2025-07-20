#include "BluetoothSerial.h"

BluetoothSerial SerialBT; 

#define BULB_1 5
#define BULB_2 18

void setup() {
  Serial.begin(115200);

  SerialBT.begin("ESP32_HOME_AUTOMATION");
  Serial.println("Bluetooth is ready. Pair and send commands!");

  pinMode(BULB_1, OUTPUT);
  pinMode(BULB_2, OUTPUT);
  digitalWrite(BULB_1, HIGH);
  digitalWrite(BULB_2, HIGH);
}

void loop() {

  if (SerialBT.available()) {

    char received = SerialBT.read(); 

    if (received == 'A') {
      digitalWrite(BULB_1, LOW); // Turn LED ON
      SerialBT.println("BULB_1 ON");
      Serial.println("BULB_1 ON");
    } 
    else if (received == 'a') {
      digitalWrite(BULB_1, HIGH); // Turn LED OFF
      SerialBT.println("BULB_1 OFF");
      Serial.println("BULB_1 OFF");
    }
     else if (received == 'B') {
      digitalWrite(BULB_2, LOW); // Turn LED OFF
      SerialBT.println("BULB_2 ON");
      Serial.println("BULB_2 ON");
    }
     else if (received == 'b') {
      digitalWrite(BULB_2, HIGH); // Turn LED OFF
      SerialBT.println("BULB_2 OFF");
      Serial.println("BULB_2 OFF");
    }
     else {
      SerialBT.println("Invalid Command! Use '1' to ON, '0' to OFF.");
    }
  }
}
