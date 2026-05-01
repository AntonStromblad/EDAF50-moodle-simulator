#include <iostream>
#include <cassert>

#include "student.cpp"

void run_tests() {
    int a[] = {5, 10, 3, 2, 8, 11};
    int b[6];

    // Vi skickar in c = 2. Då ska alla jämna tal (10, 2, 8) plockas bort!
    int* last_ptr = copy_without_multiples(a, a + 6, b, 2);
    int size = last_ptr - b;

    assert(size == 3 && "Fel antal element kopierades över!");
    assert(b[0] == 5);
    assert(b[1] == 3);
    assert(b[2] == 11);

    std::cout << "✅ Uppgift 5: remove_copy_if och din lambda fungerar perfekt!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}