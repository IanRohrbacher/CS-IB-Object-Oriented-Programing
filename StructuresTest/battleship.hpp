#include <cstdlib>
#include <ctime>
#include <iostream>

#ifndef BATTLESHIP_HPP_
#define BATTLESHIP_HPP_

using std::cout; using std::cin; using std::endl;
using std::string;

//
// data structures definitions
//

const int fleetSize = 6; // number of battleships
const int fieldSize = 6;  // the field (ocean) is fieldSize * fieldSize

// coordinates (Location) of the ship and shots
struct Location {
    int x;  // 1 through fieldSize
    char y; // 'a' through fieldSize
};

// contains ship's coordinates (Location) and whether is was sunk
struct Ship {
    Location loc;
    bool sunk;
};


Location fire() { // asks the user to input the coordinates of the next shot
    int tempX;
    char tempY;
    while (true) {
        cout << "Where would you like to fire?";
        cin >> tempX;
        cin >> tempY;
        tempY = toupper(tempY);
        if ((tempX > 0 && tempX <= fieldSize) && (tempY >= 'A' && tempY <= 'F')) {
            break;
        }
        else {
            cout << "Invaled! Try Again. ";
        }
    }
    return { tempX, tempY };
};

Location pick() { // generates a random Location
    return { (int)(rand() % fieldSize) + 1, (char)((rand() % fieldSize) + 65) };
};

void printShip(const Ship& ship) { // prints the Location and status (sunk or not) of a single ship
    cout << "Ship at " << ship.loc.x << ship.loc.y << " is " << (ship.sunk ? "Sunk" : "Not Sunk") << endl;
}

bool match(const Ship& ship, const Location& location) {  // returns true if this Location matches the Location of the Ship returns false otherwise
    return ship.loc.x == location.x && ship.loc.y == location.y;
};

void sink(Ship& ship) { // sets "sunk" member variable of the ship to true
    ship.sunk = true;
};

void initialize(Ship ships[]) { // places every Ship in a Location where x-coordinate is -1 and y-coordinate is '*' (a star) to signify that the Ship is not deployed
    for (int i = 0; i < fieldSize; i++) {
        ships[i] = { {-1, '*'}, false };
    }
};

void printFleet(const Ship ships[]) { // prints the Locations of all the ships and whether they are sunk
    for (int i = 0; i < fieldSize; i++) {
        printShip(ships[i]);
    }
};

int check(const Ship ships[], const Location& location) { // returns the index of element of the array that matches the Location returns -1 if none do uses match()
    for (int i = 0; i < fieldSize; i++) {
        if (match(ships[i], location)) {
            return i;
        }
    }
    return -1;
};

void deploy(Ship ships[]) { // places an array of battleships in random Locations in the ocean
    Location location;
    for (int i = 0; i < fieldSize; i++) {
    while (true) {
        location = pick();

        if (!(match(ships[i], location))) {
            ships[i].loc.x = location.x;
            ships[i].loc.y = location.y;
            break;
        }
    }
    }

};

bool operational(const Ship ships[]) {  // returns true if at least one ship in the array is not sunk
    for (int i = 0; i < fleetSize; i++) {
        if (!ships[i].sunk) {
            return true;
        }
    }
    return false;
};

#endif // BATTLESHIP_HPP_