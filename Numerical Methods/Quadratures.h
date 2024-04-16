#pragma once
#include<cmath>
#include<ctime>
double integralRect(long double (*f)(long double), const long double lb, const long double ub, const int nodes = 1000);
double integralT(long double (*f)(long double), const long double lb, const long double ub, const int nodes = 1000);
double integralSimpson(long double (*f)(long double), const long double lb, const long double ub, const int nodes = 1000);
double integralMonteCarlo(long double (*f)(long double), const long double lb, const long double ub, const int n = 100, int rn = 10);