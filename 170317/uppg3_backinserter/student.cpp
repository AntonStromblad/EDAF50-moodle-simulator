#include <vector>

// Uppgift 3: Implementera klassen back_insert_iterator och funktionen back_inserter.
// Dessa måste fungera med t.ex. std::copy enligt exemplet på tentan.

template <typename Container>
class back_insert_iterator {
public:
    // Tips: Konstruktorn måste ta emot containern (t.ex. en vektor) så att
    // vi vet var vi ska stoppa in elementen. Spara detta som en pekare eller referens.
    
    // Du behöver överlagra operator= så att den anropar push_back på din container.
    // Du behöver också överlagra operator* och operator++ (de kan bara returnera *this).
    
    // Din kod här:
};

// Hjälpfunktionen som skapar och returnerar iterator-objektet
template <typename Container>
back_insert_iterator<Container> back_inserter(Container& c) {
    // Din kod här:
}