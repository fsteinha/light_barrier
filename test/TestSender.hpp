#include <iostream>
#include "DigitalSender.hpp"


class TestSender: public DigitalSender
{
private:
    /* data */
    bool was_send = false;
public:
    TestSender(): DigitalSender(){};
    ~TestSender(){};
    bool send(bool pattern) override {
        std::cout << pattern;
        this->was_send = pattern;
        return true;
    }

    bool wasSend() {
        return this->was_send;
    }
};
