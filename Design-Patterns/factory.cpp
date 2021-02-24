/*
 * main.cpp
 *
 *  Created on: 14 de out de 2018
 *      Author: solid
 */



#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SportsBall{
public:
	string type;
	vector<string>materialsUsed;
	float radius;
	string comments;
	string make;
	string modelName;
};


class BallFactory{
public:
	virtual SportsBall* createBall() = 0;
};

class BasketBallMaker : public BallFactory{
public:
	SportsBall *createBall()
	{
		SportsBall *b = new SportsBall();
		b->type = "Basketball";
		b->materialsUsed.reserve(3);
		b->materialsUsed.push_back("rubber");
		b->materialsUsed.push_back("fiber");
		b->materialsUsed.push_back("synthetic composite");
		b->radius = 4.8f;
		b->make = "Spalding";
		b->modelName = "Series Basketball";
		return b;
	}
};


class BaseballMaker : public BallFactory{
	SportsBall *createBall()
	{
		SportsBall *b = new SportsBall();
		b->type = "Baseball";
		b->materialsUsed.reserve(6);
		b->materialsUsed.push_back("cork");
		b->materialsUsed.push_back("wool");
		b->materialsUsed.push_back("poly/cotton");
		b->materialsUsed.push_back("cowhide");
		b->materialsUsed.push_back("yarn");
		b->materialsUsed.push_back("composite rubber");
		b->radius = 1.45f;
		b->make = "Rawlings";
		b->modelName = "MLB Official Baseball";
		return b;
	}
};

class VoleyballMaker : public BallFactory{
	SportsBall *createBall()
	{
		SportsBall *b = new SportsBall();
		b->type = "VoleyBall";
		b->materialsUsed.reserve(2);
		b->materialsUsed.push_back("leather");
		b->materialsUsed.push_back("rubber");
		b->radius = 65.0f;
		b->make = "Misaka";
		b->modelName = "Voleyball series";
		return b;
	}
};

int main(int argc, char **argv) {
	BallFactory *f1 = new BasketBallMaker();
	BallFactory *f2 = new BaseballMaker();
	BallFactory *f3 = new VoleyballMaker();

	SportsBall *bb1 = f1->createBall();
	SportsBall *bb2 = f2->createBall();
	SportsBall *bb3 = f3->createBall();

	cout << bb1->type << endl;
	cout << bb2->type << endl;
	cout << bb3->type << endl;

	return 0;
}

