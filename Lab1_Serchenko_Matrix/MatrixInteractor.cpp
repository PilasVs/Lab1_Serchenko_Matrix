#include "MatrixInteractor.h"
#include <iostream>
#define Check(No) No >= _matrixVector.size() || No < 0
#define ScanCheck3(first, second, result) \
	std::cout << "Введите номер первой матрицы" << std::endl;\
	std::cin >> first;\
	std::cout << "Введите номер второй матрицы" << std::endl;\
	std::cin >> second;\
	std::cout << "Введите номер результирующей матрицы" << std::endl;\
	std::cin >> result;\
	if(Check(first) || Check(second) || Check(result))throw std::out_of_range("Wrong Parameters");
#define ScanCheck1(No) std::cout << "Введите номер матрицы" << std::endl;\
	std::cin >> No;\
	if(Check(No)) throw std::out_of_range("Wrong Parameters");\

void Run()
{
	setlocale(LC_ALL, "Russian");
	while (RunMainMenu() != 0);
}

int RunMainMenu()
{
	system("cls");
	std::cout << "Функционал:" << std::endl;
	std::cout << "1 - Файловый ввод матрицы" << std::endl;
	std::cout << "2 - Консольный ввод матрицы" << std::endl;
	std::cout << "0 - Выход" << std::endl;
	MatrixInteractor MI;
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		while (MI.RunFileMenu() != 0);
		break;
	case 2:
		while (MI.RunConsoleMenu() != 0);
		break;
	default:
		return 0;
	}
	return 1;
}

int MatrixInteractor::RunFileMenu()
{
	std::cout << "1 - Ввести имя файла и прочитать содержимое" << std::endl;
	std::cout << "2 - Произвести сложение" << std::endl;
	std::cout << "3 - Произвести вычитание" << std::endl;
	std::cout << "4 - Произвести умножение" << std::endl;
	std::cout << "5 - Произести транспонирование" << std::endl;
	std::cout << "6 - Вывести det" << std::endl;
	std::cout << "7 - Создать новую матрицу" << std::endl;
	std::cout << "8 - Вывести матрицу на экран" << std::endl;
	std::cout << "9 - Удалить матрицу" << std::endl;
	std::cout << "0 - Выйти и вывести данные" << std::endl;
	int choice;
	std::cin >> choice;
	if (!_file.is_open() && choice != 1)
	{
		throw std::logic_error("Имя файла не задано");
	}
	switch (choice)
	{
	case 1:
	{
		if (_file.is_open())
		{
			this->~MatrixInteractor();
		}
		std::cout << "Имя файла:" << std::endl;
		std::cin >> _fileName;
		_file.open(_fileName, std::ios_base::in);
		if (!_file.is_open())
		{
			throw std::invalid_argument("Неверное имя файла");
		}
		unsigned int quantity;
		_file >> quantity;
		for (unsigned int count = 0; count < quantity; count++)
		{
			int rows, cols;
			_file >> rows >> cols;
			_matrixVector.push_back(Matrix::FactoryMatrix(rows, cols));
			for (int i = 0; i < rows; i++)
			{
				double* row = (*_matrixVector.back())[i];   //Указатель на очередной ряд
				for (int j = 0; j < cols;
					j++)
				{
					_file >> row[j];
				}
			}
		}
		break;
	}
	case 2:
	{
		MatrixSum();
		break;
	}
	case 3:
	{
		MatrixSub();
		break;
	}
	case 4:
	{
		MatrixMul();
		break;
	}
	case 5:
	{
		MatrixTran();
		break;
	}
	case 6:
	{
		MatrixDet();
		break;
	}
	case 7:
	{
		Expand();
		break;
	}
	case 8:
	{
		MatrixPrint();
		break;
	}
	case 9:
	{
		MatrixErase();
		break;
	}
	case 0:
	{
		std::cout << "Введите имя файла приёмника" << std::endl;
		std::cin >> _fileName;
		_file.close();
		_file.open(_fileName, std::ios_base::trunc | std::ios_base::out);
		if (!_file.is_open())
		{
			throw std::invalid_argument("Неверное имя файла");
		}
		_file << _matrixVector.size() << std::endl;
		for (auto elem : _matrixVector)
		{
			_file << *(elem);
		}
		return 0;
	}
	}
	return 1;
}

int MatrixInteractor::RunConsoleMenu()
{
	std::cout << "1 - Создать новую матрицу" << std::endl;
	std::cout << "2 - Произвести сложение " << std::endl;
	std::cout << "3 - Произвести вычитание" << std::endl;
	std::cout << "4 - Произвести умножение" << std::endl;
	std::cout << "5 - Произести транспонирование" << std::endl;
	std::cout << "6 - Вывести det" << std::endl;
	std::cout << "7 - Вывести матрицу на экран" << std::endl;
	std::cout << "8 - Удалить матрицу" << std::endl;
	std::cout << "0 - Выйти" << std::endl;
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
	{
		Expand();
		break;
	}
	case 2:
	{
		MatrixSum();
		break;
	}
	case 3:
	{
		MatrixSub();
		break;
	}
	case 4:
	{
		MatrixMul();
		break;
	}
	case 5:
	{
		MatrixTran();
		break;
	}
	case 6:
	{
		MatrixDet();
		break;
	}
	case 7:
	{
		MatrixPrint();
		break;
	}
	case 8:
	{
		MatrixErase();
		break;
	}
	case 0:
	{
		return 0;
	}
	}
	return 1;
}

void MatrixInteractor::Expand()
{
	int rows, cols;
	std::cout << "Введите количество рядов" << std::endl;
	std::cin >> rows;
	std::cout << "Введите количество колонн" << std::endl;
	std::cin >> cols;
	_matrixVector.push_back(Matrix::FactoryMatrix(rows, cols));
	std::cout << "Введите матрицу " << rows << " на " << cols << std::endl;
	for (int i = 0; i < rows; i++)
	{
		double* row = (*_matrixVector.back())[i];   //Указатель на очередной ряд
		for (int j = 0; j < cols; j++)
		{
			std::cin >> row[j];
		}
	}
}

void MatrixInteractor::MatrixSum()
{
	int first, second, result;
	ScanCheck3(first, second, result)
	*(_matrixVector[result]) = *(_matrixVector[first]) + *(_matrixVector[second]);
}

void MatrixInteractor::MatrixSub()
{
	int first, second, result;
	ScanCheck3(first, second, result)
	*(_matrixVector[result]) = *(_matrixVector[first]) - *(_matrixVector[second]);
}

void MatrixInteractor::MatrixMul()
{
	int first, second, result;
	ScanCheck3(first, second, result)
	*(_matrixVector[result]) = *(_matrixVector[first]) * *(_matrixVector[second]);
}

void MatrixInteractor::MatrixTran()
{
	int No;
	ScanCheck1(No)
	~(*(_matrixVector[No]));
}

void MatrixInteractor::MatrixDet()
{
	int No;
	ScanCheck1(No)
	std::cout << ((SquareMatrix)(*(_matrixVector[No]))).Det() << std::endl;
}

void MatrixInteractor::MatrixPrint()
{
	int No;
	ScanCheck1(No)
	std::cout << *(_matrixVector[No]);
}

void MatrixInteractor::MatrixErase()
{
	int No;
	ScanCheck1(No)
	std::vector<Matrix*>::iterator it = _matrixVector.begin() + No;
	delete (*it);
	_matrixVector.erase(it);
}

MatrixInteractor::~MatrixInteractor()
{
	for (auto elem : _matrixVector)
	{
		delete elem;
	}
}

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
	int i, j;
	int rows = m.GetRows(), cols = m.GetCols();

	os << rows << ' ' << cols << std::endl;
	if (rows == 0 || cols == 0)
	{
		return os;
	}
	for (i = 0; i < rows; i++)
	{
		double* row = m[i];
		for (j = 0; j < cols - 1; j++)
		{
			os << row[j] << ' ';
		}
		os << row[j] << std::endl;
	}
	return os;
}