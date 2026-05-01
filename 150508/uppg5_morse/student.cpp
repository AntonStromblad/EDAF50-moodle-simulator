#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

// Uppgift 5: Implementera klassen MorseCode
// Konstruktorn ska läsa från filen "morse.def".
// Filen ser ut så här:
// a .-
// b -...
// (osv)

class MorseCode {
public:
    MorseCode(); // Läs in filen och populera din map
    
    std::string decode(const std::string& code) const; // Översätt ".... . .---" till "hej"

private:
    std::map<std::string, char> table;
};

// Din implementation här: