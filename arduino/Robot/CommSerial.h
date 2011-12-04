#define CommSerial_h

class CommSerial{
    private:
    public:
        CommSerial();
        void write(int data);
        int read();
};
