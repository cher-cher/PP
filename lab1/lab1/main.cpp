// lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Matrix.h"
#include "SuccessivelyMatrixRank.h"
#include "ParallelMatrixRank.h"

using namespace std;

int main(int argc, char * argv[])
{
	CMatrix matrix;
	matrix.GenerateMatrix(atoi(argv[1]));
	matrix.Print();

	size_t threadsCount = atoi(argv[2]);

	auto startTime = chrono::steady_clock::now();

	if (threadsCount > 1)
	{
		CParallelMatrixRank calc(threadsCount);
		cout << "rank matrix: " << calc.MatrixRank(matrix.GetMatrix()) << endl;
	}
	else
	{
		CSuccessivelyMatrixRank calc;
		cout << "rank matrix: " << calc.MatrixRank(matrix.GetMatrix()) << endl;
	}
	auto endTime = chrono::steady_clock::now();
	chrono::duration<double> diff = endTime - startTime;

	cout << diff.count() << endl;
    return 0;
}

