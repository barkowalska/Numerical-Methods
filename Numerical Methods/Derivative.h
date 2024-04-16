#pragma once
#include"Line.h"
#include<cmath>
long double firstDervValue(long double (*f)(long double), const long double x, const long double dx = 10e-6);
long double* firstDerv(long double (*f)(long double), const long double lb, const long double ub, const unsigned int n = 1000, 
	const long double dx = 10e-6);