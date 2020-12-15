#include "MatrixInteractor.h"
#include <vld.h>

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