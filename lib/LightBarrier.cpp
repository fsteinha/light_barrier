#include "LightBarrier.hpp"

LightBarrier::LightBarrier(u_int16_t u16_pulse_time_ms,
                            u_int8_t u8_pattern_length,
                            Trigger *p_trigger,
                            DigitalSender *p_sender): 
                            g_p_trigger(p_trigger),
                            g_p_sender(p_sender),
                            g_pulse(Pulse(u16_pulse_time_ms, 
                                          g_p_trigger, 
                                          g_p_sender, 
                                          u8_pattern_length)) {}

void LightBarrier::start()
{
    g_p_trigger->start();
}

void LightBarrier::stop()
{
    g_p_trigger->stop();
}

int LightBarrier::addCallback(std::function<void(bool)> callback)
{
    int id = nextCallbackId++;
    callbacks[id] = callback;
    return id;
}

void LightBarrier::removeCallback(int callbackId)
{
    callbacks.erase(callbackId);
}

void LightBarrier::executeCallback(bool state) const
{
    for (const auto& pair : callbacks) {
        pair.second(state);
    }    
}

