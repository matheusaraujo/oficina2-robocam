#include "CommSerial.h"

#include "WProgram.h"

CommSerial::CommSerial(){
    _RX = 0;
    _TX = 1;
    
    pinMode(_RX, INPUT);
    pinMode(_TX, OUTPUT);
}

void CommSerial::write(int data){
    
    byte mask;
    
    // bit de início
    digitalWrite(_TX,LOW);
    delayMicroseconds(bit9600Delay);
    
    for (mask = 0x01; mask>0; mask <<= 1) {
        if (data & mask){ // escolha bit
            digitalWrite(_TX,HIGH); // envie 1
        }
        else{
            digitalWrite(_TX,LOW); // envie 0
        }
        delayMicroseconds(bit9600Delay);
    }

    // bit de parada
    digitalWrite(_TX, HIGH);
    delayMicroseconds(bit9600Delay);
    
}

int CommSerial::read(){
    byte val = 0;
    
    while (digitalRead(_RX));
    
    //wait for start bit
    if (digitalRead(_RX) == LOW) {
        delayMicroseconds(halfBit9600Delay);
        for (int offset = 0; offset < 8; offset++) {
            delayMicroseconds(bit9600Delay);
            val |= digitalRead(_RX) << offset;
        }

        //wait for stop bit + extra
        delayMicroseconds(bit9600Delay); 
        delayMicroseconds(bit9600Delay);
    
        return val;
    }
    
}
