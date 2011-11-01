#include "Robot.h"

Robot::Robot(){    

    _MOTOR1_PIN1 = 6;
    _MOTOR1_PIN2 = 5;

    _MOTOR2_PIN1 = 11;
    _MOTOR2_PIN2 = 10;

    _LED_L = 12;
    _LED_R = 4;

    _SPEAKER = 13;

    pinMode(_MOTOR1_PIN1, OUTPUT);
    pinMode(_MOTOR1_PIN2, OUTPUT);

    pinMode(_MOTOR2_PIN1, OUTPUT);
    pinMode(_MOTOR2_PIN2, OUTPUT);

    pinMode(_LED_L, OUTPUT);
    pinMode(_LED_R, OUTPUT);

	spin_tolerance = 1500;
}

void Robot::setled(bool left, bool right){
    digitalWrite(_LED_L, left ? HIGH : LOW);
    digitalWrite(_LED_R, right ? HIGH : LOW);
}

void Robot::setmotor(bool m1p1, bool m1p2, bool m2p1, bool m2p2){

    // proteção do motor, dois 1 na mesma ponte H dá zica
    if ((m1p1 && m1p2) || (m2p1 && m2p2))
        return;
    
    _m1p1 = m1p1;
    _m1p2 = m2p2;
    _m2p1 = m2p1;
    _m2p2 = m2p2;    

/*    digitalWrite(_MOTOR1_PIN1, m1p1 ? HIGH : LOW);
    digitalWrite(_MOTOR1_PIN2, m1p2 ? HIGH : LOW);
    digitalWrite(_MOTOR2_PIN1, m2p1 ? HIGH : LOW);
    digitalWrite(_MOTOR2_PIN2, m2p2 ? HIGH : LOW); */
	analogWrite(_MOTOR1_PIN1, m1p1 ? 127 : 0);
	analogWrite(_MOTOR1_PIN2, m1p2 ? 127 : 0);
	analogWrite(_MOTOR2_PIN1, m2p1 ? 127 : 0);
	analogWrite(_MOTOR2_PIN2, m2p2 ? 127 : 0);
}

void Robot::start(){
    
    int melody[] = {
        NOTE_G4, NOTE_G4, NOTE_G4, NOTE_DS4, 0,
        NOTE_F4, NOTE_F4, NOTE_F4, NOTE_D4, 0,
        NOTE_G4, NOTE_G4, NOTE_G4, NOTE_DS4, NOTE_GS4,
        NOTE_GS4, NOTE_GS4, NOTE_G4, NOTE_DS5, NOTE_DS5,
        NOTE_DS5, NOTE_C5, 0, NOTE_G4, NOTE_G4,
        NOTE_G4, NOTE_D4, NOTE_GS4, NOTE_GS4, NOTE_GS4,
        NOTE_G4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_D5,
        0, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_DS5,
        0, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_DS5
    };

    int duration[] = {
        4, 4, 4, 1, 1,
        4, 4, 4, 1, 1,
        4, 4, 4, 4, 4,
        4, 4, 4, 4, 4,
        4, 1, 2, 4, 4,
        4, 4, 4, 4, 4,
        4, 4, 4, 4, 1,
        2, 4, 4, 4, 1,
        2, 4, 4, 4, 1
    };

    playsound(melody, duration, 45);
}

void Robot::finish(){
    int melody[] = {
        NOTE_B4, 0, NOTE_B5, 0, NOTE_FS5,
        0, NOTE_DS5, 0, NOTE_B5, NOTE_FS5,
        0, NOTE_DS5, 0, NOTE_C5, 0,
        NOTE_C6, 0, NOTE_G5, 0, NOTE_E5,
        0, NOTE_C6, NOTE_G5, 0, NOTE_E5,
        0, NOTE_B2, 0, NOTE_B3, 0,
        NOTE_FS5, 0, NOTE_DS5, 0, NOTE_B5,
        NOTE_FS5, 0, NOTE_DS5, 0, NOTE_DS5,
        NOTE_E5, NOTE_F5, 0, NOTE_F5, NOTE_FS5,
        NOTE_G5, 0, NOTE_G5, NOTE_GS5, NOTE_A5
    };
    int duration[] = {
        8, 8, 8, 8, 8,
        8, 8, 8, 8, 8,
        4, 4, 4, 8, 8,
        8, 8, 8, 8, 8,
        8, 8, 8, 4, 4,
        4, 8, 8, 8, 8,
        8, 8, 8, 8, 8,
        8, 4, 4, 4, 8,
        8, 8, 8, 8, 8,
        8, 8, 8, 8, 8
    };
    
    playsound(melody, duration, 50);
}

void Robot::playsound(int melody[], int duration[], int length){    
    for(int i = 0, led = true; i < length; i++, led = !led){
        setled(led, !led);        
        int nduration = 1000/(duration[i]);
        tone(_SPEAKER, melody[i], nduration);
        int pause = nduration * 1.30;
        delay(pause);
        noTone(_SPEAKER);    
    }
    setled(false, false);
}

void Robot::forward(){
    setled(true, true);
    setmotor(true, false, true, false);    
}

void Robot::forward(int tdelay){
    forward();
    delay(tdelay);
    stop();
}

void Robot::backward(){
    setled(true, true);
    setmotor(false, true, false, true);
}

void Robot::backward(int tdelay){
    backward();
    delay(tdelay);
    stop();
}

void Robot::turnleft(){
    setled(true, false);
    setmotor(true, false, false, false);
}

void Robot::turnleft(int tdelay){
    turnleft();
    delay(tdelay);
    stop();
}

void Robot::turnright(){
    setled(false, true);
    setmotor(false, false, true, false);
}

void Robot::turnright(int tdelay){
    turnright();
    delay(tdelay);
    stop();
}

void Robot::spinleft(){
	setled(true, false);
	setmotor(true, false, false, true);
}

void Robot::spinleft(int tdelay){
	spinleft();
	delay(tdelay);
	stop();
}

void Robot::spinright(){
	setled(false, true);
	setmotor(true, false, true, false);
}

void Robot::spinright(int tdelay){
	spinright();
	delay(tdelay);
	stop();
}

void Robot::stop(){
    setled(false, false);
    setmotor(false, false, false, false);
}

void Robot::forcestop(){
    setled(true, true);
    setmotor(!_m1p1, !_m1p2, !_m2p1, !_m2p2);
    delay(100);
    setled(false, false);
    setmotor(false, false, false, false);
}

void Robot::test(){
	int oo = compass.orientation();
	int o = oo;
	int c = 0;
	int t = 50;
	spinleft();
	while(c < spin_tolerance){
		o = compass.orientation();
		if (o != oo) c++;
		else c = 0;
	}

	stop();
}
