#include "pulse.hpp"

Pulse::Pulse(uint16_t u16_pattern, 
             uint16_t u16_t_puls_ms, 
             Trigger * p_trigger,
             uint8_t u8_pattern_length=8): 
            g_u16_pattern(u16_pattern), 
            g_u16_t_puls_ms(u16_t_puls_ms), 
            g_p_trigger(p_trigger),
            g_u8_pattern_length(u8_pattern_length),
            g_u8_pattern_idx(0){
                this->g_p_trigger->setCallback([this]() { this->doSend();});
             }

uint16_t Pulse::getPattern() const{ 
    return this->g_u16_pattern; 
}

int Pulse::getTPuls() const{ 
    return this->g_u16_t_puls_ms; 
}

void Pulse::doSend(){
    if (this->g_u8_pattern_idx >= this->g_u8_pattern_length){
        this->g_u8_pattern_idx=0;
    }



}