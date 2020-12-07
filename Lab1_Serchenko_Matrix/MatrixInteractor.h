#pragma once
#include "Matrix.h"
#include <fstream>

class MatrixInteractor
{
public:
	void RunFileMenu();
	void RunConsoleMenu();
	~MatrixInteractor();
private:
	void MatrixSum();
	void MatrixSub();
	void MatrixTran();
	void MatrixPrint();
	std::string _fileName;
	std::fstream _file;
	int _quantity = 0;
	Matrix** _matrixArray = nullptr;
};

void RunMainMenu();

