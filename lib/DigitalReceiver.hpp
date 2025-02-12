#ifndef DIGITAL_RECEIVER_DEF
#define DIGITAL_RECEIVER_DEF

#include <cstdint>
#include "Trigger.hpp"
#include "SendBit.hpp"

/*!
    @brief: Class to receive a pattern
*/
class DigitalReceiver {
    private:
        Trigger *g_p_trigger = nullptr;
        SendBit rcv_bit = SendBit::UNDEF;
        std::map<int, std::function<void()>> callbacks; // Callback functions with unique IDs
    
        int nextCallbackId = 0;

    protected:
        //@brief: Execute the callback function
        void executeCallbacks() const;

    public:
        DigitalReceiver() = default;
        //@brief: Constructor
        DigitalReceiver(Trigger * p_trigger) : g_p_trigger(p_trigger) {}


        //@brief: Add a send callback function
        int addCallback(std::function<void()> callback);
        
        //@brief: Remove a send callback function
        void removeCallback(int callbackId);

};

#endif