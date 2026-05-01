#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

// Eget exception enligt tentans specifikation
class illegal_number : public std::logic_error {
public:
    illegal_number() : std::logic_error("Illegal number") {}
};

// Uppgift 3: Implementera klassen BI (Big Integer)
// Den ska representera ett stort positivt heltal.
// Siffrorna lagras i en std::vector<unsigned char>.
// VIKTIGT: Den minst signifikanta siffran (ental) ska ligga på index 0!

class BI {
public:
    // Konstruktor (ska kasta illegal_number om strängen innehåller ogiltiga tecken)
    BI(const std::string& s) {
        // Din kod här!
    }

    // operator+=
    BI& operator+=(const BI& rhs) {
        // Din kod här!
        return *this;
    }

    // Vän-funktioner för utskrift och inläsning
    // friend std::ostream& operator<<(std::ostream& os, const BI& b);
    // friend std::istream& operator>>(std::istream& is, BI& b);

private:
    std::vector<unsigned char> digits;
};

// Din implementation av den fristående operator+ och ström-operatorer här: