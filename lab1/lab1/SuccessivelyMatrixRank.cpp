#include "stdafx.h"
#include "SuccessivelyMatrixRank.h"

using namespace std;

CSuccessivelyMatrixRank::CSuccessivelyMatrixRank()
{
}

CSuccessivelyMatrixRank::~CSuccessivelyMatrixRank()
{
}

size_t CSuccessivelyMatrixRank::MatrixRank(Matrix matrix)
{
	m_rank = matrix.size();
	vector<bool> lineUsed(m_rank);
	for (size_t i = 0; i < matrix.size(); ++i)
	{
		size_t j;
		for (j = 0; j < matrix.size(); ++j)
		{
			if (!lineUsed[j] && abs(matrix[j][i]) > EPS)
			{
				break;
			}
		}
		if (j == matrix.size())
		{
			--m_rank;
		}
		else
		{
			lineUsed[j] = true;
			for (size_t k = i + 1; k < matrix.size(); ++k)
			{
				matrix[j][k] /= matrix[j][i];
			}
			for (size_t n = 0; n < matrix.size(); ++n)
			{
				if (n != j && abs(matrix[n][i] > EPS))
				{
					for (size_t k = i + 1; k < matrix.size(); ++k)
					{
						matrix[n][k] -= matrix[j][k] * matrix[n][i];
					}
				}
			}
		}
	}
	return m_rank;
}