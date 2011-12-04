/*

    # ROBOCAM 1.0 - UTFPR, 2011-02
    # L. Camargo, M. Teider, M. Araujo

    Compass.cpp
    Faz a leitura do sinal da bússola e retorna para a biblioteca

*/

#include "Compass.h"

#include "WProgram.h"

Compass::Compass(){

	_PIN1 = 8;
	_PIN2 = 9;
	_PIN3 = 2;
	_PIN4 = 3;

	pinMode(_PIN1, INPUT);
	pinMode(_PIN2, INPUT);
	pinMode(_PIN3, INPUT);
	pinMode(_PIN4, INPUT);

}

int Compass::orientation(){

	return digitalRead(_PIN1) +
        2 * digitalRead(_PIN2) +
        4 * digitalRead(_PIN3) +
        8 * digitalRead(_PIN4);
}
