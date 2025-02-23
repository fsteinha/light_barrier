#include "DigitalReceiver.hpp"

void DigitalReceiver::executeCallbacks(void) const {
    this->callbackManager.executeCallbacks();
}   