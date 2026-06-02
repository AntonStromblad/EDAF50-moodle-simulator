#include <iostream>
#include <vector>
#include <sstream>
#include <string>

// Inkludera din lösning
#include "student.cpp"

// Returnerar true om testet passerar, annars false
bool run_tests() {
    std::vector<int> v = {1, 3, 2, 4, 3, 5, 4, 6, 5, 7, 3};
    
    // Tentans exempelkod
    // Ändrat begin(v) och end(v) till v.begin() och v.end()
    auto it = find_all(v.begin(), v.end(), 3);
    while (it != v.end()) {
        *it = 42;
        ++it;
    }
    
    std::stringstream buffer;
    for (auto x : v) {
        buffer << x << " ";
    }
    
    std::string output = buffer.str();
    std::string expected = "1 42 2 4 42 5 4 6 5 7 42 ";
    
    if (output != expected) {
        std::cout << "\n==================================================\n";
        std::cout << "❌ TEST MISSLYCKADES: Uppgift 5 (find_all & result_iter)\n";
        std::cout << "==================================================\n";
        std::cout << "--- FICK UTDATA ---\n" << output << "\n";
        std::cout << "-------------------\n";
        std::cout << "--- FÖRVÄNTAT   ---\n" << expected << "\n";
        std::cout << "==================================================\n" << std::endl;
        return false;
    }
    
    std::cout << "✅ Uppgift 5: find_all och result_iter fungerar utmärkt!" << std::endl;
    return true;
}

int main() {
    // Returnera 1 vid fel, 0 vid succé
    if (!run_tests()) {
        return 1;
    }
    return 0;
}