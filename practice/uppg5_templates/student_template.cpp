#include <algorithm>
#include <iterator>

// copy_unique_elements

// Uppgiftsbeskrivning:
// Skapa en algoritm copy_unique_elements som tar ett input-iterator-intervall (first, last) och en output-iterator. Algoritmen ska kopiera element från input till output, men den ska hoppa över alla element som är exakt likadana som elementet direkt före det. Det allra första elementet ska alltid kopieras.

// Din algoritm ska returnera en iterator till positionen efter det sista skrivna elementet.

// Krav för full poäng:
// Du måste använda standardalgoritmen std::copy_if tillsammans med ett funktionsobjekt (klass/struct) som ett stateful predicate.
// Hint: Ditt predicate behöver komma ihåg vilket element som senast blev kopierat. Använd std::iterator_traits<It>::value_type för att veta vilken datatyp du ska spara detta tillstånd i!
// Uppgift: Skapa algoritmen copy_unique_elements.
// Tips: Du behöver en klass för ditt stateful predicate och en template-funktion!

// int main()
// {
//     // Exempel 1: Heltal
//     std::vector<int> v = {1, 1, 2, 3, 3, 3, 4, 1, 1};
//     auto out1 = std::ostream_iterator<int>(std::cout, ", ");
//     copy_unique_elements(begin(v), end(v), out1);
//     std::cout << std::endl;

//     // Exempel 2: Strängar
//     std::stringstream ss{"hello hello world world world ! ! hello"};
//     std::istream_iterator<std::string> it(ss);
//     std::istream_iterator<std::string> ie{};
//     auto out2 = std::ostream_iterator<std::string>(std::cout, " ");
//     copy_unique_elements(it, ie, out2);
//     std::cout << std::endl;
// }
// 1, 2, 3, 4, 1, 
// hello world ! hello