#include <iterator>
#include <algorithm>

// Uppgift 4: Implementera klassen sort_insert_iterator och funktionen sort_inserter.

template <typename Container>
class sort_insert_iterator {
public:
    // Iterator-traits (behövs för att copy ska fungera)
    using iterator_category = std::output_iterator_tag;
    using value_type = void;
    using difference_type = void;
    using pointer = void;
    using reference = void;

    explicit sort_insert_iterator(Container& c) : container(&c) {}

    // Det är här magin händer. När man gör *it = value;
    sort_insert_iterator& operator=(const typename Container::value_type& value) {
        // 1. Hitta rätt plats att sätta in värdet på så att sorteringen behålls.
        // 2. Anropa container->insert(pos, value);
        return *this;
    }

    // Output-iteratorer kräver att dessa operatorer finns men de behöver inte göra något
    sort_insert_iterator& operator*() { return *this; }
    sort_insert_iterator& operator++() { return *this; }
    sort_insert_iterator& operator++(int) { return *this; }

private:
    Container* container;
};

// Hjälpfunktion för att slippa skriva template-typen manuellt
template <typename Container>
sort_insert_iterator<Container> sort_inserter(Container& c) {
    return sort_insert_iterator<Container>(c);
}