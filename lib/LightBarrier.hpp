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
#include "CallbackManager.hpp"

class LightBarrierState {
    public:
        enum Value {
            NO_INIT, INIT, RUNNING, STOPPED, ERROR
        };
    
        LightBarrierState(Value value = NO_INIT) : value_(value) {}
    
        operator Value() const { return value_; }
    
        std::string toString() const {
            switch (value_) {
                case NO_INIT:
                    return "NO_INIT";
                case INIT:
                    return "INIT";
                case RUNNING:
                    return "RUNNING";
                case STOPPED:
                    return "STOPPED";
                case ERROR:
                    return "ERROR";
                default:
                    return "UNKNOWN";
            }
        }
    
    private:
        Value value_;
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
    std::optional<DigitalReceiver> g_receiver; 

    Pulse g_pulse;
    CallbackManager callbackManager;
    int nextCallbackId = 0;
    LightBarrierState g_state = LightBarrierState::NO_INIT;

    void executeCallback() const;
    void checkReceiver();
public:
    LightBarrier(u_int16_t u16_pulse_time_ms, 
                    u_int8_t u8_pattern_length,
                    Trigger *p_trigger_sender,
                    DigitalSender *p_sender,
                    Trigger *p_trigger_receiver,
                    DigitalReceiver *p_receiver);
    void start();
    void stop();    
    //@brief: Add a send callback function
    int addCallback(std::function<void()> callback) {
        return callbackManager.addCallback(callback);
    };
    
    //@brief: Remove a send callback function
    void removeCallback(int callbackId) {
        callbackManager.removeCallback(callbackId);
    };
    LightBarrierState getState() const;
    ~LightBarrier(){};
};

#endif