#include <iostream>
#include <cassert>

// Inkludera studentens kod
#include "student.cpp"

void run_tests() {
    // 1. Testa att grundfunktionen fungerar (Kräver ingen ändring av dig)
    IntArray a(5);
    a.set(0, 10);
    assert(a.get(0) == 10 && "Fel i standardkonstruktorn, kunde inte sätta värde.");

    // 2. Testa Kopieringskonstruktorn
    // Om du har gjort en "shallow copy" kommer 'b' och 'a' peka på samma minne.
    IntArray b = a; 
    b.set(0, 20); // Vi ändrar bara i kopian 'b'
    
    assert(a.get(0) == 10 && "Kopieringskonstruktorn misslyckades! Du gjorde en 'shallow copy' så originalet ändrades när kopian ändrades.");
    assert(b.get(0) == 20 && "Kunde inte ändra i kopian.");

    // 3. Testa Kopieringstilldelningsoperatorn (operator=)
    IntArray c(3);
    c = a; // Detta anropar operator=
    c.set(0, 30); // Vi ändrar bara i kopian 'c'
    
    assert(a.get(0) == 10 && "Tilldelningsoperatorn misslyckades! Du gjorde en 'shallow copy' (eller kopierade inte alls).");
    assert(c.get(0) == 30 && "Kunde inte ändra i det tilldelade objektet.");

    // 4. Testa 'Self-assignment' (Att tilldela ett objekt till sig självt)
    a = a; 
    assert(a.get(0) == 10 && "Din operator= raderade sin egen data vid 'self-assignment' (a = a)!");

    std::cout << "✅ Uppvärmning 2 avklarad! Minnet är säkrat, inga shallow copies hittades, och self-assignment hanteras perfekt." << std::endl;
}

int main() {
    run_tests();
    return 0;
}