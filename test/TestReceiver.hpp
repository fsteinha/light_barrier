#include "DigitalReceiver.hpp"

class TestReceiver : public DigitalReceiver {
    int rcv_bit_value = 0;
public:
    TestReceiver() : DigitalReceiver() {}
    void executeCallbacks() {
        DigitalReceiver::executeCallbacks();
    }   

    void receive() {
        if (this->rcv_bit_value == 0) {
            this->rcv_bit = BitStatus::LOW;
        } else {
            this->rcv_bit = BitStatus::HIGH;
        }
        this->executeCallbacks();
    }

    void setBit(int bit) {
        this->rcv_bit_value = bit;
    }
};