#pragma once
#include "MatrixRank.h"
#include "Matrix.h"

class CSuccessivelyMatrixRank : public CMatrixRank
{
public:
	CSuccessivelyMatrixRank();
	~CSuccessivelyMatrixRank();
	size_t MatrixRank(Matrix matrix) override;
private: 
	Matrix m_matrix;
};