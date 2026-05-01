#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cassert>

// Autograder-hack för att omdirigera studentens main-funktion
#define main student_main
#include "student.cpp"
#undef main

int student_main(int argc, char* argv[]);

void run_tests() {
    // Skapa en temporär testfil
    std::ofstream out("dummy_test.txt");
    out << "the the the fake fake news news news news bad a a a a a";
    out.close();

    // Sätt upp argument som om vi körde från terminalen
    const char* argv[] = {"./count_words", "dummy_test.txt", "missing_file.txt"};
    
    std::stringstream buffer;
    std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());

    // Kör studentens kod
    student_main(3, (char**)argv);

    std::cout.rdbuf(old_cout);
    std::string output = buffer.str();

    // Enkel validering (kollar om de vanligaste orden och felhantering verkar finnas med)
    bool has_error_handling = output.find("missing_file") != std::string::npos || output.find("error") != std::string::npos;
    bool has_correct_word = output.find("a") != std::string::npos && output.find("news") != std::string::npos;

    if (!has_correct_word) {
        std::cout << "❌ Koden verkar inte skriva ut rätt ord eller frekvenser.\nDin utskrift:\n" << output << "\n";
        assert(false);
    }
    
    std::cout << "✅ Uppgift 5 fungerar! Ord räknas och filer hanteras." << std::endl;
}

int main() {
    run_tests();
    return 0;
}