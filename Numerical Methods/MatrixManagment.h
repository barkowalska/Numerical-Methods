#pragma once
#include"Exceptions.h"
template<typename T>
void allocateMatrix(T** &matrix, const int rowNum, const int columnNum) 
{
	if (matrix != nullptr)
	{
		throw NotNullPointer();
	}
	matrix = new T * [rowNum];
	for (int i = 0; i < columnNum; i++)
		matrix[i] = new T[columnNum];
}

template<typename T>
void freeMatrix(T**& matrix, const int rowNum, const int columnNum)
{
	if (matrix == nullptr) return;
	for (int i = 0; i < rowNum; i++)
		if (matrix[i] != nullptr)
			delete[] matrix[i];
	delete[] matrix;
}