#include <iostream>
#include <vector>
#include <cassert>

#include "student.cpp"

void run_tests() {
    int a[] = {1, 1, 2, 3, 5, 9};
    int b[6];

    // Testa din implementation
    auto it = adjacent_difference(a, a + 6, b);

    assert(b[0] == 1);
    assert(b[1] == 0);
    assert(b[2] == 1);
    assert(b[3] == 1);
    assert(b[4] == 2);
    assert(b[5] == 4);
    
    // Iteratorn ska peka på positionen efter det sista skrivna elementet
    assert(it == b + 6);

    std::cout << "✅ Uppgift 1: adjacent_difference beräknar skillnaderna helt korrekt!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}