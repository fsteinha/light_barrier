#include <iostream>
#include "DigitalSender.hpp"


class TestSender: public DigitalSender
{
private:
    /* data */
public:
    TestSender(): DigitalSender(){};
    ~TestSender(){};
    bool send(bool pattern) override {
        std::cout << pattern;
        return true;
    }
};
