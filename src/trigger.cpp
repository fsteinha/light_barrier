#include "trigger.hpp"


void Trigger::setCallback(std::function<void()> trg_cb) {
    this->trg_cb = trg_cb;
}

uint16_t Trigger::getTrigger() const {
    return this->u16_trigger_ms;
}

// Methode zum Aufrufen des Funktionspointers
void Trigger::executeCallback() const {
    if (this->trg_cb) {
        trg_cb();
    }
}