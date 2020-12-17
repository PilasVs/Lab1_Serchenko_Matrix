#pragma once
class Matrix
{
public:
	int GetRows() const;
	int GetCols() const;
	//void Randomize() const;
	virtual Matrix& operator ~();
	Matrix operator +(const Matrix& m) const;
	Matrix operator -(const Matrix& m) const;
	Matrix operator =(const Matrix& m) const;
	Matrix operator *(const Matrix& m) const;
	double* operator [](unsigned int row) const;
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
	double Det() const;
	SquareMatrix(unsigned int rowscols);
	SquareMatrix(const Matrix& m);
	~SquareMatrix() = default;
private:
	void getCofactor(const SquareMatrix* sm, SquareMatrix* tmp, int excessRow, int excessCol) const;
};

class FactoryMatrix 
{
public:
	static Matrix* CreateMatrix(unsigned int rows, unsigned int cols);
};