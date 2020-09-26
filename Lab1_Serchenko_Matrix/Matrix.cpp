#include "Matrix.h"
#include <algorithm>


int Matrix::GetRows() const {
	return _rows;
}
int Matrix::GetCols() const {
	return _cols;
}

Matrix& Matrix::operator~()
{
	if (_rows == _cols)
	{
		for (int i = 0; i < _rows; i++)
		{
			for (int j = i + 1; j < _cols; j++)
			{
				std::swap(_Matrix[i][j], _Matrix[j][i]);
			}
		}
	}
	else
	{
		std::swap(_rows, _cols);
		int i;
		double** _NewMatrix = new double* [_rows];
		for (i = 0; i < _rows; i++)
		{
			_NewMatrix[i] = new double[_cols];
			for (int j = 0; j < _cols; j++)
			{
				_NewMatrix[i][j];
			}
		}

	}
	return *this;
}

Matrix Matrix::operator+(const Matrix& m) 
{
	Matrix tmp(_rows, _cols);
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _cols; j++) 
		{
			tmp._Matrix[i][j] = _Matrix[i][j] + m._Matrix[i][j];
		}
	}
	return tmp;
}

Matrix Matrix::operator-(const Matrix& m)
{
	Matrix tmp(_rows, _cols);
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _cols; j++)
		{
			tmp._Matrix[i][j] = _Matrix[i][j] - m._Matrix[i][j];
		}
	}
	return tmp;
}

Matrix& Matrix::operator=(const Matrix& m)
{
	if (_rows == m._rows && _cols == m._cols)
	{
		for (int i = 0; i < _rows; i++)
		{
			std::copy(m._Matrix[i], m._Matrix[i] + _cols, _Matrix[i]);
		}
	}
	else
	{

	}
	return *this;
}

double* Matrix::operator[](int row)const
{
	return _Matrix[row];
}

Matrix::Matrix(int rows, int cols) 
{
	_rows = rows;
	_cols = cols;
	_Matrix = new double* [_rows];
	for (int i = 0; i < _rows; i++)
	{
		_Matrix[i] = new double[_cols];
		//std::fill(_Matrix[i], _Matrix[i] + _rows, 0);
	}
}

Matrix::Matrix(const Matrix& m) 
{
	_rows = m._rows;
	_cols = m._cols;
	_Matrix = new double*[_rows];
	for (int i = 0; i < _rows; i++) 
	{
		_Matrix[i] = new double[_cols];
		std::copy(m._Matrix[i], m._Matrix[i] + _cols , _Matrix[i]);
	}
}

Matrix::~Matrix() 
{
	for (int i = 0; i < _rows; i++)
	{
		delete[] _Matrix[i];
	}

	delete[] _Matrix;
}
