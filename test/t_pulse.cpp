#include <iostream>
#include <cassert>
#include "pulse.hpp"

// Unit Test Funktion
void testPulse() {
    // Testfälle
    Pulse p1(0xAAAA, 100);
    assert(p1.getPattern() == 0xAAAA);
    assert(p1.getTPuls() == 100);

    Pulse p2(0x5555, 200);
    assert(p2.getPattern() == 0x5555);
    assert(p2.getTPuls() == 200);

    std::cout << "Alle Tests bestanden!" << std::endl;
}

int main() {
    testPulse();
    return 0;
}
