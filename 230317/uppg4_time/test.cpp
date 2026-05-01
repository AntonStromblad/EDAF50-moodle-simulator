#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

// Inkludera din lösning
#include "student.cpp"

void run_tests() {
    std::istringstream is(
        "13:15 1:45 lecture\n"
        "15:00 0:15 break\n"
        "15,15 1:45 lab\n"
        "27:00 0:15 break\n"
        "17:00 0:30 administration\n"
        "18:00 0:90 commute\n"
    );
    
    std::string line;
    std::stringstream buffer;
    std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());

    // Koden från tentans exempel
    while (std::getline(is, line)) {
        std::istringstream ss(line);
        Time s;
        Time d;
        std::string event;
        if (ss >> s && ss >> d && std::getline(ss, event)) {
            Time e = s + d;
            std::cout << s << " " << e << ":" << event << '\n';
        } else {
            std::cout << "[malformed line ignored]\n";
        }
    }

    std::cout.rdbuf(old_cout);
    std::string output = buffer.str();

    std::string expected = 
        "13:15 15:00: lecture\n"
        "15:00 15:15: break\n"
        "[malformed line ignored]\n"
        "[malformed line ignored]\n"
        "17:00 17:30: administration\n"
        "[malformed line ignored]\n";

    if (output != expected) {
        std::cout << "❌ Utskriften matchade inte det förväntade resultatet!\n\nFick:\n" << output << "\nFörväntade:\n" << expected;
        assert(false);
    }
    
    std::cout << "✅ Uppgift 4: Time-klassen fungerar klockrent!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}