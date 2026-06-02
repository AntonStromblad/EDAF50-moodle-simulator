#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>

// Inkludera din lösning
#include "student.cpp"

// Returnerar true om testet passerar, annars false
bool run_tests() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    int x = 4;
    
    std::stringstream buffer;
    // Spara originalbuffern och omdirigera std::cout till vår stringstream
    std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());

    // 1. Testar med ursprungligt x = 4
    auto f = my_less_than<int>(x);
    std::copy_if(v.begin(), v.end(), std::ostream_iterator<int>(std::cout), f);
    std::cout << "\n";
    
    // 2. Uppdatera x. Eftersom functorn/lambdat ska fånga by-reference 
    // måste detta påverka resultatet!
    x = 7;
    std::copy_if(v.begin(), v.end(), std::ostream_iterator<int>(std::cout), f);
    std::cout << "\n";

    // Återställ std::cout omedelbart efter att testsekvensen är klar
    std::cout.rdbuf(old_cout);
    
    std::string output = buffer.str();
    std::string expected = "123\n123456\n";
    
    if (output != expected) {
        std::cout << "\n==================================================\n";
        std::cout << "❌ TEST MISSLYCKADES: Uppgift 6 (my_less_than)\n";
        std::cout << "==================================================\n";
        std::cout << "--- FICK UTDATA ---\n" << output;
        std::cout << "-------------------\n";
        std::cout << "--- FÖRVÄNTAT   ---\n" << expected;
        std::cout << "==================================================\n" << std::endl;
        return false;
    }
    
    std::cout << "✅ Uppgift 6: my_less_than fungerar utmärkt!" << std::endl;
    return true;
}

int main() {
    // Om testet misslyckas returnerar vi 1 till operativsystemet (standard för fel)
    if (!run_tests()) {
        return 1;
    }
    return 0;
}