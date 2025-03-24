#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::string;

int main() {
	srand(time(nullptr));
	int randNum;

	// get user input
	string input;
	cout << "Type: ";
	getline(cin, input);

	// if input is less then 40 do nothing
	if (input.size() < 40) {
		cout << input << endl;
	}
	// else if input to 90 if less then make it 90 else
	else if (input.size() < 90) {
	
		// if input has .,!?; add a space after unless its the end of the line
		for (int i = 0; i < input.size()-1; i++) {
			if (input[i] == '.' || input[i] == ',' || input[i] == '!' || input[i] == '?' || input[i] == ';') {
				input.insert(i+1, " ");
				i++;
			}
			//cout << input << endl;
		}
		// add random spaces where spaces are untill lenth == 90
		while (input.size() < 90) {
			randNum = rand();
			if (input[randNum % input.size()] == ' ') {
				input.insert(randNum % input.size(), " ");
			}
			//cout << input + ": Test" << endl;
		}
		cout << input << endl;
	}
	// else if lenth is greater then 90 throw error message
	else {
		cout << "Text Is Too Long! Must Be 90 Characters Or Less" << endl;
	}
}