#include"Jacobi.h"
long double* jacobi(long double** coefMatrix, long double* freeVar, const int n, const long double stop, long double* initialGuess, const int MAX_ITERATION)
{
	for (int i = 0; i < n; i++)
		if (coefMatrix[i][i] == 0)
			return nullptr;

	long double* result = new long double[n];
	try
	{
		if (initialGuess != nullptr)
		{
			for (int i = 0; i < n; i++)
				result[i] = initialGuess[i];
		}
		else for (int i = 0; i < n; i++)
			result[i] = 0;

	}
	catch (std::exception e)
	{
		std::cerr << "READING INITIAL GUESS HAS FAILED";
		return nullptr;
	}

	long double iterationDiff = 0;
	long double* xnew = new long double[n];
	int iter = 0;
	do
	{
		iterationDiff = 0;
		for (int k = 0; k < n; k++)
		{
			xnew[k] = 0;
			for (int j = 0; j < n; j++)
			{
				if (j == k) continue;
				xnew[k] += coefMatrix[k][j]*result[j];
			}
			xnew[k] *= (-1);
			xnew[k] += freeVar[k];
			xnew[k] /= coefMatrix[k][k];

			if (iterationDiff < abs(xnew[k] - result[k]))
				iterationDiff = abs(xnew[k] - result[k]);
		}
		for (int i = 0; i < n; i++)
			result[i] = xnew[i];
		iter++;

	} while (iterationDiff > stop && iter < MAX_ITERATION);

	delete[] xnew;
	return result;
}