#include <iterator>

// Uppgift 5: Implementera template-klassen result_iter och funktionen find_all.
// find_all letar upp element, och result_iter gör det möjligt att iterera
// enbart över dessa (och även ändra originalvärdet genom operator*).

template <typename Iter, typename T>
class result_iter {
public:
    // Lägg till lämplig konstruktor
    
    result_iter& operator++() ;
    
    T& operator*() ;
    
    bool operator!=(Iter other) const ;

private:
};

template <typename Iter, typename T>
result_iter<Iter, T> find_all(Iter first, Iter last, const T& val) ;