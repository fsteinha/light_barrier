#include "Trigger.hpp"

/*!
    @brief: Set the send callback function
    @param trg_cb: callback function
    @return: void
*/
void Trigger::setCallback(std::function<void()> trg_cb) {
    this->trg_cb = trg_cb;
}

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