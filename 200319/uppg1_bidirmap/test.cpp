#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cassert>
#include <iterator>
#include <algorithm>

using std::cout;

// Inkludera din lösning
#include "student.cpp"

// --- Test för 1a ---
bool test_invert() {
    cout << "test_invert:\n";
    std::map<int, std::string> m{{1, "kalle"}, {2, "anka"}};
    assert(m[1] == "kalle");
    assert(m[2] == "anka");
    
    auto inv = invert_map(m);
    auto res = true;
    if (inv["kalle"] != 1) {res = false; cout << "wrong value for kalle\n";}
    if (inv["anka"] != 2) {res = false; cout << "wrong value for anka\n";}
    
    std::map<int, char> n{{1, 'a'}, {2, 'b'}};
    assert(n[1] == 'a');
    assert(n[2] == 'b');
    auto inv2 = invert_map(n);
    if(inv2['a'] != 1) {res = false; cout << "wrong value for a\n";}
    if(inv2['b'] != 2) {res = false; cout << "wrong value for b\n";}
    
    cout << "test_invert done\n";
    return res;
}

// --- Hjälpfunktioner och Setup för 1b och 1c ---
bool test_lookup(const std::map<std::string, int>& m, const std::string &k, int v) {
    try {
        if (m.at(k) == v) return true;
        cout << "Wrong value for " << k << "\n";
        return false;
    } catch (...) {
        return false;
    }
}

bidir_map<std::string, int> setup() {
    bidir_map<std::string, int> m{
        {"a", 1}, {"d", 2},
        {"b", 2}, {"e", 1},
        {"c", 1}, {"f", 3}
    };
    return m;
}

// --- Test för 1b ---
bool test_forward(const std::map<std::string, int>& m) {
    bool res = true;
    cout << "test_forward:\n";
    res &= test_lookup(m, "a", 1);
    res &= test_lookup(m, "b", 2);
    res &= test_lookup(m, "c", 1);
    res &= test_lookup(m, "d", 2);
    res &= test_lookup(m, "e", 1);
    res &= test_lookup(m, "f", 3);
    
    auto it = m.find("a");
    if (it == m.end() || it->second != 1) {
        cout << "wrong value for find(\"a\")\n";
        res = false;
    }
    return res;
}

bool test_reverse_at(const bidir_map<std::string, int>& m) {
    cout << "test_reverse_at:\n";
    auto res = true;
    auto x1 = m.at(1);
    std::string ones = "ace";
    if (ones.find(x1) == std::string::npos) {
        cout << "Wrong key for 1\n";
        res = false;
    }
    auto x2 = m.at(2);
    std::string twos = "bd";
    if (twos.find(x2) == std::string::npos) {
        cout << "Wrong key for 2\n";
        res = false;
    }
    return res;
}

// --- Test för 1c ---
bool test_reverse_find(const bidir_map<std::string, int>& m) {
    cout << "test_reverse_find:\n";
    auto res = true;
    auto p1 = m.find(1);
    std::vector<std::string> vone;
    std::copy(p1.first, p1.second, std::back_inserter(vone));
    if (vone != std::vector<std::string>{"a", "c", "e"}) {
        cout << "Wrong keys for 1\n";
        res = false;
    }
    
    auto p2 = m.find(2);
    std::vector<std::string> vtwo;
    std::copy(p2.first, p2.second, std::back_inserter(vtwo));
    if (vtwo != std::vector<std::string>{"b", "d"}) {
        cout << "Wrong keys for 2\n";
        res = false;
    }
    
    auto pe = m.find(4);
    if (pe.first != pe.second) {
        cout << "Wrong: returned key for 4\n";
        res = false;
    }
    return res;
}

void run_tests() {
    assert(test_invert() && "Test 1a (invert_map) misslyckades");
    
    auto m = setup();
    
    assert(test_forward(m) && "Test 1b (forward / map-inheritance) misslyckades");
    assert(test_reverse_at(m) && "Test 1b (reverse_at) misslyckades");
    
    assert(test_reverse_find(m) && "Test 1c (reverse_find med iterator) misslyckades");
    
    std::cout << "\n✅ Helt otroligt jobbat! Du har implementerat en bidir_map och klarat tentans tyngsta uppgift (32 poäng)!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}