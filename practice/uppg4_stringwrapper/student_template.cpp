/*Uppgiftsbeskrivning (Din övning)

I C++ kan man skapa klasser som integrerar sömlöst med standardbiblioteket (STL) och beter sig som inbyggda typer.
 Betrakta följande exempelprogram som använder den egna klassen StringWrapper.

 a) Skriv en klass StringWrapper så att example1 kompilerar och körs korrekt. Förväntad utskrift:
example1:
C++-C++-C++-

b) Gör nödvändiga tillägg i StringWrapper så att example2 fungerar. Förväntad utskrift:
example2:
3 3 3
*/



#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <string>

std::vector<StringWrapper> example1() {
    std::cout << "example1:\n";
    std::vector<StringWrapper> words(3); 
    
    // std::fill fyller vektorn med ett startvärde
    std::fill(begin(words), end(words), "C++");

    // Skriver ut orden med ett bindestreck emellan
    std::ostream_iterator<std::string> it(std::cout, "-");
    std::copy(begin(words), end(words), it);
    std::cout << '\n';
    
    return words;
}

template <typename F>
auto get_result(const F& f) -> decltype(f()) {
    return f();
}

void example2(const std::vector<StringWrapper>& words) {
    std::cout << "example2:\n";
    std::vector<size_t> lengths;
    
    // Använder std::transform och vår get_result-template för att mäta längden på orden
    std::transform(begin(words), end(words), back_inserter(lengths), get_result<StringWrapper>);
    
    std::ostream_iterator<size_t> it(std::cout, " ");
    std::copy(begin(lengths), end(lengths), it);
    std::cout << '\n';
}

int main() {
    auto w = example1();
    example2(w);
}