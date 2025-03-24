#include "battleship.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {
    const int fleetSize = 6;

	srand(time(nullptr)); // random seed

    Ship myFleet[fleetSize];

    initialize(myFleet);
    deploy(myFleet);
    printFleet(myFleet);//test only
    
    Location input;
    int attempts = 0;
	while (operational(myFleet)) {
        //ask user where to launch and check if legal
        input = fire();
        //check input with all ships and if input maches a ship sink it
        if (check(myFleet, input) != -1) {
            cout << "Hit!";
            sink(myFleet[check(myFleet, input)]);
        }
        else {
            cout << "Missed!";
        }
        cout << endl;
        cout << endl;

        attempts++;
	}
    cout << "You Win! Only Took " << attempts << " Attempts!" << endl;
}