#ifndef BIT_STATUS_HPP
#define BIT_STATUS_HPP

#include <string>

class BitStatus {
public:
    enum Value {
        UNDEF,
        HIGH,
        LOW
    };

    BitStatus(Value value = UNDEF) : value_(value) {}

    operator Value() const { return value_; }

    std::string toString() const {
        switch (value_) {
            case LOW:
                return "LOW";
            case HIGH:
                return "HIGH";
            default:
                return "UNDEF";
        }
    }

private:
    Value value_;
};


#endif