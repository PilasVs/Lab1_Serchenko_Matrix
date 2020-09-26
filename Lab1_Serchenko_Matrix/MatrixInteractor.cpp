#include "MatrixInteractor.h"
#include <iostream>

void MatrixInteractor::RunProgramm()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Функционал:";
	std::cout << "1 - Ввести имя файла с матрицами";
	std::cout << "2 - Создать и использовать новую матрицу";
	std::cout << "Работа с матрицами из файла:";
	std::cout << "3 - Вычисть";
	std::cout << "4 - Сложить";
	std::cout << "5 - Транспонировать";
}
