#ifndef SENDER_DEF
#define SENDER_DEF

class DigitalSender{
    public:
        DigitalSender(void){};
        virtual bool send(bool pattern) = 0;
};

#endif