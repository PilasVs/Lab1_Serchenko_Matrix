#include "Matrix.h"
#include <algorithm>
#include <stdexcept>

int Matrix::GetRows() const {
	return _rows;
}

int Matrix::GetCols() const {
	return _cols;
}

void Matrix::Randomize() const
{
	for (unsigned int i = 0; i < _rows; i++)
	{
		for (unsigned int j = 0; j < _cols; j++)
		{
			_Matrix[i][j] = std::rand() % 10;
		}
	}
}

Matrix* Matrix::FactoryMatrix(unsigned int rows, unsigned int cols)
{
	if (rows == cols)
	{
		return new SquareMatrix(rows);
	}
	return new Matrix(rows, cols);
}

Matrix& Matrix::operator~()
{
	double** _NewMatrix = new double* [_cols];
	for (unsigned int i = 0; i < _cols; i++)
	{
		_NewMatrix[i] = new double[_rows];
		for (unsigned int j = 0; j < _rows; j++)
		{
			_NewMatrix[i][j] = _Matrix[j][i];
		}
	}
	this->~Matrix();
	std::swap(_rows, _cols);
	_Matrix = _NewMatrix;
	return *this;
}

Matrix Matrix::operator+(const Matrix& m) 
{
	if (_rows != m._rows || _cols != m._cols)
	{
		throw std::length_error("Sizes of matrices differ");
	}
	Matrix tmp(_rows, _cols);
	for (unsigned int i = 0; i < _rows; i++)
	{
		for (unsigned int j = 0; j < _cols; j++)
		{
			(tmp)._Matrix[i][j] = _Matrix[i][j] + m._Matrix[i][j];
		}
	}
	return tmp;
}

Matrix Matrix::operator-(const Matrix& m)
{
	if (_rows != m._rows || _cols != m._cols)
	{
		throw std::length_error("Sizes of matrices differ");
	}

	Matrix tmp(_rows, _cols);
	for (unsigned int i = 0; i < _rows; i++)
	{
		for (unsigned int j = 0; j < _cols; j++)
		{
			tmp._Matrix[i][j] = _Matrix[i][j] - m._Matrix[i][j];
		}
	}
	return tmp;
}

Matrix Matrix::operator=(const Matrix& m)
{
	if (_rows != m._rows || _cols != m._cols)
	{
		throw std::length_error("Sizes of matrices differ");
	}

	for (unsigned int i = 0; i < _rows; i++)
	{
		std::copy(m._Matrix[i], m._Matrix[i] + _cols, _Matrix[i]);
	}
	return *this;
}

Matrix Matrix::operator*(const Matrix& m)
{
	if (_cols != m._rows)
	{
		throw std::length_error("1st multiplier's cols != 2nd multiplier's rows");
	}

	Matrix tmp(_rows, m._cols);
	unsigned int i, j, k;
	for (i = 0; i < _rows; i++)
	{
		for (j = 0; j < m._cols; j++)
		{
			tmp._Matrix[i][j] = 0;
			for (k = 0; k < _cols; k++)
			{
				tmp._Matrix[i][j] += _Matrix[i][k] * m._Matrix[k][j];
			}
		}
	}
	return tmp;
}

double* Matrix::operator[](unsigned int row)const
{
	return _Matrix[row];
}

Matrix::Matrix(unsigned int rows, unsigned int cols)
{
	_rows = rows;
	_cols = cols;
	_Matrix = new double* [_rows];
	for (unsigned int i = 0; i < _rows; i++)
	{
		_Matrix[i] = new double[_cols];
	}
}

Matrix::Matrix(const Matrix& m) 
{
	_rows = m._rows;
	_cols = m._cols;
	_Matrix = new double*[_rows];
	for (unsigned int i = 0; i < _rows; i++)
	{
		_Matrix[i] = new double[_cols];
		std::copy(m._Matrix[i], m._Matrix[i] + _cols , _Matrix[i]);
	}
}

Matrix::~Matrix() 
{
	for (unsigned int i = 0; i < _rows; i++)
	{
		delete[] _Matrix[i];
	}

	delete[] _Matrix;
}

SquareMatrix::SquareMatrix(unsigned int rowscols)
	:Matrix(rowscols, rowscols) {}

SquareMatrix::SquareMatrix(const Matrix& m)
	:Matrix(m)
{
	if (m.GetCols() != m.GetRows())
	{
		throw std::invalid_argument("SquareMatrix creation failed");
	}
}

Matrix& SquareMatrix::operator~()
{
	for (unsigned int i = 0; i < _rows; i++)
	{
		for (unsigned int j = i + 1; j < _cols; j++)
		{
			std::swap(_Matrix[i][j], _Matrix[j][i]);
		}
	}
	return *this;
}

double SquareMatrix::Det()
{
	double D = 0, n = this->GetRows();
	if (n == 1)
	{
		return (*this)[0][0];

	}

	SquareMatrix* tmp = new SquareMatrix(n - 1);

	int sign = 1;
	for (int f = 0; f < n; f++)
	{
		getCofactor(this, tmp, 0, f);
		D += sign * (*this)[0][f] * (*tmp).Det();

		sign = -sign;
	}
	delete tmp;

	return D;
}

void SquareMatrix::getCofactor(SquareMatrix* sm, SquareMatrix* tmp, int excessRow, int excessCol)
{
	int i = 0, j = 0, n = (*sm).GetRows();
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			if (row != excessRow && col != excessCol)
			{
				(*tmp)[i][j++] = (*sm)[row][col];
				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}