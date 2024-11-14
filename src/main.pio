#include <Arduino.h>
#include <Wire.h>

#define ADDRESS 0x41  // slave address
#define SDA 21
#define SDL 22
#define FREQUENCY 400000

void setup(){
    // set up SDA and SDL
    Wire.begin();
    Wire.setPins(SDA, SDL);

    Wire.setClock(FREQUENCY);
    Serial.begin(115200);
}

void loop(){
    // the byte to be sent to pi pico
    uint8_t message = 0x15;

    // send the data
    Wire.beginTransmission(ADDRESS);
    Wire.write(message);

    // check for errors in transmission
    int error = Wire.endTransmission();
    switch(error) {
        case 0:
            Serial.println("Transmission successful");
            break;
        case 1:
            Serial.println("NACK on transmit of address");
            break;
        case 2:
            Serial.println("NACK after transmit of data byte");
            break;
        case 3:
            Serial.println("Master mode function disallowed");
            break;
        case 4:
            Serial.println("Bus error");
            break;
        case 5:
            Serial.println("Overrun error");
            break;
        default:
            Serial.println("Unknown error");
    }

    delay(1000);

    Wire.requestFrom(ADDRESS,1);

    byte data = Wire.read();  // Read the byte received
    Serial.print("Data received: ");
    Serial.println(data);

    delay(1000);
}