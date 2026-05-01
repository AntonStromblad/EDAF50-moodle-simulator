#include <iostream>
#include <string>
#include <cassert>
#include "student.cpp"

void run_tests() {
    std::string s1 = concat2("testing", 1);
    std::string s2 = concat2("test", 2);
    std::string s3 = concat2("testing, testing, testing", 5);

    assert(s1 == "testing1" && "Fel på test 1");
    assert(s2 == "test2" && "Fel på test 2");
    assert(s3 == "testing, testing, testing5" && "Fel på test 3");

    std::cout << "✅ concat2 fungerar! Strängarna och heltalen slogs ihop korrekt." << std::endl;
}

int main() {
    run_tests();
    return 0;
}