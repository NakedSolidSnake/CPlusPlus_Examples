//============================================================================
// Name        : 00-Template.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void swap(int& x, int& y);

int main() {

	int a = 100;
	int b = 200;

	cout << "Before swap, value of a: " << a << endl;
	cout << "Before swap, value of b: " << b << endl;

	swap(a, b);

	cout << "After swap, value of a: " << a << endl;
	cout << "After swap, value of b: " << b << endl;


	return 0;
}

void swap(int& x, int& y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;
}
