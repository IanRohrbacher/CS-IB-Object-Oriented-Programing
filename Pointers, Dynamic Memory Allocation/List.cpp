#include "List.hpp"
#include <iostream>

using std::cout; using std::endl;

void output(double* colPtr, int size) {
	for (int i = 0; i < size; i++) {
		cout << colPtr[i] << " ";
	}
	cout << endl;
}

int check(double* colPtr, double number, int size) {
	for (int i = 0; i < size; i++) {
		if (colPtr[i] == number) {
			return i;
		}
	}
	return -1;
}

void addNumber(double*& colPtr, double number, int& size) {
	if (check(colPtr, number, size) == -1) {
		double* temp = new double[size + 1];

		for (int i = 0; i < size; i++) {
			temp[i] = colPtr[i];
		}
		temp[size] = number;

		delete[] colPtr;
		colPtr = temp;

		size++;
	}
	else {
		cout << "Duplicate!" << endl;
	}
}

void removeNumber(double*& colPtr, double number, int& size) {
	int index = check(colPtr, number, size);

	if (index != -1) {
		double* temp = new double[size - 1];

		for (int i = 0; i < index; i++) {
			temp[i] = colPtr[i];
		}
		for (int i = index + 1; i < size; i++) {
			temp[i - 1] = colPtr[i];
		}

		delete[] colPtr;
		colPtr = temp;

		size--;
	}
	else {
		cout << "Not Present!" << endl;
	}
}