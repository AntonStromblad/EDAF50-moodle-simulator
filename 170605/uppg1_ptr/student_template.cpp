// student.cpp
// Fixa klassen enligt instruktionerna!

class Ptr {
public:
    Ptr(int* p): curr(p) {}
    
    // a) Fixa denna så att det går att skriva till pekaren (returnera en referens!)
    int operator*() const { return *curr; }

    // b) Lägg till operator!= och operator++ (prefix) här

private:
    int* curr;
};

// När du gör uppgift b), glöm inte att du måste göra om HELA klassen till en template:
// template <typename T>
// class Ptr { ... }