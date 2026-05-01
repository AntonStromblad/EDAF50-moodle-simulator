#include <iostream>
#include <cassert>

#include "student.cpp"

void run_tests() {
    // Test 3e: assign
    Vektor<int> v(3);
    v.assign({10, 20, 30});
    assert(*v.begin() == 10 && *(v.begin() + 2) == 30);

    // Test 3f: add (samma längd)
    Vektor<int> c1(3); c1.assign({1, 2, 3});
    Vektor<int> c2(3); c2.assign({10, 20, 30});
    Vektor<int> c3(6); // Tillräckligt stor
    
    add(c1, c2, c3);
    assert(*c3.begin() == 11 && *(c3.begin() + 1) == 22 && *(c3.begin() + 2) == 33);

    // Test 3f: add (olika längd)
    Vektor<int> c4(5); c4.assign({100, 200, 300, 400, 500});
    Vektor<int> c5(8);
    
    add(c1, c4, c5); 
    // c1 = {1, 2, 3}
    // c4 = {100, 200, 300, 400, 500}
    // Resultat ska bli: {101, 202, 303, 400, 500}
    
    auto it = c5.begin();
    assert(*it == 101);
    assert(*(it + 2) == 303);
    assert(*(it + 3) == 400); // Överskott från c4
    assert(*(it + 4) == 500); // Överskott från c4

    std::cout << "✅ Uppgift 3: Vektor assign() och add() fungerar galant!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}