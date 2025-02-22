#ifndef TRIGGER_DEF
#define TRIGGER_DEF
#include <cstdint>
#include <functional>
#include <map>
#include <algorithm>
#include <vector>

#include "CallbackManager.hpp"


/*!
    @brief: Class to trigger a function
*/
class Trigger {
    private:
    protected:
        uint16_t u16_trigger_ms = 0;
        CallbackManager callbackManager;
        bool b_running = false;

        void executeCallbacks(void) const;

    public:
        Trigger() = default;
        //@brief: Constructor
        Trigger(uint16_t u16_trigger_ms) :
                u16_trigger_ms(u16_trigger_ms) {}
        virtual ~Trigger() = default;

        //@brief: Add a send callback function
        int addCallback(std::function<void()> callback) {
            return callbackManager.addCallback(callback);
        };
        
        //@brief: Remove a send callback function
        void removeCallback(int callbackId) {
            callbackManager.removeCallback(callbackId);
        };

        //@brief: Start the trigger
        virtual bool start() = 0;

        //@brief: Stop the trigger
        virtual bool stop() = 0;

        //@brief: Check if the trigger is running
        bool isRunning() const {
            return this->b_running;
        }
         
        // Getter methods
        uint16_t getTrigger() const {
            return this->u16_trigger_ms;
        }
};
#endif