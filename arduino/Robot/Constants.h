/*

    # ROBOCAM 1.0 - UTFPR, 2011-02
    # L. Camargo, M. Teider, M. Araujo

    Constants.h
    Armazena as constantes da Biblioteca

*/

class Constants{

	public:

	    /*
    	    constantes para os comandos do robô
	    */
    	static const int FORWARD = 1;
	    static const int BACKWARD = 2;
    	static const int SPINLEFT = 3;
	    static const int SPINRIGHT = 4;
	    static const int STOP = 5;
	    static const int COMPASS = 6;
	    static const int ADJUSTLEFT = 7;
	    static const int ADJUSTRIGHT = 8;


    	/*
        	constantes para a leitura da bússola
	    */

		static const int NORTH = 1;
		static const int NORTHEAST = 2;
		static const int EAST = 3;
		static const int SOUTHEAST = 4;
		static const int SOUTH = 5;
		static const int SOUTHWEST = 6;
		static const int WEST = 7;
		static const int NORTHWEST = 8;

};
