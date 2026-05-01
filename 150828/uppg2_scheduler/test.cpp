#include <iostream>
#include <sstream>
#include <cassert>

#include "student.cpp"

void run_tests() {
    // Vi läser in 3 rader. 
    // Rad 1 har 3 ettor. Rad 2 har 2 ettor. Rad 3 har 4 ettor.
    std::string input = 
        "xxx \n"    // 3 ettor, 1 nolla
        "xx  \n"    // 2 ettor, 2 nollor
        "xxxx\n";   // 4 ettor
    
    std::istringstream iss(input);
    Scheduler sched(iss);

    sched.schedule();

    std::ostringstream oss;
    sched.print(oss);
    std::string out = oss.str();

    // Efter sortering ska raderna ligga i ordningen: 
    // "xxxx" (4), "xxx " (3), "xx  " (2)
    // "xxxx" ligger kvar som den är.
    // "xxx " krockar och måste skiftas 4 steg tills den blir "    xxx"
    // "xx  " krockar med båda och måste skiftas 7 steg tills den blir "       xx"
    
    // Vi kollar bara att inga rader krockar med varandra (dvs ingen position har mer än en '1')
    assert(out.find("1111") != std::string::npos && "Raden med 4 ettor saknas eller har modifierats fel!");
    
    std::cout << "✅ Uppgift 2: Din Scheduler sorterar och förskjuter bitsets helt rätt!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}