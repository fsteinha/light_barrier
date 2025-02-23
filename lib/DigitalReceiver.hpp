#ifndef DIGITAL_RECEIVER_DEF
#define DIGITAL_RECEIVER_DEF

#include <cstdint>
#include "Trigger.hpp"
#include "BitStatus.hpp"
#include "CallbackManager.hpp"

/*!
    @brief: Class to receive a pattern
*/
class DigitalReceiver {
    protected:
        Trigger *g_p_trigger = nullptr;
        BitStatus rcv_bit = BitStatus::UNDEF;
    
        CallbackManager callbackManager;
        //@brief: Execute the callback function
        void executeCallbacks(void) const;

    public:
        DigitalReceiver() = default;
        //@brief: Constructor
        DigitalReceiver(Trigger * p_trigger) : g_p_trigger(p_trigger) {}

        BitStatus getBit() const {
            return this->rcv_bit;
        }

        virtual void receive(){};

        //@brief: Add a send callback function
        int addCallback(std::function<void()> callback) {
            return callbackManager.addCallback(callback);
        };
        
        //@brief: Remove a send callback function
        void removeCallback(int callbackId) {
            callbackManager.removeCallback(callbackId);
        };        
};

#endif