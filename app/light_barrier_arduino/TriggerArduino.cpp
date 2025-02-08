#include <Arduino.h>
#include "trigger_arduino.hpp"


TriggerArduino::start()
{
    // Set the timer
    uint16_t u16_trigger_ms = this->getTrigger();
    esp32_timer = timerBegin(0, 80, true);
    timerAttachInterrupt(esp32_timer, &this->executeCallback, true);
    timerAlarmWrite(esp32_timer, u16_trigger_ms, true);
    timerAlarmEnable(esp32_timer);

    this->b_running = true;

    return true;
}

TriggerArduino::stop()
{
    timerEnd(esp32_timer);
    this->b_running = false;
    return true;
}





