#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

class Date {
public:
	Date(int num) { date = num; };
	void printDate() { cout << date << endl; };
	void setDate(int num) { date = num * 2; };
private:
	int date = 0;
};

int main() {
	Date one(12);
	one.setDate(5);
	one.printDate();

	Date two(20);
	two.printDate();
}