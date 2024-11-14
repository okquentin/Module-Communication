#include <Arduino.h>
#include <Wire.h>

#define ADDRESS 0x41 // slave address
byte error;
int lineNum = 0;
uint8_t message = 0x41; 
bool sent = false;
//char message[] = "Hello Kaden\0";
//short mesLen;
//byte val = 8;

void checkError(byte error);

void setup(){
    Wire.begin(21, 22);
    Wire.setClock(400000); 
    Serial.begin(115200);
}

void loop(){
    // Writing
    Wire.beginTransmission(ADDRESS);
    Wire.write(message);
    error = Wire.endTransmission();
    Serial.printf("[%d] ", lineNum++);
    checkError(error);

    delay(1000);

    // READING
    // if(sent){
    //     Wire.requestFrom(ADDRESS,1);    //strlen(message)
    //     while (Wire.available()) {
    //         byte data = Wire.read();  // Read the byte received
    //         Serial.print("Data received: ");
    //         Serial.println(data);
    //     }
    // }


    //delay(1000);  // Wait for a second before requesting again

    // WHATEVER THIS IS
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

void checkError(byte error){
    switch(error) {
        case 0:
            Serial.println("Transmission successful");
            sent = true;
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
}