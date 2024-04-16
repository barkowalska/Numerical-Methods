#include"Another.h"
long double diff(const Point* nodes, const int lb, const int k)
{
	long double result = 0;
	long double d = 1;
	for (int i = lb; i < lb + k; i++)
	{
		d = 1;
		for (int j = lb; j < lb + k; j++)
		{
			if (j == i) continue;
			d = d * (nodes[i]._x - nodes[j]._x);
		}

		result += nodes[i]._y / d;
	}
	return result;
}

std::string numberToString(long double number)
{
	std::string result = "";
	char c;
	while (number / 10 < 1)
		number /= 10;

	long double pos = 1;
	int r = 0;
	while (pos != 0)
	{

	}
	return result;
}


