#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

// Inkludera din kod
#include "student.cpp"

void run_tests() {
    NameList list;
    
    // Stoppa in namn i osorterad ordning
    list.insert("Charlie");
    list.insert("Alice");
    list.insert("Bob");

    // Vi omdirigerar std::cout för att kunna fånga upp din utskrift
    std::stringstream buffer;
    std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());

    // Anropa din funktion
    list.printSorted();

    // Återställ std::cout så vi kan skriva ut testresultat som vanligt
    std::cout.rdbuf(old_cout);

    std::string output = buffer.str();
    
    // Den förväntade utskriften i alfabetisk ordning
    std::string expected = "Alice\nBob\nCharlie\n";
    
    if (output != expected) {
        std::cout << "❌ Fel i utskrift eller sortering!" << std::endl;
        std::cout << "Förväntade utskrift:" << std::endl << expected << std::endl;
        std::cout << "Fick utskrift:" << std::endl << output << std::endl;
        assert(false && "Test misslyckades!");
    }

    std::cout << "✅ Utskrift och sortering fungerar perfekt!" << std::endl;
    std::cout << "✅ Om du inte fick några AddressSanitizer-fel ovanför detta, har du fixat minnesläckan!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}