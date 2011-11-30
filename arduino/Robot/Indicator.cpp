/*

    # ROBOCAM 1.0 - UTFPR, 2011-02
    # L. Camargo, M. Teider, M. Araujo

    Indicator.cpp
    Aciona os indicadores do robô - LEDs e speaker

*/

#include "Motor.h"
#include "Constants.h"
#include "utils/delay.h"

#include "WProgram.h"

Indicator::Indicator(){

    _LED_L = 12;
    _LED_R = 4;

    _SPEAKER = 13;

    pinMode(_LED_L, OUTPUT);
    pinMode(_LED_R, OUTPUT);
    pinMode(_SPEAKER, OUTPUT);

}

void Indicator::led(bool left, bool right){
    digitalWrite(_LED_L, left ? HIGH : LOW);
    digitalWrite(_LED_R, right ? HIGH : LOW);
}

void Indicator::ledmotor(int moviment){
    if (moviment == Constants.FORWARD)
        led(true, true);
    else if (moviment == Constants.BACKWARD)
        led(true, true);
    else if (moviment == SPINLEFT)
        led(true, false);
    else if (moviment == Constants.SPINRIGHT)
        led(false, true);
    else if (moviment == Constants.STOP)
        led(false, false);
    else if (moviment == Constants.ADJUSTLEFT)
        led(true, false);
    else if (moviment == Constants.ADJUSTRIGHT)
        led(false, true);
}

void Indicator::playsound(int melody[], int duration[], int length){

    for(int i = 0, led = true; i < length; i++, led = !led){

        led(led, !led);

        int nduration = 1000/(duration[i]);
        int pause = nduration * 1.30;

        tone(_SPEAKER, melody[i], nduration);
        _delay_ms_(pause);

        noTone(_SPEAKER);

    }

    led(false, false);

}


