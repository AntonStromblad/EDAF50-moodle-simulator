#include <iostream>
#include <string>
#include <cassert>
#include <vector>

#include "student.cpp"

void run_tests() {
    // Test 1: Konstruktorer och size/empty
    std::string s = "Hello World";
    string_view sv1(s);
    assert(sv1.size() == 11 && !sv1.empty());

    string_view sv2(s, 6, 5);
    assert(sv2.size() == 5);
    
    string_view sv3("Test");
    assert(sv3.size() == 4);

    string_view sv_empty;
    assert(sv_empty.empty() && sv_empty.size() == 0);

    // Test 2: Access och exceptions
    assert(sv1[0] == 'H');
    assert(sv1.at(6) == 'W');

    bool threw = false;
    try {
        sv1.at(100);
    } catch(const std::out_of_range&) {
        threw = true;
    }
    assert(threw && "at() ska kasta std::out_of_range vid index out of bounds");

    // Test 3: Substr
    string_view sub = sv1.substr(6);
    assert(sub.size() == 5 && sub[0] == 'W');

    // Test 4: Iteratorer (begin/end)
    std::vector<char> chars;
    for(auto c : sv3) {
        chars.push_back(c);
    }
    assert(chars.size() == 4 && chars[0] == 'T' && chars[3] == 't');

    std::cout << "✅ Uppgift 1: Din string_view fungerar utmärkt!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}