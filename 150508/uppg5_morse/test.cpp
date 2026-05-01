#include <iostream>
#include <fstream>
#include <cassert>

#include "student.cpp"

void run_tests() {
    // Skapa en temporär morse.def fil för testet
    std::ofstream out("morse.def");
    out << "h ....\n";
    out << "e .\n";
    out << "j .---\n";
    out << "d -..\n";
    out << "u ..-\n";
    out.close();

    // Starta klassen (som i sin tur ska läsa morse.def)
    MorseCode mc;

    // Testa avkodningen
    std::string secret = ".... . .--- -.. ..-";
    std::string decoded = mc.decode(secret);

    assert(decoded == "hejdu" && "Morse-avkodningen gav felaktigt resultat!");

    std::cout << "✅ Uppgift 5: MorseCode-klassen läser filen och avkodar meddelandet perfekt!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}