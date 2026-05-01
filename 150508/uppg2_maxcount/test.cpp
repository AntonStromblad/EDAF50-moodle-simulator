#include <iostream>
#include <vector>
#include <string>
#include <cassert>

#include "student.cpp"

void run_tests() {
    // Test 1: Heltal
    std::vector<int> v = {1, 5, 3, 5, 2, 5, 4};
    auto res1 = max_count(v.begin(), v.end());
    assert(res1.first == 5 && "Test 1: Fel maxvärde hittades!");
    assert(res1.second == 3 && "Test 1: Fel antal maxvärden räknades!");

    // Test 2: Strängar
    std::vector<std::string> words = {"äpple", "päron", "zebra", "banan", "zebra"};
    auto res2 = max_count(words.begin(), words.end());
    assert(res2.first == "zebra" && "Test 2: Fel maxvärde (sträng) hittades!");
    assert(res2.second == 2 && "Test 2: Fel antal maxvärden (strängar) räknades!");

    // Test 3: Tom sekvens
    std::vector<int> empty_vec;
    auto res3 = max_count(empty_vec.begin(), empty_vec.end());
    assert(res3.second == 0 && "Test 3: Tom sekvens ska ge 0 i antal!");

    std::cout << "✅ Uppgift 2: max_count fungerar klockrent med templates!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}