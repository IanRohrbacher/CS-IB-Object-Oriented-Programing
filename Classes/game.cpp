#include "battleship.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {
    srand(time(nullptr));
    Fleet fleet;
    fleet.deployFleet();
    bool cheat;

    while (true) {
        char ny;
        cout << "Would you like to cheat? Y/N ";
        cin >> ny;
        if (ny == 'Y' || ny == 'y') {
            cheat = true;
            cout << "shame" << endl;
            fleet.printFleet();
            break;
        }
        else if (ny == 'N' || ny == 'n') {
            cheat = false;
            cout << "Good Luck!" << endl;
            break;
        }
        else {
            cout << "Invalid Input Try Again!" << endl;
        }
    }

    cout << endl;

    int attempts = 0;
    Location userGuess;
    while (fleet.operational()) {
        userGuess.fire();
        attempts++;
        cout << "You " << (fleet.isHitNSink(userGuess) ? "Hit" : "Missed") << " A Ship At ";
        userGuess.print();
        cout << endl;
        if (cheat) {
            fleet.printFleet();
        }
        cout << endl;
    }
    cout << "You Win! Only Took " << attempts << " Attempts!" << endl;
}