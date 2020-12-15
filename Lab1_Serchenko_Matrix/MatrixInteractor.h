#pragma once
#include "Matrix.h"
#include <fstream>
#include <vector>

class MatrixInteractor
{
public:
	int RunFileMenu();
	int RunConsoleMenu();
	MatrixInteractor() = default;
	MatrixInteractor(const MatrixInteractor&) = default;
	~MatrixInteractor();
private:
	void Expand();
	void MatrixSum();
	void MatrixSub();
	void MatrixMul();
	void MatrixTran();
	void MatrixDet();
	void MatrixPrint();
	void MatrixErase();
	std::string _fileName;
	std::fstream _file;
	std::vector<Matrix*> _matrixVector;
};

void Run();
int  RunMainMenu();
std::ostream& operator<<(std::ostream& os, const Matrix& dt);
