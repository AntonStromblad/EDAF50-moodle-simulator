#include <string>
#include <stdexcept>
#include <cstring>

// Uppgift 1: Implementera en förenklad version av std::string_view.
// Syftet med klassen är att tillhandahålla en "vy" av en sträng 
// (t.ex. en char-array eller en std::string) utan att kopiera datan.

class string_view {
public:
    using size_type = std::size_t;
    using const_iterator = const char*;

    // Deklarationer (Din uppgift är att implementera dessa nedanför klassen)
    string_view();
    string_view(const std::string& s);
    string_view(const std::string& s, size_type pos, size_type len);
    string_view(const char* s);
    string_view(const char* s, size_type len);

    size_type size() const;
    bool empty() const;
    const_iterator begin() const;
    const_iterator end() const;
    char operator[](size_type idx) const;
    char at(size_type idx) const; // Ska kasta std::out_of_range om idx >= sz
    string_view substr(size_type pos = 0) const;

private:
    const char* str;
    size_type sz;
};

// --- Din implementation av funktionerna här under ---