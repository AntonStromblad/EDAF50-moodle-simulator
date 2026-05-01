#include <iostream>
#include <cassert>

// Inkludera studentens kod
#include "student.cpp"

void run_tests() {
    // 1. Testa konstruktorn och getters
    Vector2D v1(3, 4);
    assert(v1.get_x() == 3 && "v1.get_x() borde returnera 3");
    assert(v1.get_y() == 4 && "v1.get_y() borde returnera 4");

    // 2. Testa operator+
    Vector2D v2(1, 5);
    Vector2D v3 = v1 + v2;
    
    assert(v3.get_x() == 4 && "Additionen av x-koordinaterna blev fel (3 + 1 ska bli 4)");
    assert(v3.get_y() == 9 && "Additionen av y-koordinaterna blev fel (4 + 5 ska bli 9)");

    // 3. Testa const-korrekthet (fungerar inte att kompilera om getters inte är const)
    const Vector2D v4(10, 10);
    assert(v4.get_x() == 10 && "Kan inte anropa get_x() på ett const-objekt. Glömde du 'const' efter funktionsnamnet?");

    std::cout << "✅ Uppvärmning 1 avklarad! Du har stenkoll på grundläggande klasser och operatorer." << std::endl;
}

int main() {
    run_tests();
    return 0;
}