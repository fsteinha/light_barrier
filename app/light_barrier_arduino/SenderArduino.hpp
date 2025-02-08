#ifndef SENDER_ARDUINO_HPP
#define SENDER_ARDUINO_HPP

#include <Ardunio.h>
#include "digital_sender.hpp"

class SenderArduino(): public DigitalSender
{
private:
    /* data */
    int pin_out;
public:
    SenderArduino(int pin_out) pin_out(pin_out);
    ~SenderArduino();
};



#endif