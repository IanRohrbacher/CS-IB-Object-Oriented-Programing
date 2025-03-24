#include "list.hpp"
#include <iostream>

using std::cout; using std::endl;

List::List() {
	size_ = 0;
	list_ = new double[size_];
}// void constructor

int List::check(double num) {
	for (int i = 0; i < size_; i++) {
		if (list_[i] == num) {
			return i;
		}
	}
	return -1;
}// returns index of element containg "number" or -1 if none

void List::addNumber(double num) {
	if (check(num) == -1) {
		double* temp = new double[size_ + 1];

		for (int i = 0; i < size_; i++) {
			temp[i] = list_[i];
		}
		temp[size_] = num;

		delete[] list_;
		list_ = temp;

		size_++;
	}
	else {
		cout << "Duplicate!" << endl;
	}

}// adds number to the List

void List::removeNumber(double num) {
	int index = check(num);

	if (index != -1) {
		double* temp = new double[size_ - 1];

		for (int i = 0; i < index; i++) {
			temp[i] = list_[i];
		}
		for (int i = index + 1; i < size_; i++) {
			temp[i - 1] = list_[i];
		}

		delete[] list_;
		list_ = temp;
		size_--;
	}
	else {
		cout << "Not Present!" << endl;
	}
}// deletes the number from the List

void List::output() {
	for (int i = 0; i < size_; i++) {
		cout << list_[i] << " ";
	}
	cout << endl;
}// prints the values of the List


 // big three
List::List(const List& copy) {
	size_ = copy.size();
	list_ = new double[size_];
	for (int i = 0; i < size_; i++) {
		list_[i] = copy.list_[i];
	}
}// copy constructor

List& List::operator= (const List& rhs) {
	if (this != &rhs) {
		this->size_ = rhs.size();
		delete[] list_;
		list_ = new double[size_];
		for (int i = 0; i < size_; i++) {
			list_[i] = rhs.list_[i];
		}
	}
	return *this;
}// overloaded assignment

List::~List() {
	delete[] list_;
	list_ = nullptr;
}// destructor