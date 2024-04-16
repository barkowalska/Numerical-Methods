#include<array>

long double Gauss2DQuadrature(long double (*f)(long double, long double), const long double* x, const long double* y, long double* xi, 
	long double* eta, long double* wxi, long double* weta);