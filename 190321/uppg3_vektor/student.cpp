#include <initializer_list>
#include <algorithm>
#include <functional> // För std::plus

template <typename T>
class Vektor {
public:
    Vektor(std::size_t n) : sz(n), p(new T[n]{}) {}
    ~Vektor() { delete[] p; }

    // Kopieringskonstruktor (för att testerna ska rulla smidigt)
    Vektor(const Vektor& other) : sz(other.sz), p(new T[other.sz]) {
        std::copy(other.begin(), other.end(), p);
    }

    std::size_t length() const { return sz; }
    T* begin() { return p; }
    T* end() { return p + sz; }
    const T* begin() const { return p; }
    const T* end() const { return p + sz; }

    // Uppgift 3e: Implementera assign (använd std::copy)
    // Den ska ta en std::initializer_list och kopiera över den till vektorns pekare p.
    void assign(const std::initializer_list<T>& l);

private:
    std::size_t sz;
    T* p;
};

// Din implementation av assign här:


// Uppgift 3f: Implementera add-funktionen (fristående funktion)
// Den ska addera elementen parvis från c1 och c2 och spara i c3.
// Om c1 och c2 är olika långa ska "överskottet" från den längre vektorn 
// kopieras in direkt i c3.
// Tips: Använd std::transform och std::copy!
template <typename T>
void add(const Vektor<T>& c1, const Vektor<T>& c2, Vektor<T>& c3) {
    // Din kod här:
}