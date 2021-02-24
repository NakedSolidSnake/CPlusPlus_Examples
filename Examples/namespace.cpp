#include <iostream>

namespace Avg{
	float Calculate(float x, float y)
	{
		return x * y / 2.0f;
	}
}

float Calculate(float x, float y)
{
	return x * y;	
}


int main(int argc, char const *argv[])
{
	printf("%f\n", Avg::Calculate(10.0,10.0));
	printf("%f\n", Calculate(10.0,10.0));
	return 0;
}