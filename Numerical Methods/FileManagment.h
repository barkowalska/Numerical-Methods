#pragma once
#include<string>
#include<fstream>
#include"Structures.h"
void readPoints(const std::string& filename, Point*& dest, int& num);
void readMatrix(long double** &matrix, int& rows, int& columns, std::string fileName);
void readVector(long double* &vector, int& length, std::string fileName);
void saveVectorToFile(long double* vector, int length, std::string fileName, void(*output)(std::ofstream&, long double, unsigned int));

void resultVectorOutput(std::ofstream& file, long double x0, unsigned int n);