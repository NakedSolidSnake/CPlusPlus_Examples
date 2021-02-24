//============================================================================
// Name        : 00-Template.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class printData{
public:
	void print(int i)
	{
		cout << "Printing int: " << i << endl;
	}

	void print(double f)
	{
		cout << "Printing float: " << f << endl;
	}

	void print(char *c)
	{
		cout << "Printing character: " << c << endl;
	}

};

int main() {

	printData pd;

	pd.print(5);
	pd.print(500.263);
	pd.print((char *)"Hello C++\n");

	return 0;
}
