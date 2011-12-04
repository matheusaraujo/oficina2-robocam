/*

    # ROBOCAM 1.0 - UTFPR, 2011-02
    # L. Camargo, M. Teider, M. Araujo

    Robot.h
    Classe central da biblioteca

*/

#define Robot_h

#include "WProgram.h"
#include "pitches.h"
#include "util/delay.h"


#include "Constants.h"

#include "Compass.h"
#include "Indicator.h"
#include "Motor.h"

#include "CommSerial.h"

/*
    PINAGEM DO ARDUÍNO:
    MOTOR ESQUERDO, FRENTE: PINO 6 M1P1
    MOTOR ESQUERDO, TRÁS: PINO 5 M1P2
    MOTOR DIREITO, FRENTE: 11 M2P1
    MOTOR DIREITO, TRÁS: 10 M2P2
    LED ESQUERDO: PINO 2
    LED DIREITO: PINO 4
    SPEAKER: PINO 8
*/

class Robot
{
    private:

		Compass compass;
		Motor motor;
		Indicator indicator;

    public:

        Robot();

        void start();
        void finish();
        void move(int moviment);
        void move(int moviment, int tdelay);
		int orientation();

		void test();
};
