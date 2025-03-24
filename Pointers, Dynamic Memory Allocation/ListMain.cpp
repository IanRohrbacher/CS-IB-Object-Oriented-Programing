#include "List.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {

    int size = 0;
    double* arr = new double[size];

    string operation;
    double number;

    while (true) {
        cout << "Enter Operation [a/r/q] and \'Number\': ";
        cin >> operation;
        if (operation[0] == 'q' || operation[0] == 'Q') {
            break;
        }
        cin >> number;

        if (operation[0] == 'a' || operation[0] == 'A') {
            addNumber(arr, number, size);
        }
        else if (operation[0] == 'r' || operation[0] == 'R') {
            removeNumber(arr, number, size);
        }
        else {
            cout << "Try Again!" << endl;
        }

        cout << "Your Numbers: ";
        output(arr, size);
    }

    delete[] arr;

}