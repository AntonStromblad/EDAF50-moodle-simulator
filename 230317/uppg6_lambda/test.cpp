#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <cassert>

// Inkludera din lösning
#include "student.cpp"

void run_tests() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    int x = 4;
    
    std::stringstream buffer;
    std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());

    // Testar med x = 4
    auto f = my_less_than(x);
    std::copy_if(begin(v), end(v), std::ostream_iterator<int>(std::cout), f);
    std::cout << "\n";
    
    // Eftersom lambda fångade by-reference ska uppdateringen av x påverka functorn!
    x = 7;
    std::copy_if(begin(v), end(v), std::ostream_iterator<int>(std::cout), f);
    std::cout << "\n";

    std::cout.rdbuf(old_cout);
    std::string output = buffer.str();

    std::string expected = "123\n123456\n";
    
    if (output != expected) {
        std::cout << "❌ Functorn betedde sig inte som det förväntade lambdat!\n\nFick:\n" << output << "Förväntade:\n" << expected;
        assert(false);
    }
    
    std::cout << "✅ Uppgift 6: my_less_than fungerar precis som capture-by-reference lambdat!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}