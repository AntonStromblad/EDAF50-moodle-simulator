#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cassert>

// Inkludera din lösning
#include "student.cpp"

void run_tests() {
    // Test 1 från tentan (heltal)
    std::vector<int> v(30);
    std::iota(begin(v), end(v), 1);
    
    std::stringstream ss1;
    auto out1 = std::ostream_iterator<int>(ss1, ", ");
    copy_nth(begin(v), end(v), out1, 4);

    std::string expected1 = "1, 5, 9, 13, 17, 21, 25, 29, ";
    if (ss1.str() != expected1) {
        std::cout << "❌ Fel på Test 1 (heltal)!\nFörväntade: " << expected1 << "\nFick: " << ss1.str() << "\n";
        assert(false);
    }

    // Test 2 från tentan (strängar)
    std::stringstream ss{"one two three four five six seven"};
    std::istream_iterator<std::string> it(ss);
    std::istream_iterator<std::string> ie{};
    
    std::stringstream ss2;
    auto out2 = std::ostream_iterator<std::string>(ss2, ", ");
    copy_nth(it, ie, out2, 3);

    std::string expected2 = "one, four, seven, ";
    if (ss2.str() != expected2) {
        std::cout << "❌ Fel på Test 2 (strängar)!\nFörväntade: " << expected2 << "\nFick: " << ss2.str() << "\n";
        assert(false);
    }

    std::cout << "✅ Snyggt! copy_nth fungerar perfekt med dina testfall!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}