#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <cstdio> 

#include "student.cpp"

void run_tests() {
    // Skapa en testfil
    std::ofstream out("grep_test.txt");
    out << "Detta är rad 1.\n";
    out << "Här finns ordet covfefe gömt.\n";
    out << "Detta är rad 3.\n";
    out << "Ännu en covfefe rad.\n";
    out.close();

    // Testa framgångsrik sökning
    std::stringstream buffer;
    std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());
    
    int result = print_matching_lines("covfefe", "grep_test.txt");
    
    // STÄDA UPP DIREKT!
    // Vi tar bort filen så fort din funktion har läst klart den. 
    // Då slipper vi skräpfiler även om en assert kraschar programmet på nästa rad.
    std::remove("grep_test.txt"); 
    
    std::cout.rdbuf(old_cout);
    std::string output = buffer.str();

    assert(result == 0 && "Funktionen måste returnera 0 vid success");
    assert(output.find("Här finns ordet") != std::string::npos && "Missade första matchningen");
    assert(output.find("Ännu en") != std::string::npos && "Missade andra matchningen");
    assert(output.find("rad 1") == std::string::npos && "Skrev ut en rad som inte matchade!");

    // Testa felaktig fil
    std::stringstream err_buffer;
    std::streambuf* old_cerr = std::cerr.rdbuf(err_buffer.rdbuf());
    
    int err_result = print_matching_lines("test", "finns_inte.txt");
    
    std::cerr.rdbuf(old_cerr);
    
    assert(err_result == 1 && "Funktionen måste returnera 1 om filen inte finns");
    assert(err_buffer.str().length() > 0 && "Du måste skriva ett felmeddelande till std::cerr om filen inte kunde öppnas");

    std::cout << "✅ print_matching_lines fungerar! Filer läses, rader filtreras och fel hanteras." << std::endl;
}

int main() {
    run_tests();
    return 0;
}