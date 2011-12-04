/*

    # ROBOCAM 1.0 - UTFPR, 2011-02
    # L. Camargo, M. Teider, M. Araujo

    Compass.h
    Faz a leitura do sinal da bússola e retorna para a biblioteca

*/

#define Compass_h

class Compass{

	private:

		char _PIN1;
		char _PIN2;
		char _PIN3;
		char _PIN4;

	public:

		Compass();
		int orientation();

};
