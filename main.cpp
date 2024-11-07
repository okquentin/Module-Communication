#include <Arduino.h>
#include <Wire.h>

#define ADDRESS 0x41        // slave address
//short mesLen;
//byte val = 8;

void setup(){
    Wire.begin(21, 22);
    Wire.setClock(400000);

    Serial.begin(115200);
}

void loop(){
    //char message[] = "Hello Kaden\0";

    uint8_t message = 0x15;

    Wire.beginTransmission(ADDRESS);
    // send the data
    Wire.write(message);
    Wire.endTransmission();
    if (Wire.endTransmission() != 0) {
        Serial.println("Transmission failed");
    } else {
        Serial.println("Data Sent");
    }

    delay(1000);

    Wire.requestFrom(ADDRESS,1);    //strlen(message)

    while (Wire.available()) {
        byte data = Wire.read();  // Read the byte received
        Serial.print("Data received: ");
        Serial.println(data);
    }

    delay(1000);  // Wait for a second before requesting again
    //char retMes[mesLen];

    // int index = 0;
    // if (Wire.available()){
    //     while(Wire.available()){
    //     retMes[index] = Wire.read();
    //     index++;
    //     }
    //     retMes[index] = '\0';

    //     Serial.println("Data Received");
    //     Serial.println(retMes);
    // }

    //delay(1000);
}