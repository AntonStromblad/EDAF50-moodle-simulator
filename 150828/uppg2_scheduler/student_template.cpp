#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>

// Uppgift 2: Implementera metoderna schedule() och print() för klassen Scheduler.

class Scheduler {
public:
    using row_type = std::bitset<80>;

    // Konstruktorn är given för att förenkla inläsningen av "rätt" bit-ordning
    Scheduler(std::istream& in) {
        std::string line;
        while (std::getline(in, line)) {
            // Omvandla alla bokstäver till '1' och mellanslag till '0'
            std::string bits = "";
            for (char c : line) {
                bits += (c == ' ') ? '0' : '1';
            }
            // Bitset läser höger-till-vänster, så vi vänder strängen
            std::reverse(bits.begin(), bits.end());
            rows.push_back(row_type(bits));
        }
    }

    // a) Sortera raderna så att raden med flest antal ettor hamnar först.
    // Sedan, för varje rad (från index 1 och framåt), skifta raden åt 
    // vänster (<<= 1) tills den inte längre krockar med någon av de TIDIGARE raderna.
    void schedule();

    // b) Skriv ut varje rad till out-strömmen som en sträng av 1:or och 0:or
    void print(std::ostream& out) const;

private:
    std::vector<row_type> rows;

    // Hjälpfunktion: Kontrollerar om rad 'row_nbr' krockar med någon av raderna OVANFÖR den.
    // Två rader krockar om de har en etta på samma position (använd bitvis AND).
    bool collides_with(int row_nbr) const {
        for (int i = 0; i < row_nbr; ++i) {
            if ((rows[i] & rows[row_nbr]).any()) {
                return true;
            }
        }
        return false;
    }
};

// Din implementation av schedule() och print() här: