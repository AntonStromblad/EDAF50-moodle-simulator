#include <algorithm>
#include <iterator>

// Uppgift 2: Skapa algoritmen copy_nth.
// Den tar in en start-iterator, slut-iterator, en output-iterator och ett heltal n.
// Krav från tentan: Du ska använda std::copy_if med ett funktionsobjekt (stateful predicate)
// för att lösa uppgiften. Den ska returnera en iterator till positionen efter sista insatta elementet.

// Din kod här (skriv både din functor-struct och funktionen copy_nth)