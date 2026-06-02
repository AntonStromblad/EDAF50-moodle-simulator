#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

// Inkludera din lösning
#include "student.cpp"

// Returnerar true om alla test passerar, annars false
bool run_tests() {
    // ---------------------------------------------------------
    // Test 1: Heltal (Kopiera bara när talet ändras)
    // ---------------------------------------------------------
    std::vector<int> v = {1, 1, 2, 3, 3, 3, 4, 1, 1};
    
    std::stringstream ss1;
    auto out1 = std::ostream_iterator<int>(ss1, ", ");
    
    // Anropar din funktion!
    copy_unique_elements(v.begin(), v.end(), out1);

    std::string output1 = ss1.str();
    // 1, 2, 3, 4, 1 förväntas (dubbletterna i rad rensas bort)
    std::string expected1 = "1, 2, 3, 4, 1, ";
    
    if (output1 != expected1) {
        std::cout << "\n==================================================\n";
        std::cout << "❌ TEST MISSLYCKADES: copy_unique_elements - Test 1 (heltal)\n";
        std::cout << "==================================================\n";
        std::cout << "--- FICK UTDATA ---\n" << output1 << "\n";
        std::cout << "-------------------\n";
        std::cout << "--- FÖRVÄNTAT   ---\n" << expected1 << "\n";
        std::cout << "==================================================\n" << std::endl;
        return false;
    }

    // ---------------------------------------------------------
    // Test 2: Strängar
    // ---------------------------------------------------------
    std::stringstream ss{"hello hello world world world ! ! hello"};
    std::istream_iterator<std::string> it(ss);
    std::istream_iterator<std::string> ie{};
    
    std::stringstream ss2;
    auto out2 = std::ostream_iterator<std::string>(ss2, " ");
    
    // Anropar din funktion!
    copy_unique_elements(it, ie, out2);

    std::string output2 = ss2.str();
    std::string expected2 = "hello world ! hello ";
    
    if (output2 != expected2) {
        std::cout << "\n==================================================\n";
        std::cout << "❌ TEST MISSLYCKADES: copy_unique_elements - Test 2 (strängar)\n";
        std::cout << "==================================================\n";
        std::cout << "--- FICK UTDATA ---\n" << output2 << "\n";
        std::cout << "-------------------\n";
        std::cout << "--- FÖRVÄNTAT   ---\n" << expected2 << "\n";
        std::cout << "==================================================\n" << std::endl;
        return false;
    }

    std::cout << "✅ Snyggt! copy_unique_elements fungerar perfekt med båda testfallen!" << std::endl;
    return true;
}

int main() {
    // Returnera 1 vid fel, 0 vid succé
    if (!run_tests()) {
        return 1;
    }
    return 0;
}