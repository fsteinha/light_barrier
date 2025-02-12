#include <iostream>
#include <cassert>
#include "LightBarrier.hpp"
#include "TriggerMock.hpp"
#include "TestSender.hpp"
#include "DigitalReceiver.hpp"

static void testLightBarrier_(u_int16_t pattern, u_int8_t pattern_length, int repeat) {
    TriggerMock *p_trigger_sender = new TriggerMock(1);
    TestSender *p_sender = new TestSender();
    DigitalReceiver *p_receiver = new DigitalReceiver();

    LightBarrier *p_light_barrier = new LightBarrier(pattern, 
                                                    pattern_length, 
                                                    p_trigger_sender, 
                                                    p_sender,
                                                    nullptr, 
                                                    p_receiver);
    
    for (int i = 0; i < repeat; i++) {
        p_trigger_sender->executeCallbacks();
    }
    std::cout << std::endl;
    
    delete p_trigger_sender;
    delete p_sender;
    delete p_light_barrier;
}

// Unit Test Funktion
void testLightBarrier() {
    // Testfälle
    TriggerMock trigger = TriggerMock(1);
    TestSender sender = TestSender();

    testLightBarrier_(0xAAAA, 16, 32);
    testLightBarrier_(0x5555, 16, 32);
    testLightBarrier_(0x8000, 2, 16);

    
    std::cout << "Alle Tests bestanden!" << std::endl;
}

int main() {
    testLightBarrier();
    return 0;
}
