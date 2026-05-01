#include <iostream>
#include <sstream>
#include <cassert>

#include "student.cpp"

void run_tests() {
    Sensors sensors;
    
    // 1. Läs in XML och kolla att värden sparades i mappen
    sensors.update("http://owserver1.lth.se/detail.xml");
    
    assert(sensors.getTemp("06000006AE3F4528") == 23.5 && "Fel temperatur inläst för första sensorn!");
    assert(sensors.getTemp("07000006AE3F4528") == 19.2 && "Fel temperatur inläst för andra sensorn!");
    
    // 2. Felhantering
    sensors.update("http://trasig-url.lth.se"); // Ska inte krascha, bara ignoreras

    bool threw = false;
    try {
        sensors.getTemp("FinnsInte");
    } catch (const std::runtime_error&) {
        threw = true;
    }
    assert(threw && "getTemp ska kasta std::runtime_error om sensorn inte hittas!");

    // 3. Utskrift
    std::stringstream buffer;
    std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());
    sensors.print();
    std::cout.rdbuf(old_cout);
    
    std::string out = buffer.str();
    assert(out.find("06000006AE3F4528 23.5") != std::string::npos && "print() skriver inte ut i rätt format!");

    std::cout << "✅ Uppgift 4: Sensors-klassen parsar XML och hanterar data korrekt!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}