#pragma once
#include"Derivative.h"

//SPRAWDØ JAK ZWI KSZY∆ DOK£ADNOå∆ (2DX,3DX ...) - SPRAWDè SZEREG TAYLORA!
long double firstDervValue(long double (*f)(long double), const long double x, const long double dx)
{
	return (-f(x+2*dx) + 8*f(x + dx) - 8*f(x - dx) + f(x-2*dx) ) / (12 * dx);
}

long double* firstDerv(long double (*f)(long double), const long double lb, const long double ub, const unsigned int n, 
	const long double dx)
{
	long double* result = new long double[n];
	long double step = abs(ub - lb) / n;
	long double x = lb + dx;
	for (int i = 0; i < n; i++)
	{
		result[i] = firstDervValue(f, x, dx);
		x += step;
	}

	return result;
}