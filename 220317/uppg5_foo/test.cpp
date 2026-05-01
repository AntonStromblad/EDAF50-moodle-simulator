#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include <cassert>

#include "student.cpp"

void run_tests() {
    // Del 1: Konverteringar och vector-initialisering
    std::vector<Foo> v(5); // Kräver default-konstruktor
    std::iota(v.begin(), v.end(), 1); // Kräver Foo(int) och operator int (eller operator++)

    assert((int)v[0] == 1);
    assert((int)v[4] == 5);

    // Del 2: std::transform med operator()
    // Enligt facit ska operator() i detta exempel dubbla värdet
    // (Detta baseras på EXAMPLE2 i facit-filen)
    std::vector<int> res;
    std::transform(v.begin(), v.end(), std::back_inserter(res), [](Foo& f) {
        // I tentan anropas f() vilket kräver operator()
        return (int)f(); 
    });

    // Om din operator() dubblar värdet (som i facit):
    assert(res[0] == 2);
    assert(res[4] == 10);

    std::cout << "✅ Uppgift 5: Foo-klassen hanterar konverteringar och transform korrekt!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}