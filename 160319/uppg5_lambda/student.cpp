#include <algorithm>

// Uppgift 5: Använd std::remove_copy_if med en lambda-funktion!
// Funktionen ska kopiera element från [first, last) till dest.
// Den ska "ta bort" (alltså hoppa över att kopiera) element om de är jämnt delbara med 'c'.
// Returnera en pekare (iterator) till slutet av den nyskapade arrayen 'dest'.

int* copy_without_multiples(int* first, int* last, int* dest, int c) {
    // Din kod här: Returnera resultatet av std::remove_copy_if!
}