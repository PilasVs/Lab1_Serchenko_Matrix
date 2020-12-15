#include "MatrixInteractor.h"
#include <vld.h>
#include <iostream>

void MP(Matrix& M)
{
	int i, j;
	for (i = 0; i < M.GetRows(); i++)
	{
		for (j = 0; j < M.GetCols() - 1; j++)
		{
			std::cout << M[i][j] << ' ';
		}
		std::cout << M[i][j] << std::endl;
	}
}

int main()
{
	try {
		Run();
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
	getchar(); getchar();

	return 0;
}