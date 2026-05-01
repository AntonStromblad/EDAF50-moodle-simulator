#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <cassert>

// Inkludera din lösning
#include "student.cpp"

// Denna funktion är given i tentan och bygger på att din token-klass är rätt skriven.
void remove_html(std::istream& is, std::ostream& os) {
    std::istream_iterator<token> iit(is);
    std::istream_iterator<token> ie{};
    std::ostream_iterator<char> oi(os);
    
    // För att kompilatorn ska tillåta detta krävs std::noskipws så den inte kastar bort radbrytningar
    is >> std::noskipws; 
    
    std::copy(iit, ie, oi);
}

void run_tests() {
    // Exemplet från tentan
    std::string html =
        "<html><body><H1>Test</H1>\n"
        "<p>This is a test with a list</p>\n"
        "<ul><li>item1\n"
        "<li>item2\n"
        "<li>item3</ul>\n"
        "<p>and some text with special chars (&lt;, &amp; and &gt;) to be translated</p>\n"
        "</body></html>";

    std::istringstream is(html);
    std::stringstream buffer;
    
    remove_html(is, buffer);
    
    std::string output = buffer.str();
    
    std::string expected = 
        "Test\n"
        "This is a test with a list\n"
        "item1\n"
        "item2\n"
        "item3\n"
        "and some text with special chars (<, &, and >) to be translated\n";

    if (output != expected) {
        std::cout << "❌ Utskriften stämde inte!\n\nFick:\n" << output << "\n\nFörväntade:\n" << expected;
        assert(false);
    }

    std::cout << "✅ Perfekt! Din token-klass rensade bort HTML och översatte tecknen klockrent!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}