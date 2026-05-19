#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <sstream>

// Inkludera din kod här
#include "student.cpp"

// --- LÄRARENS KOD ---

std::vector<StringWrapper> example1() {
    std::cout << "example1:\n";
    std::vector<StringWrapper> words(3);
    std::fill(begin(words), end(words), "C++");
    
    std::ostream_iterator<std::string> it(std::cout, "-");
    std::copy(begin(words), end(words), it);
    std::cout << '\n';
    return words;
}

template <typename F>
auto get_result(const F& f) -> decltype(f()) {
    return f();
}

void example2(const std::vector<StringWrapper>& words) {
    std::cout << "example2:\n";
    std::vector<size_t> lengths;
    std::transform(begin(words), end(words), back_inserter(lengths), get_result<StringWrapper>);
    std::ostream_iterator<size_t> it(std::cout, " ");
    std::copy(begin(lengths), end(lengths), it);
    std::cout << '\n';
}

// --- AUTOMATISERADE TESTER ---

bool test_part_a() {
    std::cout << "[TEST] Startar Uppgift A (example1)...\n";
    
    std::stringstream buffer;
    std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());

    auto words = example1();

    std::cout.rdbuf(old_cout);
    std::string output = buffer.str();
    std::string expected = "example1:\nC++-C++-C++-\n";

    if (output == expected && words.size() == 3) {
        std::cout << "✅ [UPPGIFT A]: Godkänd! example1() skriver ut C++-C++-C++-.\n\n";
        return true;
    } else {
        std::cout << "❌ [UPPGIFT A]: Misslyckades!\n";
        std::cout << "--- FÖRVÄNTAT ---\n" << expected;
        std::cout << "--- DITT RESULTAT ---\n" << output << "---------------------\n\n";
        return false;
    }
}

bool test_part_b(bool a_passed) {
    if (!a_passed) {
        std::cout << "⏭️ [UPPGIFT B]: Skippas eftersom Uppgift A inte är godkänd ännu.\n";
        return false;
    }

    std::cout << "[TEST] Startar Uppgift B (example2)...\n";

    std::stringstream buffer;
    std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());

    auto words = example1();
    buffer.str(""); // Rensa bufferten 

    example2(words);

    std::cout.rdbuf(old_cout);
    std::string output = buffer.str();
    std::string expected = "example2:\n3 3 3 \n";

    if (output == expected) {
        std::cout << "✅ [UPPGIFT B]: Godkänd! example2() räknar ut längderna korrekt.\n\n";
        return true;
    } else {
        std::cout << "❌ [UPPGIFT B]: Misslyckades!\n";
        std::cout << "--- FÖRVÄNTAT ---\n" << expected;
        std::cout << "--- DITT RESULTAT ---\n" << output << "---------------------\n\n";
        return false;
    }
}

int main() {
    std::cout << "====================================\n";
    std::cout << "Kör tester för StringWrapper\n";
    std::cout << "====================================\n\n";

    bool a_passed = test_part_a();
    bool b_passed = test_part_b(a_passed);

    if (a_passed && b_passed) {
        std::cout << "🌟 Fenomenalt! Båda delarna lösta perfekt.\n";
    }

    return 0;
}