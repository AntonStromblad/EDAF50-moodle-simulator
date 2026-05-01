#include <iostream>
#include <cassert>

#include "student.cpp"

void run_tests() {
    EquivalenceClasses ec;
    
    // Skapa klassen {10, 20}
    ec.join(10, 20);
    // Lägg till 30 i samma klass -> {10, 20, 30}
    ec.join(20, 30);
    
    // Skapa en helt ny klass {40, 50}
    ec.join(40, 50);

    // Kontrollera att least() fungerar
    assert(ec.least(30) == 10 && "least(30) borde vara 10 eftersom {10, 20, 30} är samma klass");
    assert(ec.least(10) == 10);
    assert(ec.least(50) == 40 && "least(50) borde vara 40");
    
    // Ett element som inte lagts in ännu ska returnera sig självt
    assert(ec.least(99) == 99 && "least(99) borde returnera 99");

    // Slå ihop de två stora klasserna med varandra
    ec.join(30, 40);
    
    // Nu är alla {10, 20, 30, 40, 50} i samma klass!
    assert(ec.least(50) == 10 && "Nu är klasserna hopslagna, minsta borde vara 10");

    std::cout << "✅ Uppgift 3: Din EquivalenceClasses fungerar och kan merga bitsets!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}