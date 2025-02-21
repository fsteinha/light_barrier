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

void Trigger::executeCallbacks(void) const {
    this->callbackManager.executeCallbacks();
}   