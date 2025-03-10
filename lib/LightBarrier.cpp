#include <iostream>
#include "LightBarrier.hpp"

LightBarrier::LightBarrier(u_int16_t u16_pulse_time_ms,
                            u_int8_t u8_pattern_length,
                            Trigger *p_trigger,
                            DigitalSender *p_sender,
                            Trigger *p_trigger_receiver,
                            DigitalReceiver *p_receiver) : 
                            g_p_trigger_sender(p_trigger),
                            g_p_sender(p_sender),
                            g_p_trigger_receiver(p_trigger_receiver),
                            g_p_receiver(p_receiver),
                            g_pulse(Pulse(u16_pulse_time_ms, 
                                          g_p_trigger_sender, 
                                          g_p_sender, 
                                          u8_pattern_length)) {
    
    if (g_p_trigger_sender == nullptr || g_p_sender == nullptr) 
    {
        this->g_state = LightBarrierState::ERROR;
    }

    if (g_p_trigger_receiver == nullptr)
    {
        this->g_trigger_receiver.emplace(LightBarrierRcvTrigger());
        this->g_p_trigger_receiver = &this->g_trigger_receiver.value();
    }

    if (g_p_receiver == nullptr) 
    {
        this->g_receiver.emplace(DigitalReceiver(this->g_p_trigger_receiver));
        this->g_p_receiver = &this->g_receiver.value();
    }
    
    g_p_receiver->addCallback([this](void) {this->checkReceiver();});

    if (this->g_state != LightBarrierState::ERROR)
    {
        this->g_state = LightBarrierState::INIT;
    }
}

void LightBarrier::start(){
    g_p_trigger_sender->start();
    this->g_state = LightBarrierState::RUNNING;

}

void LightBarrier::stop(){
    g_p_trigger_sender->stop();
    this->g_state = LightBarrierState::STOPPED;
}

void LightBarrier::checkReceiver(){
    BitStatus rcv_bit = g_p_receiver->getBit();
    BitStatus last_send = g_pulse.getSendBit();

    if ((rcv_bit == BitStatus::UNDEF) || (last_send == BitStatus::UNDEF))
    {
        this->g_result = LightBarrierResult::NONE;
    }
    else if (rcv_bit == last_send)
    {
        this->g_result = LightBarrierResult::FREE;
    }
    else if (rcv_bit != last_send)
    {
        this->g_result = LightBarrierResult::BLOCKED;
    }
    else if ((last_send == BitStatus::LOW) && (rcv_bit == BitStatus::HIGH))
    {
        this->g_result = LightBarrierResult::NOISE;
    }
    else
    {
        this->g_result = LightBarrierResult::NONE;
    }

    std::cout << "Result: " << this->g_result.toString() << "Received: " << rcv_bit.toString() << " Expected: " << last_send.toString() << std::endl;
}

void LightBarrier::executeCallback() const{
    this->callbackManager.executeCallbacks();
}

LightBarrierState LightBarrier::getState() const {
     return g_state; 
}