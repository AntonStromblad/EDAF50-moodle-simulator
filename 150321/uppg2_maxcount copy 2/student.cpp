#include <iterator>
#include <utility>

// Uppgift 2: Skriv template-funktionen max_count.
// Den ska ta två InputIterators (first och last) och returnera ett std::pair.
// Pairet ska innehålla:
// 1. Det största värdet i sekvensen.
// 2. Antalet gånger det värdet förekommer.
//
// Tips: Använd std::iterator_traits<InputIterator>::value_type för att ta 
// reda på vilken datatyp som iteratorn pekar på!

template <typename InputIterator>
std::pair<typename std::iterator_traits<InputIterator>::value_type, std::size_t>
max_count(InputIterator first, InputIterator last) {
    // Din kod här!
}