#ifndef TRIGGER_DEF
#define TRIGGER_DEF
#include <cstdint>
#include <functional>

class Trigger {
    private:
        uint16_t u16_trigger_ms;
        std::function<void()> trg_cb; // Funktionspointer

    public:
        // Konstruktor
        Trigger(uint16_t u16_tigger_ms) :
                u16_trigger_ms(u16_tigger_ms) {}

        void setCallback(std::function<void()> trg_cb);

        // Methode zum Aufrufen des Funktionspointers
        void executeCallback() const;
        
        // Getter Methoden
        uint16_t getTrigger() const; 
};
#endif