#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>

#include "student.cpp"

void run_tests() {
    std::istringstream iss("to be or not to be");
    std::vector<word> res = read_words(iss);

    // Kontrollera antal unika ord
    assert(res.size() == 4 && "Ska vara 4 unika ord");

    // Kontrollera sortering och frekvens
    // "be" (2), "not" (1), "or" (1), "to" (2)
    assert(res[0].get_word() == "be" && res[0].get_freq() == 2);
    assert(res[1].get_word() == "not" && res[1].get_freq() == 1);
    assert(res[2].get_word() == "or" && res[2].get_freq() == 1);
    assert(res[3].get_word() == "to" && res[3].get_freq() == 2);

    std::cout << "✅ Uppgift 2: Inläsning och frekvensräkning fungerar!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}