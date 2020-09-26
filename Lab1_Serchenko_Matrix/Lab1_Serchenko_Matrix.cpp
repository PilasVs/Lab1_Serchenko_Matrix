#include "Matrix.h"
#include <vld.h>
//#include <algorithm>
#include <iostream>

const int rows = 3;
const int cols = 3;

void PrintMatrix(const Matrix& m)
{
	for (int i = 0; i < m.GetRows(); i++)
	{
		for (int j = 0; j < m.GetCols(); j++)
		{
			std::cout << m[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

Matrix matrix1(rows, cols);
Matrix matrix2(rows, cols);

int main()
{
	Matrix matrix3 = matrix1 + matrix2;
	PrintMatrix(matrix3);
	Matrix matrix4 = matrix1 - matrix2;
	PrintMatrix(matrix4);
	return 0;
}