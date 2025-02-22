#include "Trigger.hpp"

void Trigger::executeCallbacks(void) const {
    this->callbackManager.executeCallbacks();
}   