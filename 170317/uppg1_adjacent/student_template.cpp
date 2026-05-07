#include <iterator>

// Uppgift 1: Implementera STL-funktionen adjacent_difference.
// Den beräknar skillnaden mellan intilliggande värden i range [first, last)
// och skriver till result. Det första elementet flyttas oförändrat.
// Exempel: {1, 1, 2, 3, 5, 9} -> {1, 0, 1, 1, 2, 4}

template<typename InputIterator, typename OutputIterator>
OutputIterator adjacent_difference(InputIterator first, InputIterator last, OutputIterator result) {
    // Din kod här!
}