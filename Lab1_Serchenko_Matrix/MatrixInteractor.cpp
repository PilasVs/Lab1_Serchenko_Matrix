#include "MatrixInteractor.h"
#include <iostream>

void RunMainMenu()
{
	system("cls");
	setlocale(LC_ALL, "Russian");
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
		MI.RunFileMenu();
		break;
	case 2:
		MI.RunConsoleMenu();
	}
}

void MatrixInteractor::RunFileMenu()
{
	system("cls");
	std::cout << "1 - ������ ��� ����� � ��������� ����������" << std::endl;
	std::cout << "2 - ���������� ��������" << std::endl;
	std::cout << "3 - ���������� ���������" << std::endl;
	std::cout << "4 - ��������� ����������������" << std::endl;
	std::cout << "5 - ������� ����� �������" << std::endl;
	std::cout << "6 - ������� ������� �� �����" << std::endl;
	std::cout << "0 - ����� � ������� ������" << std::endl;
	int choice;
	std::cin >> choice;
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
			throw "�������� ��� �����";
		}
		_file >> _quantity;
		_matrixArray = new Matrix * [_quantity];
		for (int count = 0; count < _quantity; count++)
		{
			int rows, cols;
			_file >> rows >> cols;
			_matrixArray[count] = new Matrix(rows, cols);
			for (int i = 0; i < rows; i++)
			{
				double* row = (*(_matrixArray[count]))[i];   //��������� �� ��������� ���
				for (int j = 0; j < cols; j++)
				{
					_file >> row[j];
				}
			}
		}
		break;
	}
	case 2:
	{
		if (!_file.is_open())
		{
			throw "��� ����� �� ������";
		}
		MatrixSum();
		break;
	}
	case 3:
	{
		if (!_file.is_open())
		{
			throw "��� ����� �� ������";
		}
		MatrixSub();
		break;
	}
	case 4:
	{
		if (!_file.is_open())
		{
			throw "��� ����� �� ������";
		}
		MatrixTran();
		break;
	}
	case 5:
	{
		if (!_file.is_open())
		{
			throw "��� ����� �� ������";
		}
		int rows, cols;
		std::cout << "������� ���������� �����" << std::endl;
		std::cin >> rows;
		std::cout << "������� ���������� ������" << std::endl;
		std::cin >> cols;
		Matrix** tmp = _matrixArray;
		_matrixArray = new Matrix * [_quantity + 1];
		std::copy(tmp, tmp + _quantity, _matrixArray);
		delete[] tmp;
		_matrixArray[_quantity] = new Matrix(rows, cols);
		_quantity++;
		break;
	}
	case 6:
	{
		MatrixPrint();
		break;
	}
	case 0:
	{
		std::cout << "������� ��� ����� ��������" << std::endl;
		std::cin >> _fileName;
		if (_file.is_open())
		{
			_file.close();
		}
		_file.open(_fileName, std::ios_base::trunc || std::ios_base::out);
		_file << _quantity << std::endl;
		for (int count = 0; count < _quantity; count++)
		{
			const Matrix& matrix = *(_matrixArray[count]);
			int i, j;
			int rows = matrix.GetRows(), cols = matrix.GetCols();
			_file << rows << ' ' << cols << std::endl;
			for (i = 0; i < rows; i++)
			{
				double* row = matrix[i];
				for (j = 0; j < cols - 1; j++)
				{
					_file << row[j] << ' ';
				}
				_file << row[j] << std::endl;
			}
		}
		//this->~MatrixInteractor();
		RunMainMenu();
		return;
	}
	}
	RunFileMenu();
}

void MatrixInteractor::RunConsoleMenu()
{
	system("cls");
	std::cout << "1 - ������� ����� �������" << std::endl;
	std::cout << "2 - ���������� �������� " << std::endl;
	std::cout << "3 - ���������� ���������" << std::endl;
	std::cout << "4 - ��������� ����������������" << std::endl;
	std::cout << "5 - ������� ������� �� �����" << std::endl;
	std::cout << "0 - �����" << std::endl;
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
	{
		int rows, cols;
		std::cout << "������� ���������� �����" << std::endl;
		std::cin >> rows;
		std::cout << "������� ���������� ������" << std::endl;
		std::cin >> cols;
		Matrix** tmp = _matrixArray;
		_matrixArray = new Matrix * [_quantity + 1];
		std::copy(tmp, tmp + _quantity, _matrixArray);
		delete[] tmp;
		_matrixArray[_quantity] = new Matrix(rows, cols);
		std::cout << "������� ������� " << rows << " �� " << cols << std::endl;
		for (int i = 0; i < rows; i++)
		{
			double* row = (*(_matrixArray[_quantity]))[i];   //��������� �� ��������� ���
			for (int j = 0; j < cols; j++)
			{
				std::cin >> row[j];
			}
		}
		_quantity++;
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
		MatrixTran();
		break;
	}
	case 5:
	{
		MatrixPrint();
		break;
	}
	case 0:
	{
		RunMainMenu();
		return;
	}
	}
	RunConsoleMenu();
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
	*(_matrixArray[result]) = *(_matrixArray[first]) + *(_matrixArray[second]);
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
	*(_matrixArray[result]) = *(_matrixArray[first]) - *(_matrixArray[second]);
}

void MatrixInteractor::MatrixTran()
{
	int num;
	std::cout << "������� ����� �������" << std::endl;
	std::cin >> num;
	~(*(_matrixArray[num]));
}

void MatrixInteractor::MatrixPrint()
{
	int num;
	std::cout << "������� ����� �������" << std::endl;
	std::cin >> num;
	int rows = (*(_matrixArray[num])).GetRows(), cols = (*(_matrixArray[num])).GetCols();
	for (int i = 0; i < rows; i++)
	{
		double* row = (*(_matrixArray[num]))[i];   //��������� �� ��������� ���
		for (int j = 0; j < cols; j++)
		{
			std::cout << row[j] << ' ';
		}
		std::cout << '\n';
	}
}

MatrixInteractor::~MatrixInteractor()
{
	for (int i = 0; i < _quantity; i++)
	{
		delete _matrixArray[i];
	}

	delete[] _matrixArray;
	_file.close();
}