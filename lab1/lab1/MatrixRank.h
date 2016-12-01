#pragma once
#include "Matrix.h"

const float EPS = 0.0000000001f;

class CMatrixRank
{
public:
	CMatrixRank();
	~CMatrixRank();

	virtual size_t MatrixRank(Matrix matrix) = 0;
protected:
	int m_rank = 0;
};