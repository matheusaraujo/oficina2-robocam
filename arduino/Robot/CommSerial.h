#define CommSerial_h

#define bit9600Delay 84  
#define halfBit9600Delay 42
#define bit4800Delay 188 
#define halfBit4800Delay 94

class CommSerial{
    private:
        char _RX;
        char _TX;
    public:
        CommSerial();
        void write(int data);
        int read();

};
