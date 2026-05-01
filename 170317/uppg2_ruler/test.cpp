#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
#include <algorithm>

#include "student.cpp"

void run_tests() {
    // Test 1: Inläsning (operator>>)
    std::istringstream is("Carl 16 Sweden 1973 0\nMargrethe 2 Denmark 1972 0\n");
    Ruler r1, r2;
    is >> r1 >> r2;

    // Test 2: Utskrift (operator<<)
    std::ostringstream os;
    os << r1;
    assert(os.str() == "Carl 16 of Sweden, 1973-0" && "Utskriften matchar inte det förväntade formatet!");

    // Test 3: Sortering (operator<)
    // Sorteras först på nation, sedan startår. (Denmark kommer före Sweden).
    std::vector<Ruler> rulers = {r1, r2};
    std::sort(rulers.begin(), rulers.end());

    std::ostringstream os2;
    os2 << rulers[0];
    assert(os2.str() == "Margrethe 2 of Denmark, 1972-0" && "Sorteringen (operator<) fungerar inte korrekt!");

    std::cout << "✅ Uppgift 2: Klassen Ruler läser in, skriver ut och sorterar perfekt!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}