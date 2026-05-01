#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#include "student.cpp"

void run_tests() {
    std::vector<int> source = {10, 20, 30};
    std::vector<int> dest;

    // Kopierar från source och pushar in i dest med hjälp av DIN back_inserter!
    std::copy(source.begin(), source.end(), back_inserter(dest));

    assert(dest.size() == 3 && "Vektorn fick inte rätt storlek!");
    assert(dest[0] == 10);
    assert(dest[1] == 20);
    assert(dest[2] == 30);

    std::cout << "✅ Uppgift 3: Din back_inserter och back_insert_iterator interagerar perfekt med std::copy!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}