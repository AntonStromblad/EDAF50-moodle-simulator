#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

#include "student.cpp"

void run_tests() {
    // 1. Testa konstruktor och array-access
    A a1(3);
    for (std::size_t i = 0; i < 3; ++i) { a1[i] = i + 1; }

    // 2. Testa operator<< (Uppgift 1a)
    std::stringstream ss1;
    ss1 << a1;
    // Förväntat format från tentans utskrift är t.ex. "1, 2, 3"
    assert(ss1.str() == "1, 2, 3" && "operator<< fungerar inte korrekt!");

    // 3. Testa Rule of Three (Uppgift 1b)
    A a2;
    a2 = a1; // Testar copy-assignment
    A a3(a1); // Testar copy-constructor

    // Om de delar minne (shallow copy) kommer a2 och a3 också ändras!
    a1[0] = 99; 

    assert(a2[0] == 1 && "Tilldelningsoperatorn verkar göra en shallow copy (den delar minne med a1)!");
    assert(a3[0] == 1 && "Kopieringskonstruktorn verkar göra en shallow copy (den delar minne med a1)!");

    std::cout << "✅ Uppgift 1: Klassen A fungerar, skriver ut rätt och hanterar minne korrekt!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}