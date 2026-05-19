#include <iostream>
#include <algorithm> // std::copy är din bästa vän här!

// Uppvärmning 2: Minneshantering och Rule of Three
// Klassen IntArray är en dynamisk array av heltal.
// Den allokerar minne på heapen med 'new', men saknar Rule of Three!
// 
// DIN UPPGIFT:
// 1. Skriv en Destruktor som frigör minnet.
// 2. Skriv en Kopieringskonstruktor (Deep copy).
// 3. Skriv en Tilldelningsoperator (operator=) som hanterar "self-assignment" och gör en Deep copy.

class IntArray {
public:
    // Standardkonstruktor (Redan färdig)
    IntArray(size_t size) : m_size(size), m_data(new int[size]{}) {}

    // Getters och Setters (Låt dessa vara, de används av testerna)
    size_t size() const { return m_size; }
    int get(size_t index) const { return m_data[index]; }
    void set(size_t index, int value) { m_data[index] = value; }

private:
    size_t m_size;
    int* m_data;
};