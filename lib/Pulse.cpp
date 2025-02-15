#include "Pulse.hpp"
#include "DigitalSender.hpp"

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
             uint8_t u8_pattern_length): 
            g_u16_pattern(u16_pattern), 
            g_p_trigger(p_trigger),
            g_p_sender(p_sender),
            g_u8_pattern_length(u8_pattern_length),
            g_u8_pattern_idx(0)
            {
                this->g_p_trigger->addCallback([this]() { this->doSend();});
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
    bool b_send;
    uint16_t u16_mask;

    if (this->g_u8_pattern_idx >= this->g_u8_pattern_length){
        this->g_u8_pattern_idx=0;
    }
    u16_mask = this->PATTERN_MASK_INIT >> this->g_u8_pattern_idx;
    this->g_u8_pattern_idx++;
    b_send = ((u16_mask & this->g_u16_pattern) > 0);
    this->g_p_sender->send(b_send);
    if (b_send == true){
        this->g_send_bit = BitStatus::HIGH;
    } else {
        this->g_send_bit = BitStatus::LOW;
    }
}

/*!
    @brief: Getter method for send bit
    @return: SendBit
*/
BitStatus Pulse::getSendBit() const{
    return this->g_send_bit;
}