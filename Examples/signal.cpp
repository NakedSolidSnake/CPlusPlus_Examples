//============================================================================
// Name        : 00-Template.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <csignal>
#include <unistd.h>

#define ONE_SECOND 1000000

using namespace std;


void signalHandler(int signum)
{
	cout << "Interrupt signal (" << signum << ") received.\n";
}

int main() {
	int i = 0;
	signal(SIGINT, signalHandler);

	while(1)
	{
		cout << "Going to sleep..." << endl;
		usleep(ONE_SECOND);
		if(++i > 3)
		{
			raise(SIGINT);
			i = 0;
		}

	}

	return 0;
}
