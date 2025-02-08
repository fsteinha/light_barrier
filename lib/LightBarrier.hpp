#ifndef LIGHT_BARRIER_ARDUINO
#define LIGHT_BARRIER_ARDUINO

#include <cstdint>
#include "Trigger.hpp"
#include "Pulse.hpp"
#include "DigitalSender.hpp"

class LightBarrier
{
private:
    Pulse g_pulse;
    Trigger *g_p_trigger;
    DigitalSender *g_p_sender;

public:
    LightBarrier(u_int16_t u16_pulse_time_ms, 
                u_int8_t u8_pattern_Lenght,
                          Trigger *p_trigger,
                          DigitalSender *p_sender);
    ~LightBarrier();
};

#endif