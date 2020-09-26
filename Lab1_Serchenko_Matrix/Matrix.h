#pragma once
class Matrix
{
public:
	int GetRows() const;
	int GetCols() const;
	Matrix& operator ~();
	Matrix operator +(const Matrix& m);
	Matrix operator -(const Matrix& m);
	Matrix& operator =(const Matrix& m);
	double* operator [](int row)const;
	Matrix(int rows, int cols);
	Matrix(const Matrix& Matrix);
	~Matrix();
private:
	int _rows = 0;
	int _cols = 0;
	double** _Matrix = nullptr;
};

