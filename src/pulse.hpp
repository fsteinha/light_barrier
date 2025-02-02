#ifndef PULSE_DEF
#define PULSE_DEF
#include <cstdint>
#include "trigger.hpp"

class Pulse {
    private:
        uint16_t g_u16_pattern;
        uint16_t g_u16_t_puls_ms;
        Trigger *g_p_trigger;
        uint8_t  g_u8_pattern_length;
        u_int8_t g_u8_pattern_idx;
        static constexpr uint16_t PATTERN_MASK_INIT = 0x8000;


    public:
        // Konstruktor
        Pulse(uint16_t u16_pattern, 
              uint16_t u16_t_puls_ms, 
              Trigger * p_trigger,
              uint8_t u8_pattern_length);

        void doSend();

        // Getter Methoden
        uint16_t getPattern() const; 
        int getTPuls() const;
};
#endif
