#include <cstdint>

class Pulse {
    private:
        uint16_t pattern;
        int TPuls;

    public:
        // Konstruktor
        Pulse(uint16_t p, int t) : pattern(p), TPuls(t) {}

        // Getter Methoden
        uint16_t getPattern() const; 
        int getTPuls() const;
};

