#include "MatrixInteractor.h"
#include <vld.h>
#include <iostream>

int main()
{
	try {
		RunMainMenu();
	}
	catch (const char* s) {
		std::cout << s << std::endl;
	}
	getchar(); getchar();
	return 0;
}