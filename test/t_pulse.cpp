#include <iostream>
#include <cassert>
#include "Pulse.hpp"
#include "Trigger.hpp"
#include "DigitalSender.hpp"

class TriggerMock : public Trigger {
    public:
        TriggerMock(uint16_t u16_trigger_ms) : Trigger(u16_trigger_ms) {}
        void executeCallback() const override {
            if (this->trg_cb) {
                this->trg_cb();
            }           
        }

        bool start() override {
            this->b_running = true;
            return true;
        }

        bool stop() override {
            this->b_running = false;
            return true;
        }   
};

class Sender: public DigitalSender
{
private:
    /* data */
public:
    Sender(): DigitalSender(){};
    ~Sender(){};
    bool send(bool pattern) override {
        std::cout << pattern;
        return true;
    }
};


static void testPulse_(u_int16_t pattern, u_int8_t pattern_length, int repeat) {
    TriggerMock *p_trigger = new TriggerMock(1);
    Sender *p_sender = new Sender();

    Pulse *pulse = new Pulse(pattern, p_trigger, p_sender, pattern_length);
    assert(pulse->getPattern() == pattern);

    for (int i = 0; i < repeat; i++) {
        p_trigger->executeCallback();
    }
    std::cout << std::endl;
    
    delete p_trigger;
    delete p_sender;
    delete pulse;
}

// Unit Test Funktion
void testPulse() {
    // Testfälle
    TriggerMock trigger = TriggerMock(1);
    Sender sender = Sender();

    testPulse_(0xAAAA, 16, 32);
    testPulse_(0x5555, 16, 32);
    testPulse_(0x8000, 2, 16);

    
    std::cout << "Alle Tests bestanden!" << std::endl;
}

int main() {
    testPulse();
    return 0;
}
