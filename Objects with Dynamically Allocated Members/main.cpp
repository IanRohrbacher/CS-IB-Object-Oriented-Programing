#include "list.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {

    string operation;
    List arrList;
    double number;

    do {
        cout << "Enter Operation [a/r/q] and \'Number\': ";
        cin >> operation;
        if (!(operation[0] == 'q' || operation[0] == 'Q')) {
            cin >> number;
        }

        if (operation[0] == 'a' || operation[0] == 'A') {
            arrList.addNumber(number);
        }
        else if (operation[0] == 'r' || operation[0] == 'R') {
            arrList.removeNumber(number);
        }
        else if (!(operation[0] == 'q' || operation[0] == 'Q')){
            cout << "Try Again!" << endl;
        }

        cout << "Your List: ";
        arrList.output();
    } while (!(operation[0] == 'q' || operation[0] == 'Q'));
}