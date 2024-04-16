#include"Interpolation.h"
long double* newtonInterpolation(const Point* nodes, const int num, long double**& matrix, const int prevNum)
{
	// Tworzenie macierzy 2D
	if (matrix == nullptr)
	{
		matrix = new long double* [num];
		for (int i = 0; i < num; i++)
			matrix[i] = new long double[num + 1];

		// Wype³nianie pierwszej kolumny wartoœciami f(x)
		for (int i = 0; i < num; i++)
			matrix[i][0] = nodes[i]._y;
	}
	else
	{
		long double** newMatrix = new long double* [num];
		for (int i = 0; i < prevNum; i++)
			newMatrix[i] = matrix[i];
		long double** toDelete = matrix;
		matrix = newMatrix;
		delete[] toDelete;
	}
	// Obliczanie elementów macierzy
	for (int i = prevNum + 1; i < num; i++)
	{
		for (int j = i; j < num; j++)
		{
			matrix[j][i] = (matrix[j][i - 1] - matrix[j - 1][i - 1]) / (nodes[j]._x - nodes[j - i]._x);
		}
	}

	// Odczytywanie wartoœci z przek¹tnej

	long double* coef = new long double[num];
	for (int i = 0; i < num; i++)
		coef[i] = matrix[i][i];

	return coef;
}

long double newtonPolynomial(const Point* nodes, const int numNodes, const long double* coef, const long double X)
{
	long double wn = coef[numNodes - 1];
	long double wi = 0;
	for (int i = numNodes - 2; i >= 0; i--)
	{
		wi = wn * (X - nodes[i]._x) + coef[i];
		wn = wi;
	}
	return wi;
}

long double lagrangePolynomial(const Point* nodes, const int numNode, const long double X)
{
	// Zabezpieczenie
	if (numNode <= 0) return INFINITY;
	//	Wynik
	long double result = 0;
	//	Zmienne pomocnicze
	long double numerator = 1;
	long double denominator = 1;

	//	Obliczenie wartoœci wielomianu interpolacyjnego na podstawie wzoru
	for (int i = 0; i < numNode; i++)
	{
		numerator = 1;
		denominator = 1;
		for (int j = 0; j < numNode; j++)
		{
			if (j == i) continue;
			numerator *= (X - nodes[j]._x);
			denominator *= (nodes[i]._x - nodes[j]._x);
		}

		result += (numerator / denominator) * nodes[i]._y;
	}
	return result;
}

long double* aproximation(Point* nodes, const int num)
{
	long double a1, a0;

	/// a1

	//	Inicjalizacja zmiennych pomocniczych, nazwy odpowiadaj¹
	//	elementom wzoru
	long double nxiyi, xi, yi, nxi2, xi2;
	nxiyi = xi = yi = nxi2 = xi2 = 0;

	//	Obliczanie sum
	for (int i = 0; i < num; i++)
	{
		nxiyi += nodes[i]._x * nodes[i]._y;
		xi += nodes[i]._x;
		yi += nodes[i]._y;
		nxi2 += nodes[i]._x * nodes[i]._x;
	}

	//	Przemno¿enie odpowiednich sum przez liczbê wêz³ów
	nxiyi *= num;
	nxi2 = nxi2 * num;

	//	Obliczenie sumy podniesionej do kwadratu
	xi2 = xi * xi;

	// Obliczenie wspó³czynnika kierunkowego
	a1 = (nxiyi - xi * yi) / (nxi2 - xi2);

	// Obliczanie brakuj¹cych sum - dzielenie wczeœniej wyliczonych
	// przez liczbê wêz³ów, przez któr¹ to zosta³y wymno¿one

	long double yixi2 = yi * (nxi2 / num);
	long double xixiyi = xi * (nxiyi / num);

	// Obliczenie wyrazu wolnego
	a0 = (yixi2 - xixiyi) / (nxi2 - xi2);

	// results

	long double* res = new long double[2];
	res[0] = a0;
	res[1] = a1;
	return res;

}

long double Rcoef(const Point* nodes, const int num)
{
	// Inicjalizacja zmiennych pomocniczych
	long double nxiyi, xi, yi, nxixi, xi2, nyiyi, yi2;
	nxiyi = xi = yi = nxixi = xi2 = nyiyi = yi2 = 0;

	// Obliczenie sum
	for (int i = 0; i < num; i++)
	{
		nxiyi += nodes[i]._x * nodes[i]._y;
		xi += nodes[i]._x;
		yi += nodes[i]._y;
		nxixi += nodes[i]._x * nodes[i]._x;
		nyiyi += nodes[i]._y * nodes[i]._y;
	}
	// Przemno¿enie odpowiednich sum przez liczbê wêz³ów
	nxiyi *= num;
	nxixi *= num;
	nyiyi *= num;

	// Podniesienie odpowiednich sum do kwadratu
	xi2 = xi * xi;
	yi2 = yi * yi;

	// Obliczenie wspó³czynnika korelacji
	return (nxiyi - xi * yi) / (sqrt(nxixi - xi2) * sqrt(nyiyi - yi2));

}
