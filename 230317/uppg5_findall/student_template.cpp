#include <iterator>

// Uppgift 5: Implementera template-klassen result_iter och funktionen find_all.
// find_all letar upp element, och result_iter gör det möjligt att iterera
// enbart över dessa (och även ändra originalvärdet genom operator*).

template <typename Iter, typename T>
class result_iter {
public:
    // Lägg till lämplig konstruktor
    
    result_iter& operator++() {
        // Din kod här
        return *this;
    }
    
    T& operator*() {
        // Din kod här
    }
    
    bool operator!=(Iter other) const {
        // Din kod här (Notera att du jämför med bas-iteratorn Iter, t.ex. end())
    }

private:
    // Din kod här (vilka medlemsvariabler behövs?)
};

template <typename Iter, typename T>
result_iter<Iter, T> find_all(Iter first, Iter last, const T& val) {
    // Din kod här
}