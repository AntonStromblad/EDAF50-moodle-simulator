#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

// Vi inkluderar din lösning direkt (ett smidigt fulhack för autograders)
#include "student.cpp"

void run_tests() {
    int a[] = {1, 2, 3, 4};
    assert(is_strict_monotonic(a, a+4) == true && "Test 1 misslyckades: {1, 2, 3, 4} ska vara monoton");

    int b[] = {4, 3, 2, 1};
    assert(is_strict_monotonic(b, b+4) == true && "Test 2 misslyckades: {4, 3, 2, 1} ska vara monoton");

    int c[] = {1, 2, 7, 3, 4};
    assert(is_strict_monotonic(c, c+5) == false && "Test 3 misslyckades: {1, 2, 7, 3, 4} ska INTE vara monoton");

    std::vector<std::string> v = {"Despite", "the", "constant", "negative", "press", "covfefe"};
    assert(is_strict_monotonic(v.begin(), v.end()) == false && "Test 4 misslyckades: Osorterad vektor ska INTE vara monoton");

    sort(v.begin(), v.end());
    assert(is_strict_monotonic(v.begin(), v.end()) == true && "Test 5 misslyckades: Sorterad vektor ska vara monoton");
    
    std::cout << "Bravo! Din kod klarade alla testfall från tentan." << std::endl;
}

int main() {
    run_tests();
    return 0;
}