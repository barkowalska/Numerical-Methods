#pragma once
#include<cmath>
#include"Structures.h"

long double* newtonInterpolation(const Point* nodes, const int num, long double**& matrix, const int prevNum = 0);
long double newtonPolynomial(const Point* nodes, const int numNodes, const long double* coef, const long double X);
long double lagrangePolynomial(const Point* nodes, const int numNode, const long double X);
long double* aproximation(Point* nodes, const int num);
long double Rcoef(const Point* nodes, const int num);