#ifndef LIGHT_BARRIER_ARDUINO
#define LIGHT_BARRIER_ARDUINO

#include <cstdint>
#include <map>
#include <functional>
#include <optional>
#include "Trigger.hpp"
#include "Pulse.hpp"
#include "DigitalSender.hpp"
#include "DigitalReceiver.hpp"

enum class LightBarrierState
{
    NO_INIT, INIT, RUNNING, STOPPED, ERROR
};

class LightBarrierRcvTrigger: public Trigger
{
public:
    LightBarrierRcvTrigger(){}
    ~LightBarrierRcvTrigger() = default;
    bool start() override {
        this->b_running = true;
        return true;
    }

    bool stop() override {
        this->b_running = false;
        return true;
    }

    void executeCallbacks() {
        Trigger::executeCallbacks();
    }   
};

class LightBarrier
{
private:
    Trigger *g_p_trigger_sender = nullptr;
    DigitalSender *g_p_sender = nullptr;
    Trigger *g_p_trigger_receiver = nullptr;
    std::optional<LightBarrierRcvTrigger> g_trigger_receiver;
    DigitalReceiver *g_p_receiver = nullptr;
    std::optional<DigitalReceiver> g_reiver; 

    Pulse g_pulse;
    std::map<int, std::function<void(bool)>> callbacks; // Callback functions with unique IDs
    int nextCallbackId = 0;
    LightBarrierState g_state = LightBarrierState::NO_INIT;

    void executeCallback(bool state) const;

public:
    LightBarrier(u_int16_t u16_pulse_time_ms, 
                    u_int8_t u8_pattern_length,
                    Trigger *p_trigger_sender,
                    DigitalSender *p_sender,
                    Trigger *p_trigger_receiver,
                    DigitalReceiver *p_receiver);
    void start();
    void stop();    
    int addCallback(std::function<void(bool)> callback);
    void removeCallback(int callbackId);
 
    ~LightBarrier(){};
};

#endif