/*

    # ROBOCAM 1.0 - UTFPR, 2011-02
    # L. Camargo, M. Teider, M. Araujo

    Motor.cpp
    Aciona os motores do robô

*/

#include "Motor.h"
#include "Constants.h"

#include "util/delay.h"

#include "WProgram.h"

Motor::Motor(){

    _MOTOR1_PIN1 = 5;
    _MOTOR1_PIN2 = 6;

    _MOTOR2_PIN1 = 11;
    _MOTOR2_PIN2 = 10;

    pinMode(_MOTOR1_PIN1, OUTPUT);
    pinMode(_MOTOR1_PIN2, OUTPUT);

    pinMode(_MOTOR2_PIN1, OUTPUT);
    pinMode(_MOTOR2_PIN2, OUTPUT);

}

void Motor::setmotor(bool m1p1, bool m1p2, bool m2p1, bool m2p2, int pwm1, int pwm2){

    /*
        proteção para o motor
        os dois pinos do motor em alto danificam o equipamento
    */

    if ((m1p1 && m1p2) || (m2p1 && m2p2))
        return;

	analogWrite(_MOTOR1_PIN1, m1p1 ? 255 * pwm1 / 100 : 0);
	analogWrite(_MOTOR1_PIN2, m1p2 ? 255 * pwm1 / 100 : 0);
	analogWrite(_MOTOR2_PIN1, m2p1 ? 255 * pwm2 / 100 : 0);
	analogWrite(_MOTOR2_PIN2, m2p2 ? 255 * pwm2 / 100 : 0);

}

void Motor::setmotor(bool m1p1, bool m1p2, bool m2p1, bool m2p2){
    setmotor(m1p1, m1p2, m2p1, m2p2, 75, 75);
}

void Motor::move(int moviment){
    if (moviment == Constants::FORWARD)
        setmotor(true, false, true, false);
    else if (moviment == Constants::BACKWARD)
        setmotor(false, true, false, true);
    else if (moviment == Constants::SPINLEFT)
        setmotor(false, true, true, false);
    else if (moviment == Constants::SPINRIGHT)
        setmotor(true, false, false, true);
    else if (moviment == Constants::STOP)
        setmotor(false, false, false, false);
    else if (moviment == Constants::ADJUSTLEFT)
        setmotor(true, false, true, false, 40, 60);
    else if (moviment == Constants::ADJUSTRIGHT)
        setmotor(true, false, true, false, 60, 40);
}

void Motor::move(int moviment, int tdelay){
    move(moviment);
    _delay_ms(tdelay);
    move(Constants::STOP);
}

void Motor::stop(){
    move(Constants::STOP);
}
