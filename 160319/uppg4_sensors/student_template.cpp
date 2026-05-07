#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <iterator>

// GIVEN KOD: En mock-klass för URLstream som beskrivs i tentan.
// Den fungerar precis som en istream/stringstream.
class URLstream : public std::stringstream {
public:
    URLstream(const std::string& url) {
        if (url == "http://owserver1.lth.se/detail.xml") {
            // Vi skickar in en förenklad version av XML:en från tentan
            str("<ROMId>06000006AE3F4528</ROMId><Temperature Units=\"Centigrade\">23.5</Temperature>\n"
                "<ROMId>07000006AE3F4528</ROMId><Temperature Units=\"Centigrade\">19.2</Temperature>");
        } else {
            setstate(std::ios_base::failbit);
        }
    }
};

// Uppgift 4: Implementera metoderna för klassen Sensors
class Sensors {
public:
    Sensors() = default;
    
    // Läs XML via URLstream och uppdatera sensorernas mätvärden
    // Vid nätverksfel (t.ex. failbit sätts) ska funktionen avbrytas utan att krascha.
    void update(std::string url);
    
    // Returnera senaste tempen (kasta std::runtime_error om sensorn inte finns)
    double getTemp(const std::string& id) const;
    
    // Skriv ut alla sensorer i ordning (id temp) med std::cout
    void print() const;

private:
    std::map<std::string, double> values;
};

// Din implementation av update, getTemp och print här: