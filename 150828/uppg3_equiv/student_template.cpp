#include <vector>
#include <bitset>
#include <algorithm>

// Uppgift 3: Implementera klassen EquivalenceClasses.
// Den använder en vector av bitsets för att hålla koll på vilka heltal som hör ihop.

class EquivalenceClasses {
public:
    // Slå ihop de två klasserna som a och b tillhör.
    // Om varken a eller b finns i någon klass: skapa en ny klass {a, b}.
    // Om bara a finns i en klass: lägg in b i den klassen (och tvärtom).
    // Om a och b finns i OLIKA klasser: Slå ihop dem med bitvis OR (|=) och ta bort den ena från vektorn.
    void join(int a, int b);

    // Hitta det minsta heltalet i samma klass som n.
    // Om n inte finns i någon klass, returnera n.
    int least(int n);

private:
    using set_type = std::bitset<256>;
    std::vector<set_type> sets;

    // Frivilligt tips: Skapa en hjälpfunktion för att hitta vilken klass (set) 
    // ett nummer tillhör. Det gör join och least mycket enklare!
    // std::vector<set_type>::iterator find_set(int n);
};

// Din implementation av metoderna här: