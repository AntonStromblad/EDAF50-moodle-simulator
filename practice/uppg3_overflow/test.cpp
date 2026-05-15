// test.cpp
#include <iostream>
#include "student.cpp"

int main() {
    std::cout << "--- Kör test för Uppgift 1 ---\n";
    
    int original[] = {10, 20, 30, 40, 50};
    int size = 5;

    // Anropa funktionen som ska testas
    int* reversedArray = createReversedCopy(original, size);

    // Kontrollera om det sista elementet blev rätt (ska vara 10)
    if (reversedArray[4] == 10) {
        std::cout << "Test lyckades! Sista elementet är 10.\n";
    } else {
        std::cout << "Test misslyckades. Fel värde kopierades.\n";
    }

    // Städa upp minnet
    delete[] reversedArray;

    return 0;
}