#include <iostream>
#include <sstream>
#include <cassert>
#include "student.cpp"

void run_tests() {
    std::stringstream buffer;
    std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());

    // Koden från tentans exempel
    counter c;
    std::cout << "1: c=" << c << '\n';
    c = 17;
    std::cout << "2: c=" << c << '\n';
    int x = c;
    std::cout << "3: x=" << x << '\n';
    c();
    std::cout << "4: c=" << c << '\n';
    c(24);
    std::cout << "5: c=" << c << '\n';
    c = c + 100;
    std::cout << "6: c=" << c << '\n';
    if(c > 100) {
        std::cout << "correct: " << c << " > 100\n";
    }

    std::cout.rdbuf(old_cout);
    std::string output = buffer.str();

    std::string expected = 
        "1: c=0\n"
        "2: c=17\n"
        "3: x=17\n"
        "4: c=18\n"
        "5: c=42\n"
        "6: c=142\n"
        "correct: 142 > 100\n";

    if (output != expected) {
        std::cout << "❌ Utskriften matchade inte det förväntade resultatet!\n\nFick:\n" << output << "\nFörväntade:\n" << expected;
        assert(false);
    }
    std::cout << "✅ Snyggt! Din counter-klass fungerar perfekt och ger exakt rätt utskrift!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}