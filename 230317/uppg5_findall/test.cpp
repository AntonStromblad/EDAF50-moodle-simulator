#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>

// Inkludera din lösning
#include "student.cpp"

void run_tests() {
    std::vector<int> v = {1, 3, 2, 4, 3, 5, 4, 6, 5, 7, 3};
    
    // Tentans exempelkod
    auto it = find_all(begin(v), end(v), 3);
    while(it != end(v)) {
        *it = 42;
        ++it;
    }
    
    std::stringstream buffer;
    for(auto x : v) {
        buffer << x << " ";
    }
    
    std::string expected = "1 42 2 4 42 5 4 6 5 7 42 ";
    
    if (buffer.str() != expected) {
        std::cout << "❌ Fel på utskrift/modifiering!\nFörväntade: " << expected << "\nFick: " << buffer.str() << "\n";
        assert(false);
    }
    
    std::cout << "✅ Uppgift 5: find_all och result_iter fungerar utmärkt!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}