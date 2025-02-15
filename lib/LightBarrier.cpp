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
    
    if (this->g_state != LightBarrierState::ERROR)
    {
        this->g_state = LightBarrierState::INIT;
    }
}

void LightBarrier::start(){
    g_p_trigger_sender->start();

}

void LightBarrier::stop(){
    g_p_trigger_sender->stop();
}

void LightBarrier::checkReceiver(){
    BitStatus rcv_bit = g_p_receiver->getBit();
    
}

int LightBarrier::addCallback(std::function<void(bool)> callback){
    int id = nextCallbackId++;
    callbacks[id] = callback;
    return id;
}

void LightBarrier::removeCallback(int callbackId){
    callbacks.erase(callbackId);
}

void LightBarrier::executeCallback(bool state) const{
    for (const auto& pair : callbacks) {
        pair.second(state);
    }    
}

LightBarrierState LightBarrier::getState() const {
     return g_state; 
}