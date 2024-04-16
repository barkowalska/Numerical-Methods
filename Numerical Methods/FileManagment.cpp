#include"FileManagment.h"
void readPoints(const std::string& filename, Point*& dest, int& num)
{
	dest = nullptr;
	num = 0;

	std::ifstream file;
	file.open(filename.c_str());
	if (file.is_open() == false)
	{
		return;
	}

	file >> num;
	dest = new Point[num];
	int itr = 0;

	while (file.eof() == false)
	{
		file >> dest[itr]._x;
		file >> dest[itr]._y;
		itr++;
	}
	file.close();
}

void readMatrix(long double** &matrix, int& rows, int& columns, std::string fileName)
{
	std::ifstream file;
	file.open(fileName.c_str());
	if (file.is_open() == false)
		return;
	file >> rows;
	file >> columns;
	matrix = new long double* [rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new long double[columns];
	for(int r = 0; r < rows; r++)
		for (int c = 0; c < columns; c++)
		{
			file >> matrix[r][c];
			matrix[r][c] /= 100;
		}
	file.close();
}

void readVector(long double* &vector, int& length, std::string fileName)
{
	std::ifstream file;
	file.open(fileName.c_str());
	if (file.is_open() == false)
		return;

	file >> length;

	vector = new long double[length];
	for (int i = 0; i < length; i++)
		file >> vector[i];
	file.close();
}

void saveVectorToFile(long double* vector, int length, std::string fileName, void (*output)(std::ofstream&, long double, unsigned int) )
{
	std::ofstream file;
	file.open(fileName);
	for (int i = 0; i < length; i++)
		output(file, vector[i], i);
	file.close();
}

void resultVectorOutput(std::ofstream& file, long double x0, unsigned int n)
{
	file << "X" << n << ": " << x0 << std::endl;
}