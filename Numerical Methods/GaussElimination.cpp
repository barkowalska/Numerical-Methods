#include"GaussElimination.h"
long double* gausElimination(long double** A, long double* b, const int n)
{
	//Zmienna pomocnicza
	long double h = 0;

	//Przekszta�canie macierzy 
	for (int row = 0; row < n-1; row++)
	{
		for(int rowToCorrect = row+1; rowToCorrect < n; rowToCorrect++)
		{ 
			//Obliczanie wsp�czynnika potrzebnego do wyzerowania odpowiednich element�w w wierszach 
			//poni�ej wiersza row
		    h = A[rowToCorrect][row]/A[row][row];
			//Przekszta�cenie wektora wyraz�w wolnych
			b[rowToCorrect] -= h * b[row];
			//Przekszta�cenie wiersza - odj�cie od elemet�w wiersza rowtToCorrect element�w wiersza row 
			//pomno�onych przez odpowiednie wsp�czynniki
			for (int column = 0; column < n; column++)
			{
				A[rowToCorrect][column] = A[rowToCorrect][column] - h*A[row][column];
			}
		}
	}

	//Wektor wynikowy
	long double* results = new long double[n];
	//Obliczenie wynik�w
	for (int row = n - 1; row >= 0; row--)
	{
		results[row] = b[row];
		for (int column = n - 1; column > row ; column--)
		{
			results[row] -= A[row][column] * results[column];
		}
		results[row] /= A[row][row];
	}

	return results;
}