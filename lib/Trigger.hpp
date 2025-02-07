#ifndef TRIGGER_DEF
#define TRIGGER_DEF
#include <cstdint>
#include <functional>


/*!
    @brief: Class to trigger a function
*/
class Trigger {
    private:
    protected:
        uint16_t u16_trigger_ms;
        std::function<void()> trg_cb; // Funktionspointer
        bool b_running = false;

        //@brief: Execute the callback function
        virtual void executeCallback() const = 0;
    
    public:
        //@brief: Constructor
        Trigger(uint16_t u16_tigger_ms) :
                u16_trigger_ms(u16_tigger_ms) {}
        virtual ~Trigger() = default;

        //@brief: Set the send callback function
        void setCallback(std::function<void()> trg_cb);

        virtual bool start() = 0;
        virtual bool stop() = 0;
        bool isRunning() const;
         
        // Getter Methoden
        uint16_t getTrigger() const; 
};
#endif