#include <iostream>
#include <cassert>
#include "Pulse.hpp"
#include "TriggerMock.hpp"
#include "TestSender.hpp"

static void testPulse_(u_int16_t pattern, u_int8_t pattern_length, int repeat) {
    TriggerMock *p_trigger = new TriggerMock(1);
    TestSender *p_sender = new TestSender();

    Pulse *pulse = new Pulse(pattern, p_trigger, p_sender, pattern_length);
    assert(pulse->getPattern() == pattern);

    for (int i = 0; i < repeat; i++) {
        p_trigger->executeCallbacks();
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
    TestSender sender = TestSender();

    testPulse_(0xAAAA, 16, 32);
    testPulse_(0x5555, 16, 32);
    testPulse_(0x8000, 2, 16);

    
    std::cout << "Alle Tests bestanden!" << std::endl;
}

int main() {
    testPulse();
    return 0;
}
