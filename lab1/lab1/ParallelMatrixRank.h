#pragma once
#include "stdafx.h"
#include "MatrixRank.h"

class CParallelMatrixRank : public CMatrixRank
{
public:
	CParallelMatrixRank();
	CParallelMatrixRank(size_t threads);
	~CParallelMatrixRank();
	void CalculateRank(size_t numbThread);
	size_t MatrixRank(Matrix matrix) override;
private:
	Matrix m_matrix;
	size_t m_numbThreads = 0;
};