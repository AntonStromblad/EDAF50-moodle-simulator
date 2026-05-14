#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Uppgift 2: Implementera klassen 'word' och funktionen 'read_words'.
// 'word' ska hålla en sträng och en räknare (frekvens).
// 'read_words' ska läsa ord för ord och hålla vektorn sorterad alfabetiskt.

class word {
public:
    word(const std::string &s);
    int get_freq() const;
    const std::string& get_word() const;
};


std::vector<word> read_words(std::istream& is) {
    // Din kod här.
    //Sorted alphabetically and by their frequencies
    //Krav: read_words must build the sorted vector by inserting each word at the right place when first encountering
    // it. You must use std::lower_bound to efficiently find a word (or where to insert it)
}

//sort_by_frequency

//sort_alphabetically