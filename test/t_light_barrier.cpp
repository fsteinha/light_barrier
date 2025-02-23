#include <iostream>
#include <cassert>
#include "LightBarrier.hpp"
#include "TriggerMock.hpp"
#include "TestSender.hpp"
#include "TestReceiver.hpp"

static void testLightBarrier_(u_int16_t pattern, u_int8_t pattern_length, int repeat) {
    TriggerMock *p_trigger_sender = new TriggerMock(1);
    TestSender *p_sender = new TestSender();
    TestReceiver *p_receiver = new TestReceiver();

    LightBarrier *p_light_barrier = new LightBarrier(pattern, 
                                                    pattern_length, 
                                                    p_trigger_sender, 
                                                    p_sender,
                                                    nullptr, 
                                                    p_receiver);

    assert(p_light_barrier->getState() == LightBarrierState::INIT);
    
    for (int i = 0; i < repeat; i++) {
        p_trigger_sender->executeCallbacks();
        p_receiver->setBit(0);
        p_receiver->receive();
        p_receiver->executeCallbacks();
    }
    std::cout << std::endl;
    
    delete p_trigger_sender;
    delete p_sender;
    delete p_light_barrier;
}

// Unit Test Function
void testLightBarrier() {
    // Testfälle
    testLightBarrier_(0xAAAA, 16, 32);
    testLightBarrier_(0x5555, 16, 32);
    testLightBarrier_(0x8000, 2, 16);

    
    std::cout << "Alle Tests bestanden!" << std::endl;
}

int main() {
    testLightBarrier();
    return 0;
}
