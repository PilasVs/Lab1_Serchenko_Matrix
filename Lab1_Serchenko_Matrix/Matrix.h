#pragma once
class Matrix
{
public:
	int GetRows() const;
	int GetCols() const;
	void Randomize() const;
	static Matrix* FactoryMatrix(unsigned int rows, unsigned int cols);
	virtual Matrix& operator ~();
	Matrix operator +(const Matrix& m);
	Matrix operator -(const Matrix& m);
	Matrix operator =(const Matrix& m);
	Matrix operator *(const Matrix& m);
	double* operator [](unsigned int row)const;
	Matrix(unsigned int rows, unsigned int cols);
	Matrix(const Matrix& m);
	~Matrix();
protected:
	unsigned int _rows = 0;
	unsigned int _cols = 0;
	double** _Matrix = nullptr;
};

class SquareMatrix :public Matrix
{
public:
	Matrix& operator ~() override;
	double Det();
	SquareMatrix(unsigned int rowscols);
	SquareMatrix(const Matrix& m);
	~SquareMatrix() = default;
private:
	void getCofactor(SquareMatrix* sm, SquareMatrix* tmp, int excessRow, int excessCol);
};