#include"Root.h"

long double rootFPN(long double (*f)(long double), const long double lb, const long double ub, const long double TOLLERANCE, const unsigned int MAX_ITERATION)
{
	long double result = INFINITY;
	long double* line = nullptr;
	long double leftB = lb;
	long double rightB = ub;
	long double fl = 0;
	long double fr = 0;

	unsigned int itr = 0;

	while (itr++ < MAX_ITERATION)
	{
		fl = f(leftB);
		fr = f(rightB);
		line = lineEquation(leftB, fl, rightB, fr);
		result = -1 * (line[1] / line[0]);
		if (f(result) < TOLLERANCE) break;
		if (f(result) * fl > 0) leftB = result;
		else rightB = result;
	}

	return result;
}

long double rootNR(long double (*f)(long double), const long double lb, const long double ub, const long double TOLLERANCE, const double MIN_RANGE)
{
	long double x0 = ub;
	long double x1 = ub;
	long double dx = 0;
	unsigned int itr = 0;
	while (abs(f(x0)) > TOLLERANCE)
	{
		x0 = x1;
		x1 = x0 - f(x0) / firstDervValue(f, x0);
		if (abs(x1 - x0) < MIN_RANGE) break;
	}
	return x0;
}

long double rootBisection(long double (*f)(long double), const long double lb, const long double ub, const long double TOLLERANCE, const double MIN_RANGE)
{

	long double result = INFINITY;
	long double a = lb;
	long double b = ub;
	long double fx0 = 0;

	while ((b - a) > MIN_RANGE)
	{
		fx0 = f((b + a) / 2.0);
		if (abs(fx0) < TOLLERANCE)
		{
			result = fx0;
			break;
		}
		else if (fx0 * f(a) < 0) b = (a + b) / 2.0;
		else a = (a + b) / 2;
	}

	return result;
}