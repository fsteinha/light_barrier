#include "Trigger.hpp"

class TriggerMock : public Trigger {
    public:
        TriggerMock(uint16_t u16_trigger_ms) : Trigger(u16_trigger_ms) {}
        ~TriggerMock() = default;
        bool start() override {
            this->b_running = true;
            return true;
        }

        bool stop() override {
            this->b_running = false;
            return true;
        }

        void executeCallbacks() {
            Trigger::executeCallbacks();
        }   
};