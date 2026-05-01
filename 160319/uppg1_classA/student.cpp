#include <iostream>
#include <cstddef>

// Uppgift 1: Rätta till kompileringsfelet och minnesläckorna.
// Klassen allokerar minne dynamiskt men saknar The Rule of Three.

class A {
public:
    A(std::size_t sz = 10) : size(sz), storage(new int[size]) {}
    
    // a) Fixa utskriften (Kompileringsfelet i funktionen print på tentan).
    // Tips: Du behöver deklarera en friend-operator<< här inne!
    
    // b) Fixa minneshanteringen (Rule of three):
    // 1. Destruktor
    // 2. Kopieringskonstruktor
    // 3. Tilldelningsoperator (operator=)

    int operator[](std::size_t pos) const { return storage[pos]; }
    int& operator[](std::size_t pos) { return storage[pos]; }
    std::size_t get_size() const { return size; }

private:
    int* storage;
    std::size_t size;
};

// a) Implementera din operator<< här (utanför klassen)