#include "Trigger.hpp"

/*!
    @brief: Getter method for trigger
    @return: uint16_t
*/
uint16_t Trigger::getTrigger() const {
    return this->u16_trigger_ms;
}

/*! 
    @brief: Method to determine is the trigger running
*/
bool Trigger::isRunning() const {
    return this->b_running;
}

int Trigger::addCallback(std::function<void()> callback) {
    int id = nextCallbackId++;
    callbacks[id] = callback;
    return id;
}

void Trigger::removeCallback(int callbackId) {
    callbacks.erase(callbackId);
}

void Trigger::executeCallbacks() const {
    for (const auto& pair : callbacks) {
        pair.second();
    }
}