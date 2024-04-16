#pragma once
long double* goldenRatioOpt(long double a, long double b, long double (*f)(long double), long double eps);
long double* expansion(long double a, long double b, long double (*f)(long double), long double d, long double alpha);