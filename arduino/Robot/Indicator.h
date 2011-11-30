/*

    # ROBOCAM 1.0 - UTFPR, 2011-02
    # L. Camargo, M. Teider, M. Araujo

    Indicator.h
    Aciona os indicadores do robô - LEDs e speaker

*/

class Indicator{

    private:

        byte _LED_L;
        byte _LED_R;
        byte _SPEAKER;

    public:

        Indicator();
        void led(bool left, bool right);
        void ledmotor(int moviment);
        void playsound(int melody[], int duration[], int length);

};
