#ifndef TRIGGER_ARDUINO_HPP
#define TRIGGER_ARDUINO_HPP

#include <Arduino.h>
#include "trigger.hpp"

class TriggerArduino() : public Trigger
{
private:
    hw_timer_t *esp32_timer = NULL;
public:
    TriggerArduino(uint16_t u16_trigger_ms) : Trigger(u16_trigger_ms) {};
    ~TriggerArduino() {}
};

#endif