#ifndef PULSE_DEF
#define PULSE_DEF
#include <cstdint>
#include "Trigger.hpp"
#include "DigitalSender.hpp"

/*!
    @brief: Class to send a pattern
*/
class Pulse {
    private:
        uint16_t g_u16_pattern;
        //@brief: Pointer to Trigger object
        Trigger *g_p_trigger = nullptr; 
        //@brief: Pointer to DigitalSender object
        DigitalSender *g_p_sender = nullptr;
        uint8_t  g_u8_pattern_length;
        u_int8_t g_u8_pattern_idx;
        static constexpr uint16_t PATTERN_MASK_INIT = 0x8000;
        

    public:
        Pulse() = default;
        //@brief: Constructor
        Pulse(uint16_t u16_pattern, 
              Trigger * p_trigger,
              DigitalSender *p_sender,
              uint8_t u8_pattern_length);

        //@brief: Method to send the pattern
        void doSend();

        //@brief: Getter method for pattern
        uint16_t getPattern() const; 

};
#endif
