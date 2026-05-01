#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

// Inkludera din kod
#include "student.cpp"

void run_tests() {
    // 1. Testa att vi kan skriva till pekaren (uppgift a)
    int val = 10;
    Ptr<int> p_val(&val);
    *p_val = 20; 
    assert(val == 20 && "Uppgift A: Det gick inte att skriva till pekaren via *p = ...");

    // 2. Testa iteration över int-array (uppgift b)
    int x[] = {1, 2, 3};
    std::stringstream int_buffer;
    for (Ptr<int> p = x; p != x + 3; ++p) {
        int_buffer << *p << " ";
    }
    assert(int_buffer.str() == "1 2 3 " && "Uppgift B: int-iterationen fungerade inte!");

    // 3. Testa iteration över string-array (uppgift b)
    std::string y[] = {"Despite", "the", "constant", "negative", "press", "covfefe"};
    std::stringstream str_buffer;
    for (Ptr<std::string> p = y; p != y + 6; ++p) {
        str_buffer << *p << " ";
    }
    assert(str_buffer.str() == "Despite the constant negative press covfefe " && "Uppgift B: string-iterationen fungerade inte!");

    std::cout << "✅ Snyggt! Din Ptr-klass är nu en fullt fungerande template-iterator!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}