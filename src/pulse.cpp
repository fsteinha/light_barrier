#include "pulse.hpp"
#include "sender.hpp"

/*!
    @brief: Constructor of Pulse
    @param u16_pattern: pattern to send
    @param p_trigger: trigger object
    @param p_sender: sender object
    @param u8_pattern_length: length of the pattern
    @return: void
*/
Pulse::Pulse(uint16_t u16_pattern, 
             Trigger * p_trigger,
             DigitalSender *p_sender,
             uint8_t u8_pattern_length=8): 
            g_u16_pattern(u16_pattern), 
            g_p_trigger(p_trigger),
            g_u8_pattern_length(u8_pattern_length),
            g_u8_pattern_idx(0),
            g_p_sender(p_sender){
                this->g_p_trigger->setCallback([this]() { this->doSend();});
             }

/*!
    @brief: Getter method for pattern
    @return: uint16_t
*/
uint16_t Pulse::getPattern() const{ 
    return this->g_u16_pattern; 
}


/*!
    @brief: Method to send the pattern
    @return: void
*/
void Pulse::doSend(){
    uint8_t u8_send;
    uint16_t u16_mask;

    if (this->g_u8_pattern_idx >= this->g_u8_pattern_length){
        this->g_u8_pattern_idx=0;
    }
    u16_mask = this->PATTERN_MASK_INIT >> this->g_u8_pattern_idx;
    this->g_u8_pattern_idx++;
    u8_send = ((u16_mask & this->g_u16_pattern) > 0);
    this->g_p_sender->send(u8_send);
}