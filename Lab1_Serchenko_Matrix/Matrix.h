#pragma once
class Matrix
{
public:
	int GetRows() const;
	int GetCols() const;
	void Randomize() const;
	virtual Matrix& operator ~();
	Matrix operator +(const Matrix& m);
	Matrix operator -(const Matrix& m);
	Matrix operator =(const Matrix& m);
	Matrix operator *(const Matrix& m);
	double* operator [](unsigned int row)const;
	Matrix(unsigned int rows, unsigned int cols);
	Matrix(const Matrix& m);
	virtual ~Matrix();
protected:
	unsigned int _rows = 0;
	unsigned int _cols = 0;
	double** _Matrix = nullptr;
};

class SquareMatrix :public Matrix
{
public:
	SquareMatrix(unsigned int rowscols);
	SquareMatrix(const Matrix& m);
	Matrix& operator ~() override;
	int Det();
private:
	void getCofactor(SquareMatrix* sm, SquareMatrix* tmp, int excessRow, int excessCol);
};
