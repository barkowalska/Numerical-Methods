#include<array>

// Funkcje kszta³tu //
long double shapeFunction_1(const long double xi, const long double eta)
{
	return 0.25 * (1 - xi) * (1 - eta);
}

long double shapeFunction_2(const long double xi, const long double eta)
{
	return 0.25 * (1 + xi) * (1 - eta);
}

long double shapeFunction_3(const long double xi, const long double eta)
{
	return 0.25 * (1 + xi) * (1 + eta);
}

long double shapeFunction_4(const long double xi, const long double eta) 
{
	return 0.25 * (1 - xi) * (1 + eta);
}

// Tablica z funkcjami kszta³tu //
std::array<long double(*)(const long double, const long double), 4> shapeFunctons =
{ shapeFunction_1 , shapeFunction_2, shapeFunction_3, shapeFunction_4 };

// Funkcja przekszta³caj¹ca //
long double* reTransform(long double ksi, long double eta, const long double* x, const long double* y)
{
	long double* result = new long double[2];
	result[0] = 0; result[1] = 0;
	for (int i = 0; i < 4; i++)
		result[0] += shapeFunctons[i](ksi, eta) * x[i];
	for (int i = 0; i < 4; i++)
		result[1] += shapeFunctons[i](ksi, eta) * y[i];

	return result;
}

// Pochodne funkcji kszta³tu po Xi //

long double dervXi_shapeFunction_1(const long double eta)
{
	return -0.25 * (1 - eta);
}
long double dervXi_shapeFunction_2(const long double eta)
{
	return 0.25 * (1 - eta);
}
long double dervXi_shapeFunction_3(const long double eta)
{
	return 0.25 * (1 + eta);
}
long double dervXi_shapeFunction_4(const long double eta)
{
	return -0.25 * (1 + eta);
}

std::array<long double(*)(const long double), 4> dervXi_shapeFunctons =
{ dervXi_shapeFunction_1 , dervXi_shapeFunction_2, dervXi_shapeFunction_3, dervXi_shapeFunction_4 };


// Pochodne funkcji kszta³tu po Eta //

long double dervEta_shapeFunction_1(const long double xi)
{
	return -0.25 * (1 - xi);
}
long double dervEta_shapeFunction_2(const long double xi)
{
	return -0.25 * (1 + xi);
}
long double dervEta_shapeFunction_3(const long double xi)
{
	return 0.25 * (1 + xi);
}
long double dervEta_shapeFunction_4(const long double xi)
{
	return 0.25 * (1 - xi);
}

std::array<long double(*)(const long double), 4> dervEta_shapeFunctons = 
{ dervEta_shapeFunction_1 , dervEta_shapeFunction_2, dervEta_shapeFunction_3, dervEta_shapeFunction_4 };


// Funkcja obliczaj¹ca pochodn¹ x lub y po eta //


long double derv_Eta(const long double* x, const long double xi)
{
	long double result = 0;
	for (int i = 0; i < 4; i++)
		result += (dervEta_shapeFunctons[i])(xi) * (x[i]);
	return result;
}

// Funkcja obliczaj¹ca pochodn¹ x lub y po xi //

long double derv_Xi(const long double* x, const long double eta)
{
	long double result = 0;
	for (int i = 0; i < 4; i++)
		result += (dervXi_shapeFunctons[i])(eta) * (x[i]);
	return result;
}

// Funkcja obliczaj¹ca Jacobian

long double Jacobian(const long double xi, const long double eta, const long double* x, const long double* y)
{
	return (derv_Xi(x, eta) * derv_Eta(y, xi) - derv_Eta(x, xi) * derv_Xi(y, eta));
}



long double Gauss2DQuadrature(long double (*f)(long double, long double), const long double* x, const long double* y, long double* xi, 
	long double* eta, long double* wxi, long double* weta)
 {
	long double result = 0;
	long double* t = nullptr;
	for (int j = 0; j < 2; j++)
		for (int i = 0; i < 2; i++)
		{
			// Przekszta³cenie wêz³a do "standardowego" uk³adu wspó³rzêdnych ( span{(1,0),(0,1)} )
			t = reTransform(xi[j], eta[i], x, y);
			result +=wxi[j] * weta[i]* f(t[0], t[1]) * Jacobian(xi[j], eta[i], x, y);
			delete t;
		}
	return result;
}

