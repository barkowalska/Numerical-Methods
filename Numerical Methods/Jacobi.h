#pragma once
#include<exception>
#include<iostream>
long double* jacobi(long double** coefMatrix, long double* freeVar, const int n, const long double stop, long double* initialGuess = nullptr, const int MAX_ITERATION = 1000);