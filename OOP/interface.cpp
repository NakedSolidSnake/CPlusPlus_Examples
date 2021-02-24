//============================================================================
// Name        : 00-Template.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Interface{
	virtual void setValue(int value) = 0;
	virtual int getValue(void) const = 0;
};

class Point : public Interface{
private:
	int value;

public:
	void setValue(int value)
	{
		this->value = value;
	}
	int getValue(void) const{
		return this->value;
	}

	~Point(){

	}
};

int main() {

	Point point;

	point.setValue(10);

	cout << "Point Value : " << point.getValue() << endl;

	return 0;
}
