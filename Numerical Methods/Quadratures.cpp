#include"Quadratures.h"
/*
*	Integrals
*/

double integralRect(long double (*f)(long double), const long double lb, const long double ub, const int nodesNum)
{
	const long double dx = abs(ub - lb) / nodesNum;
	long double result = 0;
	long double h = 0;
	for (long double x = lb; x <= ub; x += dx)
	{
		result += f(x + dx);
	}
	return result * dx;
}

double integralT(long double (*f)(long double), const long double lb, const long double ub, const int nodesNum)
{
	const long double dx = abs(ub - lb) / nodesNum;
	long double result = 0;
	for (long double x = lb; x <= ub; x += dx)
	{
		result += 0.5 * (f(x) + f(x + dx)) * dx;
	}
	return result;
}

double integralSimpson(long double (*f)(long double), const long double lb, const long double ub, const int nodes)
{
	const long double dx = (ub - lb) / nodes;
	long double result = 0;
	for (long double x = lb; x < ub; x += 2 * dx)
	{
		result += f(x) + 4 * f(x + dx) + f(x + 2 * dx);
	}
	result *= dx / 3;
	return result;
}

double integralMonteCarlo(long double (*f)(long double), const long double lb, const long double ub, const int n, int rn)
{
	const int rangeNum = n / rn;
	long double rangeWidth = abs(ub - lb) / rangeNum;
	long double fValuesSum = 0;

	for (long double x = lb; x < ub; x += rangeWidth)
	{
		srand(time(NULL));
		for (int i = 0; i < rn; i++)
		{
			fValuesSum += f((static_cast <long double> (std::rand()) / static_cast <long double> (RAND_MAX)) * rangeWidth + x);
		}
	}
	return (fValuesSum / n) * abs(ub - lb);
}