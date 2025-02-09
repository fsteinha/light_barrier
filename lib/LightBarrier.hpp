#ifndef LIGHT_BARRIER_ARDUINO
#define LIGHT_BARRIER_ARDUINO

#include <cstdint>
#include "Trigger.hpp"
#include "Pulse.hpp"
#include "DigitalSender.hpp"

class LightBarrier
{
private:
    Trigger *g_p_trigger;
    DigitalSender *g_p_sender;
    Pulse g_pulse;
    std::map<int, std::function<void(bool)>> callbacks; // Callback functions with unique IDs
    int nextCallbackId = 0;
    
    void executeCallback(bool state) const;

public:
    LightBarrier(u_int16_t u16_pulse_time_ms, 
                    u_int8_t u8_pattern_length,
                    Trigger *p_trigger,
                    DigitalSender *p_sender);
    void start();
    void stop();    
    int addCallback(std::function<void(bool)> callback);
    void removeCallback(int callbackId);
 
    ~LightBarrier(){};
};

#endif