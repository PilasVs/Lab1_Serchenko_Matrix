#include "MatrixInteractor.h"
#include <iostream>
#include <string.h>

void Run()
{
	setlocale(LC_ALL, "Russian");
	while (RunMainMenu() != 0);
}

int RunMainMenu()
{
	system("cls");
	std::cout << "����������:" << std::endl;
	std::cout << "1 - �������� ���� �������" << std::endl;
	std::cout << "2 - ���������� ���� �������" << std::endl;
	std::cout << "0 - �����" << std::endl;
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
	std::cout << "1 - ������ ��� ����� � ��������� ����������" << std::endl;
	std::cout << "2 - ���������� ��������" << std::endl;
	std::cout << "3 - ���������� ���������" << std::endl;
	std::cout << "4 - ���������� ���������" << std::endl;
	std::cout << "5 - ��������� ����������������" << std::endl;
	std::cout << "6 - ������� det" << std::endl;
	std::cout << "7 - ������� ����� �������" << std::endl;
	std::cout << "8 - ������� ������� �� �����" << std::endl;
	std::cout << "9 - ������� �������" << std::endl;
	std::cout << "0 - ����� � ������� ������" << std::endl;
	int choice;
	std::cin >> choice;
	if (!_file.is_open() && choice != 1)
	{
		throw std::logic_error("��� ����� �� ������");
	}
	switch (choice)
	{
	case 1:
	{
		if (_file.is_open())
		{
			this->~MatrixInteractor();
		}
		std::cout << "��� �����:" << std::endl;
		std::cin >> _fileName;
		_file.open(_fileName, std::ios_base::in);
		if (!_file.is_open())
		{
			throw std::invalid_argument("�������� ��� �����");
		}
		unsigned int quantity;
		_file >> quantity;
		for (unsigned int count = 0; count < quantity; count++)
		{
			int rows, cols; char type;
			_file >> type >> rows >> cols;
			_matrixVector.push_back(FactoryMatrix(type, rows, cols));
			for (int i = 0; i < rows; i++)
			{
				double* row = (*_matrixVector.back())[i];   //��������� �� ��������� ���
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
		std::cout << "������� ��� ����� ��������" << std::endl;
		std::cin >> _fileName;
		_file.close();
		_file.open(_fileName, std::ios_base::trunc | std::ios_base::out);
		if (!_file.is_open())
		{
			throw std::invalid_argument("�������� ��� �����");
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
	std::cout << "1 - ������� ����� �������" << std::endl;
	std::cout << "2 - ���������� �������� " << std::endl;
	std::cout << "3 - ���������� ���������" << std::endl;
	std::cout << "4 - ���������� ���������" << std::endl;
	std::cout << "5 - ��������� ����������������" << std::endl;
	std::cout << "6 - ������� det" << std::endl;
	std::cout << "7 - ������� ������� �� �����" << std::endl;
	std::cout << "8 - ������� �������" << std::endl;
	std::cout << "0 - �����" << std::endl;
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
	int rows, cols; char type;
	std::cout << "������� ��� �������('M','S')" << std::endl;
	std::cin >> type;
	switch (type)
	{
	case 'M':
	{
		std::cout << "������� ���������� �����" << std::endl;
		std::cin >> rows;
		std::cout << "������� ���������� ������" << std::endl;
		std::cin >> cols;
		break;
	}
	case 'S':
	{
		std::cout << "������� �����������" << std::endl;
		std::cin >> rows;
		cols = rows;
		break;
	}
	default:
	{
		throw std::invalid_argument("�������� ���");
	}
	}
	_matrixVector.push_back(FactoryMatrix(type, rows, cols));
	std::cout << "������� ������� " << rows << " �� " << cols << std::endl;
	for (int i = 0; i < rows; i++)
	{
		double* row = (*_matrixVector.back())[i];   //��������� �� ��������� ���
		for (int j = 0; j < cols; j++)
		{
			std::cin >> row[j];
		}
	}
}

void MatrixInteractor::MatrixSum()
{
	int first, second, result;
	std::cout << "������� ����� ������ �������" << std::endl;
	std::cin >> first;
	std::cout << "������� ����� ������ �������" << std::endl;
	std::cin >> second;
	std::cout << "������� ����� �������������� �������" << std::endl;
	std::cin >> result;
	*(_matrixVector[result]) = *(_matrixVector[first]) + *(_matrixVector[second]);
}

void MatrixInteractor::MatrixSub()
{
	int first, second, result;
	std::cout << "������� ����� ������ �������" << std::endl;
	std::cin >> first;
	std::cout << "������� ����� ������ �������" << std::endl;
	std::cin >> second;
	std::cout << "������� ����� �������������� �������" << std::endl;
	std::cin >> result;
	*(_matrixVector[result]) = *(_matrixVector[first]) - *(_matrixVector[second]);
}

void MatrixInteractor::MatrixMul()
{
	int first, second, result;
	std::cout << "������� ����� ������ �������" << std::endl;
	std::cin >> first;
	std::cout << "������� ����� ������ �������" << std::endl;
	std::cin >> second;
	std::cout << "������� ����� �������������� �������" << std::endl;
	std::cin >> result;
	*(_matrixVector[result]) = *(_matrixVector[first]) * *(_matrixVector[second]);
}

void MatrixInteractor::MatrixTran()
{
	int No;
	std::cout << "������� ����� �������" << std::endl;
	std::cin >> No;
	~(*(_matrixVector[No]));
}

void MatrixInteractor::MatrixDet()
{
	int No;
	std::cout << "������� ����� �������" << std::endl;
	std::cin >> No;
	std::cout << ((SquareMatrix)(*(_matrixVector[No]))).Det() << std::endl;
}

void MatrixInteractor::MatrixPrint()
{
	int No;
	std::cout << "������� ����� �������" << std::endl;
	std::cin >> No;
	std::cout << *(_matrixVector[No]);
}

void MatrixInteractor::MatrixErase()
{
	int No;
	std::cout << "������� ����� �������" << std::endl;
	std::cin >> No;
	std::vector<Matrix*>::iterator it = _matrixVector.begin() + No;
	delete (*it);
	_matrixVector.erase(it);
}

Matrix* MatrixInteractor::FactoryMatrix(char type, unsigned int rows, unsigned int cols)
{
	switch (type)
	{
	case 'M':
		return new Matrix(rows, cols);
	case 'S':
		return new SquareMatrix(rows);
	default:
		return NULL;
	}
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
	if (rows == 0 || cols == 0)
	{
		throw "0 dimension matrix";
	}

	char type; if (typeid(m).name()[6] == 'M') type = 'M';else type = 'S';

	os << type << ' ' << rows << ' ' << cols << std::endl;
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