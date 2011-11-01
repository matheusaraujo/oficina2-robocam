#define Robot_h

#include "WProgram.h"
#include "pitches.h"
#include "Compass.h"

/*
    PINAGEM DO ARDUÍNO:
    MOTOR ESQUERDO, FRENTE: PINO 6 M1P1
    MOTOR ESQUERDO, TRÁS: PINO 5 M1P2
    MOTOR DIREITO, FRENTE: 11 M2P1
    MOTOR DIREITO, TRÁS: 10 M2P2
    LED ESQUERDO: PINO 2
    LED DIREITO: PINO 4
    SPEKAR: PINO 8
*/

class Robot
{
    private:
        void setled(bool left, bool right);        
        void setmotor(bool m1p1, bool m1p2, bool m2p1, bool m2p2);
        char _MOTOR1_PIN1;
        char _MOTOR1_PIN2;
        char _MOTOR2_PIN1;
        char _MOTOR2_PIN2;
        char _LED_L;
        char _LED_R;
        char _SPEAKER;
        bool _m1p1;
        bool _m1p2;
        bool _m2p1;
        bool _m2p2;
		int spin_tolerance; // ciclos de tolerância no spin
		Compass compass;
    public:
        Robot();
        void start();
        void finish();
        void playsound(int melody[], int duration[], int length);        
        void forward();
        void forward(int tdelay);
        void backward();
        void backward(int tdelay);
        void turnleft();
        void turnleft(int tdelay);
        void turnright(); 
        void turnright(int tdelay);
		void spinleft();
		void spinleft(int tdelay);
		void spinright();
		void spinright(int tdelay);
        void stop();
        void forcestop();
		void test();
};
