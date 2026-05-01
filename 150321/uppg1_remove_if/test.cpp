#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#include "student.cpp"

void run_tests() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Ta bort alla jämna tal
    auto it = my_remove_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    
    // Ändra storleken faktiskt (the erase-remove idiom)
    v.erase(it, v.end());

    assert(v.size() == 5 && "Fel storlek efter remove_if!");
    assert(v[0] == 1 && v[1] == 3 && v[4] == 9 && "Fel element kvar i vektorn!");

    std::cout << "✅ Uppgift 1: Din my_remove_if fungerar precis som originalet!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}