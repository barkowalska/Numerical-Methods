#pragma once

namespace DE {

	long double** eulerMethod(long double(*f)(long double, long double), long double x0, long double fx0, long double x1, long double h, int&n);
	long double** heunMethod(long double(*f)(long double, long double), long double x0, long double fx0, long double x1, long double h, int&n);
	long double** rungKuttyMethod4(long double(*f)(long double, long double), long double x0, long double fx0, long double x1, long double h, int&n);
}