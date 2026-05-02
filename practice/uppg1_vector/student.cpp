#include <iostream>

// Uppvärmning 1: Skapa en klass Vector2D som representerar en 2D-vektor (x, y).
// Du ska repetera följande:
// 1. Skapa en konstruktor som tar x och y som parametrar 
// 2. Implementera get_x() och get_y() som returnerar värdena
// 3. Överlagra operator+ så att man kan addera två Vector2D-objekt med varandra.

class Vector2D {
public:
    // Din konstruktor här 
    
    // Dina getters här

	Vector2D(const int x, const int y): x{x}, y{y} {};
	const int get_x(){return x;}
	const int get_y(){return y;}
    	
    // Din operator+ här. Den ska returnera en ny Vector2D.
    // Exempel: Vector2D operator+(const Vector2D& other) const;

private:
    int x;
    int y;
};

// Skriv dina implementationer antingen inuti klassen ovan, eller här nere.
