#include <iostream>
#include <vector>
#include <list>
#include <cassert>

#include "student.cpp"

void run_tests() {
    int from[] = {9, 2, 7, 8, 4, 5, 1, 6, 3};
    std::vector<int> to = {1, 3, 5, 7};

    // Använd din sort_inserter för att kopiera och sortera samtidigt
    std::copy(std::begin(from), std::end(from), sort_inserter(to));

    // Förväntat resultat: 1 1 2 3 3 4 5 5 6 7 7 8 9 9 (sorterat)
    assert(std::is_sorted(to.begin(), to.end()) && "Vektorn är inte sorterad!");
    assert(to.size() == 13 && "Vektorn har fel antal element!");
    
    // Testa med en annan behållare (t.ex. list)
    std::list<int> l;
    std::copy(std::begin(from), std::end(from), sort_inserter(l));
    assert(std::is_sorted(l.begin(), l.end()) && "Listan är inte sorterad!");

    std::cout << "✅ Uppgift 4: Din sort_insert_iterator sorterar elementen rätt vid varje insert!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}