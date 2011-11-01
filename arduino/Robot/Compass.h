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
