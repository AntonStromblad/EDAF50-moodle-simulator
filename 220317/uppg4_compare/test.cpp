#include <iostream>
#include <string>
#include <sstream>

#include "student.cpp" 

// En liten hjälpfunktion för att köra ett test i taget och ge bra feedback
template <typename T>
bool run_single_test(const std::string& test_name, const T& a, const T& b, const std::string& expected_output) {
    std::stringstream buffer;
    
    // Omdirigera cout till vår buffer
    std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());
    
    // Kör funktionen
    compareObjects(a, b);
    
    // Återställ cout DIREKT så vi kan skriva ut testresultatet till skärmen
    std::cout.rdbuf(old_cout);
    
    std::string actual_output = buffer.str();
    
    if (actual_output == expected_output) {
        std::cout << "✅ [OK]   " << test_name << "\n";
        return true;
    } else {
        std::cout << "❌ [FEL]  " << test_name << "\n";
        std::cout << "   -> Förväntade: '" << expected_output << "'\n";
        std::cout << "   -> Fick:       '" << actual_output << "'\n\n";
        return false;
    }
}

void run_tests() {
    std::string s1 = "Hej";
    std::string s2 = "Hej";
    std::string s3 = "Då";
    std::string& s1_ref = s1;

    std::cout << "--- Kör tester för Uppgift 4 ---\n";
    bool all_passed = true;

    // Test 1: Samma objekt (ska ha både samma adress och samma värde)
    // Obs: Båda strängarna skrivs ut i en klump eftersom din funktion saknar radbrytning.
    all_passed &= run_single_test("Samma objekt och värde", 
                                  s1, s1_ref, 
                                  "a and b is the same objectthe values of a and b are equal");

    // Test 2: Olika objekt, men samma värde
    all_passed &= run_single_test("Olika objekt, samma värde", 
                                  s1, s2, 
                                  "the values of a and b are equal");

    // Test 3: Olika objekt och olika värden (ska inte skriva ut något alls)
    all_passed &= run_single_test("Olika objekt, olika värden", 
                                  s1, s3, 
                                  "");

    std::cout << "--------------------------------\n";
    if (all_passed) {
        std::cout << "🌟 Alla tester godkända! compareObjects fungerar perfekt.\n";
    } else {
        std::cout << "⚠️ Vissa tester misslyckades. Läs felsökningen ovan.\n";
    }
}

int main() {
    run_tests();
    return 0;
}