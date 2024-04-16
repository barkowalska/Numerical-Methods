#include"Derivative.h"

namespace DE
{
	long double** eulerMethod(long double(*f)(long double, long double), long double x0, long double fx0, long double x1, long double h, int &n)
	{
		n = (x1 - x0) / h;

		long double** result = new long double* [n+1];
		for (int i = 0; i < n+1; i++)
			result[i] = new long double[2];

		result[0][0] = x0;
		result[0][1] = fx0;
		for (int i = 1; i <= n; i++)
		{
			result[i][0] = result[i-1][0] + h;
			result[i][1] = result[i-1][1] + h * f(result[i-1][0], result[i-1][1]);
		}

		return result;
	}

	long double** heunMethod(long double(*f)(long double, long double), long double x0, long double fx0, long double x1, long double h, int &n)
	{
		n = (x1 - x0) / h;

		long double** result = new long double* [n+1];
		for (int i = 0; i <= n; i++)
			result[i] = new long double[2];

		result[0][0] = x0;
		result[0][1] = fx0;
		long double fprev = 0;
		for (int i = 1; i < n+1; i++)
		{
			fprev = f(result[i - 1][0], result[i - 1][1]);
			result[i][0] = result[i - 1][0] + h;
			result[i][1] = result[i - 1][1] + 0.5*h*( fprev + f( result[i-1][0]+h, result[i - 1][1] + h * fprev));
		}

		return result;
	}

	long double** rungKuttyMethod4(long double(*f)(long double, long double), long double x0, long double fx0, long double x1, long double h, int& n)
	{
		n = (x1 - x0) / h;

		long double** result = new long double* [n+1];
		for (int i = 0; i < n+1; i++)
			result[i] = new long double[2];

		result[0][0] = x0;
		result[0][1] = fx0;

		long double k1 = 0;
		long double k2 = 0;
		long double k3 = 0;
		long double k4 = 0;
		long double fprev = 0;

		for (int i = 1; i <= n; i++)
		{
			k1 = f(result[i - 1][0], result[i - 1][1]);
			k2 = f(result[i - 1][0] + 0.5*h, result[i - 1][1] + 0.5*k1);
			k3 = f(result[i - 1][0] + 0.5*h, result[i - 1][1] + 0.5*k2);
			k4 = f(result[i - 1][0] + h, result[i - 1][1] + k3);

			result[i][0] = result[i-1][0] + h;
			result[i][1] = result[i - 1][1] + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
		}

		return result;
	}
}