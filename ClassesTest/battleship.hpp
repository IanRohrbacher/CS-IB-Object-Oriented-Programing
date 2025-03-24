#include <cstdlib>
#include <ctime>
#include <iostream>

#ifndef BATTLESHIP_HPP_
#define BATTLESHIP_HPP_

using std::cout; using std::cin; using std::endl;
using std::string;

// coordinates (location) of the ship and shots
class Location {
public:
    Location(); // void constructor, assigns -1 to X coord, and * to Y coord 
    void pick(); // picks a random location
    void fire(); // asks the user to input coordinates of the next shot
    void print() const { cout << x_ << y_; } // prints location in format "a1"

    // predicate returns true if the two locations match
    friend bool compare(const Location& LocationOne, const Location& LocationTwo)
    { return (LocationOne.x_ == LocationTwo.x_) && (LocationOne.y_ == LocationTwo.y_); };

private:
    static const int fieldSize_ = 6; // the field (ocean) is fieldSize X fieldSize
    int x_;  // 1 through fieldSize
    char y_; // 'a' through fieldSize
};

Location::Location() {
    x_ = -1;
    y_ = '*';
}

void Location::pick() {
    x_ = (rand() % fieldSize_) + 1;
    y_ = (rand() % fieldSize_) + 65;
}

void Location::fire() {
    int tempX;
    char tempY;
    while (true) {
        cout << "Where would you like to fire? ";
        cin >> tempX;
        cin >> tempY;
        tempY = toupper(tempY);
        if ((tempX > 0 && tempX <= fieldSize_) && (tempY >= 'A' && tempY <= 'F')) {
            break;
        }
        else {
            cout << "Invaled! Try Again. ";
        }
    }
    x_ = tempX;
    y_ = tempY;
}

// contains ship's coordinates (location) and whether is was sunk
class Ship {
public:
    Ship(); // void constructor, sets sunk=false
    bool match(const Location& location) const { return compare(loc_, location); } // returns true if this location matches the ship's location
    bool isSunk() const { return sunk_; } // checks to see if the ship is sunk
    void sink() { sunk_ = true; } // sets "sunk" member variable of the ship to true
    void setLocation(const Location& location) { loc_ = location; } // deploys the ship at the specified location
    void printShip() const; // prints location and status of the ship

private:
    Location loc_;
    bool sunk_;
};

Ship::Ship() {
    loc_ = Location();
    sunk_ = false;
}

void Ship::printShip() const {
    cout << "Ship at ";
    loc_.print();
    cout << " is " << (sunk_ ? "Sunk" : "Not Sunk") << endl;
}

// contains the fleet of the deployed ships
class Fleet {
public:
    void deployFleet(); // deploys the ships in random locations
    // of the ocean
    bool operational() const; // predicate returns true if at least
    // one ship in the fleet is not sunk
    bool isHitNSink(const Location&); // returns true if there was a deployed
    // ship at this location (hit) and sinks it
    // otherwise returns false (miss)
    void printFleet() const; // prints out locations of ships in fleet

private:
    static const int fleetSize_ = 8; // number of battleships
    int check(const Location&) const;  // returns index of the ship 
    // that matches location
    // -1 if none match
    Ship ships_[fleetSize_];        // battleships of the fleet
};

void Fleet::deployFleet() {
    Location location;

    for (int i = 0; i < fleetSize_; i++) {
        location.pick();
        while (true) {
            if (check(location) == -1) {
                ships_[i].setLocation(location);
                break;
            }
            location.pick();
        }
    }
}

bool Fleet::operational() const {  // returns true if at least one ship in the array is not sunk
    for (int i = 0; i < fleetSize_; i++) {
        if (!ships_[i].isSunk()) {
            return true;
        }
    }
    return false;
};

bool Fleet::isHitNSink(const Location& location) {
    int num = check(location);
    if (num == -1) {
        return false;
    }
    ships_[num].sink();
    return true;
}

void Fleet::printFleet() const {
    for (int i = 0; i < fleetSize_; i++) {
        ships_[i].printShip();
    }
}

int Fleet::check(const Location& location) const {
    for (int i = 0; i < fleetSize_; i++) {
        if (ships_[i].match(location)) {
            return i;
        }
    }
    return -1;
}

#endif /* BATTLESHIP_HPP_ */