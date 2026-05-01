#include <iostream>
#include <string>
#include <set>

// Uppgift: Fixa de tre felen i klassen NameList!
// a) Fixa minnesläckan.
// b) Fixa utskriften (inga hexadecimala minnesadresser).
// c) Fixa sorteringen (alfabetisk ordning).

class NameList {
public:
    NameList() {}
    ~NameList() {} // Fixa minnesläckan här

    void insert(const std::string& name) {
        names.insert(new std::string(name));
    }

    void printSorted() const {
        for (list_type::const_iterator it = names.begin(); it != names.end(); ++it) {
            std::cout << *it << std::endl; // Fixa utskriften här
        }
    }

private:
    // Tips: Du behöver förmodligen ändra hur set:et jämför elementen för att lösa c)
    typedef std::set<std::string*> list_type;
    list_type names;
};

