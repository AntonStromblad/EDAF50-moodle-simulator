#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

#include "student.cpp"

void run_tests() {
    std::string s1 = "Hej";
    std::string s2 = "Hej";
    std::string& s3 = s1;

    std::stringstream buffer;
    std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());

    // Test 1: Samma objekt
    compareObjects(s1, s3);
    // Test 2: Olika objekt, samma värde
    compareObjects(s1, s2);

    std::cout.rdbuf(old_cout);
    std::string out = buffer.str();

    assert(out.find("same object") != std::string::npos);
    assert(out.find("values of a and b are equal") != std::string::npos);

    std::cout << "✅ Uppgift 4: compareObjects identifierar identitet och värde korrekt!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}