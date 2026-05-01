#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    double x, y;
    double distance(const Point& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }
};

class Tour {
public:
    void addPoint(const Point& p) {
        cities.push_back(p);
    }

    double totalDistance() const {
        if (cities.empty()) return 0.0;
        double dist = 0.0;
        for (size_t i = 0; i < cities.size() - 1; ++i) {
            dist += cities[i].distance(cities[i+1]);
        }
        dist += cities.back().distance(cities.front()); // Tillbaka till start
        return dist;
    }

    // Uppgift 3: Närmaste granne-metoden
    void nearestNeighbor() {
        // Din kod här
    }

    // Uppgift 4: Optimal väg (undersök alla kombinationer)
    void optimalTour() {
        // Din kod här (tips: std::next_permutation)
    }

    // Uppgift 5: Slumpmässiga byten
    void randomSwap() {
        // Din kod här
    }

    // Uppgift 6: 2-opt metoden
    void twoOpt() {
        // Din kod här
    }

    std::vector<Point> cities;
};