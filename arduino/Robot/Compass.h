/*

    # ROBOCAM 1.0 - UTFPR, 2011-02
    # L. Camargo, M. Teider, M. Araujo

    Compass.h
    Faz a leitura do sinal da bússola e retorna para a biblioteca

*/

#define Compass_h

class Compass{

	private:

		byte _PIN1;
		byte _PIN2;
		byte _PIN3;
		byte _PIN4;

	public:

		Compass();
		int orientation();

};
