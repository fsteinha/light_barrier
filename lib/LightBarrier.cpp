#include "LightBarrier.hpp"

LightBarrier::LightBarrier(u_int16_t u16_pulse_time_ms,
                            u_int8_t u8_pattern_lenght,
                            Trigger *p_trigger,
                            DigitalSender *p_sender): 
                            g_p_trigger(p_trigger),
                            g_p_sender(p_sender),
                            g_pulse(Pulse(u16_pulse_time_ms, 
                                          g_p_trigger, 
                                          g_p_sender, 
                                          u8_pattern_lenght)) {}