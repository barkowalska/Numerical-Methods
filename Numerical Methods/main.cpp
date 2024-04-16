#include<iostream>
#include<fstream>
#include<cmath>
#include<ctime>
#include<stdlib.h>
#include"Gaus2D.h"
#include"GaussElimination.h"
#include"Structures.h"
#include"FileManagment.h"
#include"Quadratures.h"
#include"Root.h"
#include"Interpolation.h"
#include"DerivativeEquation.h"
#include"Jacobi.h"


#define PI 3.14159265359

long double function(long double x);
long double function2D(long double x, long double y);

int& createRef(std::unique_ptr<int>& ptr)
{
	return *ptr;
}

void freePointer(int& ref)
{
	int* ptr = &ref;
	delete ptr;
}

int main()
{
	return 0;
}


long double function(long double x)
{
	return x*x*x + x*x -2;
}

long double function2D(long double x, long double y)
{
	return x*x - sin(x) + y;
}

