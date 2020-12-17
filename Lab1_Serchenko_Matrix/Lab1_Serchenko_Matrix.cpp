#include "MatrixInteractor.h"
#include <vld.h>
#include <iostream>

int main()
{
	try {
		Run();
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		getchar(); getchar();
	}

	return 0;
}