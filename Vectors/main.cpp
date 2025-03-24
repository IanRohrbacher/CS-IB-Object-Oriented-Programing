#include <vector>
#include <iostream>
#include <algorithm>

using std::cout; using std::cin; using std::endl;
using std::string; using std::vector;

int main() {

    string operation;
    vector<char> arrList;
    string character;

    vector<char>::iterator found;
    int index = -1;

    do {
        cout << "Enter Operation [a/r/q] and \'Character\': ";
        cin >> operation;
        if (!(operation[0] == 'q' || operation[0] == 'Q')) {
            cin >> character;
        }

        found = find(arrList.begin(), arrList.end(), character[0]);

        if (operation[0] == 'a' || operation[0] == 'A') {
            if (found == arrList.end()) { //TODO WHAT DOES THIS MEAN
                arrList.push_back(character[0]);
            }
            else {
                cout << "Duplicate!" << endl;
            }
        }
        else if (operation[0] == 'r' || operation[0] != 'R') {
            if (arrList.empty()) {
                cout << "Empty!" << endl;
            }
            else if (found != arrList.end()) {
                index = found - arrList.begin();
                arrList.erase(arrList.begin() + index);
            }
            else {
                cout << "Not Present!" << endl;
            }
        }
        else if (!(operation[0] == 'q' || operation[0] == 'Q')) {
            cout << "Try Again!" << endl;
        }

        cout << "Your List: ";
        for (int i = 0; i < arrList.size(); i++) {
            cout << arrList[i] << " ";
        }
        cout << endl;
    } while (!(operation[0] == 'q' || operation[0] == 'Q'));
}