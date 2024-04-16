#include"Optimization.h"
long double* goldenRatioOpt(long double a, long double b, long double (*f)(long double), long double eps)
{
	// Golden ratio
	const long double REV_GR = 0.61803398;

	long double x0, x1;
	while (b - a > eps)
	{
		x0 = b - (b - a) * REV_GR;
		x1 = a + (b - a) * REV_GR;
		if (f(x0) < f(x1))
		{
			b = x1;
		}
		else
		{
			a = x0;
		}
	}
	long double* x1x2 = new long double[2];
	x1x2[0] = x0;
	x1x2[1] = x1;
	return x1x2;
}

long double* expansion(long double a, long double b, long double (*f)(long double))
{

}