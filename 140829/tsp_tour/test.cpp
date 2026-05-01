#include <iostream>
#include <cassert>
#include "student.cpp"

void run_tests() {
    Tour t;
    t.addPoint({0, 0});
    t.addPoint({0, 10});
    t.addPoint({10, 10});
    t.addPoint({10, 0});

    double initial_dist = t.totalDistance();

    t.optimalTour();
    assert(t.totalDistance() <= initial_dist && "Uppgift 4: Optimal tour ska inte vara sämre än startordningen!");

    t.nearestNeighbor();
    assert(t.totalDistance() > 0 && "Uppgift 3: Nearest neighbor kraschade eller nollställde turen!");

    std::cout << "✅ TSP-funktionerna kördes utan att krascha! Du måste själv verifiera algoritmernas logik i detalj." << std::endl;
}

int main() {
    run_tests();
    return 0;
}