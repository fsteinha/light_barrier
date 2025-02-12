#ifndef TRIGGER_DEF
#define TRIGGER_DEF
#include <cstdint>
#include <functional>
#include <map>
#include <algorithm>
#include <vector>


/*!
    @brief: Class to trigger a function
*/
class Trigger {
    private:
    protected:
        uint16_t u16_trigger_ms = 0;
        std::map<int, std::function<void()>> callbacks; // Callback functions with unique IDs
    
        bool b_running = false;
        int nextCallbackId = 0;

    protected:
        //@brief: Execute the callback function
        void executeCallbacks() const;
    
    public:
        Trigger() = default;
        //@brief: Constructor
        Trigger(uint16_t u16_trigger_ms) :
                u16_trigger_ms(u16_trigger_ms) {}
        virtual ~Trigger() = default;

        //@brief: Add a send callback function
        int addCallback(std::function<void()> callback);
        
        //@brief: Remove a send callback function
        void removeCallback(int callbackId);

        //@brief: Start the trigger
        virtual bool start() = 0;

        //@brief: Stop the trigger
        virtual bool stop() = 0;

        //@brief: Check if the trigger is running
        bool isRunning() const;
         
        // Getter methods
        uint16_t getTrigger() const; 
};
#endif