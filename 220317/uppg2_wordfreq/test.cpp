#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "student.cpp"

// En liten hjälpfunktion för att snyggare hantera tester
bool check_test(bool condition, const std::string& test_name, const std::string& error_info = "") {
    if (condition) {
        std::cout << "  [OK]  " << test_name << "\n";
        return true;
    } else {
        std::cout << "  [FEL] " << test_name << "\n";
        if (!error_info.empty()) {
            std::cout << "        -> Info: " << error_info << "\n";
        }
        return false;
    }
}

void run_tests() {
    std::cout << "--- Startar tester för Uppgift 2 ---\n";
    std::istringstream iss("to be or not to be");
    
    std::cout << "Läser in texten: \"to be or not to be\"...\n";
    std::vector<word> res = read_words(iss);

    bool all_passed = true;

    // 1. Kontrollera antal unika ord
    all_passed &= check_test(res.size() == 4, 
                             "Rätt antal unika ord", 
                             "Förväntade 4, men fick " + std::to_string(res.size()));

    // 2. Kontrollera sortering och frekvens (bara om vi faktiskt har 4 ord)
    if (res.size() == 4) {
        all_passed &= check_test(res[0].get_word() == "be" && res[0].get_freq() == 2, 
                                 "Ord 1: 'be' (frekvens 2)");
                                 
        all_passed &= check_test(res[1].get_word() == "not" && res[1].get_freq() == 1, 
                                 "Ord 2: 'not' (frekvens 1)");
                                 
        all_passed &= check_test(res[2].get_word() == "or" && res[2].get_freq() == 1, 
                                 "Ord 3: 'or' (frekvens 1)");
                                 
        all_passed &= check_test(res[3].get_word() == "to" && res[3].get_freq() == 2, 
                                 "Ord 4: 'to' (frekvens 2)");
    } else {
        std::cout << "  [---] Skippar detaljtester för orden eftersom antalet ord är fel.\n";
    }

    std::cout << "------------------------------------\n";
    
    // Slutresultat
    if (all_passed) {
        std::cout << "✅ Uppgift 2: Alla tester passerade! Inläsning och frekvensräkning fungerar!\n";
    } else {
        std::cout << "❌ Uppgift 2: Vissa tester misslyckades. Se utskriften ovan för detaljer.\n";
    }
}

int main() {
    run_tests();
    return 0;
}