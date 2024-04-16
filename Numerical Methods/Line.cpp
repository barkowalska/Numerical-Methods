#pragma once
#include"Line.h"

long double* lineEquation(long double x0, long double y0, long double x1, long double y1)
{
	long double* result = new long double[2];
	result[0] = (y1 - y0) / (x1 - x0);
	result[1] = y1 - result[0] * x1;

	return result;
}