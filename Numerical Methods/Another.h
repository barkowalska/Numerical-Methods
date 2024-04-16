#pragma once
#include<iostream>
#include"Structures.h"

template<typename T>
void print(T* arr, const int num)
{
	for (int i = 0; i < num; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

template<typename T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

long double diff(const Point* nodes, const int lb, const int ub);

std::string numberToString(long double number);
