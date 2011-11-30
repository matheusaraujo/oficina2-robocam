/*

    # ROBOCAM 1.0 - UTFPR, 2011-02
    # L. Camargo, M. Teider, M. Araujo

    Robot.cpp
    Classe central da biblioteca

*/

#include "Robot.h"

Robot::Robot(){

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

void Robot::move(int moviment){
    indicator.ledmotor(moviment);
    motor.move(moviment);
}

void Robot::move(int moviment, int tdelay){
    indicator.ledmotor(moviment);
    motor.move(moviment, tdelay);
}

int Robot::orientation(){
    return compass.orientation();
}

void Robot::test(){
	int oo = compass.orientation();
	int o = oo;

	forward();

	while(o == oo){
		o = compass.orientation();
	}

	stop();
}


