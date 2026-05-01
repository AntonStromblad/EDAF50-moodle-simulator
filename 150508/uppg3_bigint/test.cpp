#include <iostream>
#include <sstream>
#include <cassert>

#include "student.cpp"

void run_tests() {
    // 1. Testa konstruktor och addition med carry (minnessiffra)
    BI a("99");
    BI b("2");
    a += b; // Ska bli 101

    // 2. Testa utskrift
    std::ostringstream os;
    os << a;
    assert(os.str() == "101" && "Additionen eller utskriften fungerar inte korrekt!");

    // 3. Testa exception vid felaktig inmatning
    bool threw = false;
    try {
        BI bad("123A5");
    } catch (const illegal_number&) {
        threw = true;
    }
    assert(threw && "Konstruktorn kastade inte illegal_number vid bokstäver!");

    std::cout << "✅ Uppgift 3: Din Big Integer-klass kan räkna ut gigantiska tal!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}