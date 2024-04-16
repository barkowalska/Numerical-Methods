#include<vector>
#include"Line.h"
#include"Derivative.h"

long double rootFPN(long double (*f)(long double), const long double lb, const long double ub, const long double TOLLERANCE = 10e-3, const unsigned int MAX_ITERATION = 1000);
long double rootNR(long double (*f)(long double), const long double lb, const long double ub, const long double TOLLERANCE = 10e-6, const double MIN_RANGE = 10.0e-6);
long double rootBisection(long double (*f)(long double), const long double lb, const long double ub, const long double TOLLERANCE = 10e-6, const double MIN_RANGE = 10.0e-6);