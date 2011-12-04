/*

    # ROBOCAM 1.0 - UTFPR, 2011-02
    # L. Camargo, M. Teider, M. Araujo

    Motor.h
    Aciona os motores do robô

*/

#define Motor_h

class Motor{

    private:

        char _MOTOR1_PIN1;
        char _MOTOR1_PIN2;
        char _MOTOR2_PIN1;
        char _MOTOR2_PIN2;

        void setmotor(bool m1p1, bool m1p2, bool m2p1, bool m2p2);
        void setmotor(bool m1p1, bool m1p2, bool m2p1, bool m2p2, int pwm1, int pwm2);

    public:

        Motor();
        void move(int moviment);
        void move(int moviment, int tdelay);
        void stop();

		void test();

};
