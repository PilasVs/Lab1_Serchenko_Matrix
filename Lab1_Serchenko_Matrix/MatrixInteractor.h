#pragma once
#include "Matrix.h"
#include <fstream>
#include <vector>
#include <map>
#include <set>

class MatrixInteractor
{
public:
	int RunFileMenu();
	int RunConsoleMenu();
	MatrixInteractor() = default;
	MatrixInteractor(const MatrixInteractor&) = default;
	~MatrixInteractor();
private:
	void Expand(std::istream& is, bool prompt);
	void MatrixSum();
	void MatrixSub();
	void MatrixMul();
	void MatrixTran();
	void MatrixDet();
	void MatrixPrint();
	void MatrixFindNo();
	void MatrixFindDet();
	void MatrixErase();
	std::string _fileName;
	std::fstream _file;
	std::vector<Matrix*> _matrixVector;
	std::map<std::pair<unsigned int, unsigned int>, std::set<unsigned int>> _mapNo;
	std::map<double, std::set<unsigned int>> _mapDet;
};

void Run();
int  RunMainMenu();
std::ostream& operator<<(std::ostream& os, const Matrix& dt);
