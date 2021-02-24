//============================================================================
// Name        : 00-Template.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {

	const char *filename = "afile.txt";
	char data[100];

	ofstream outfile;
	outfile.open(filename);

	cout << "Writing to the file" << endl;
	cout << "Enter your name: ";
	cin.getline(data, 100);

	outfile << data << endl;

	cout << "Enter your age: ";
	cin >> data;
	cin.ignore();

	outfile << data << endl;

	outfile.close();

	ifstream infile;
	infile.open(filename);

	cout << "Reading from the file" << endl;
	infile >> data;

	cout << data << endl;

	infile >> data;
	cout << data << endl;

	infile.close();

	return 0;
}
