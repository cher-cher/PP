#include "stdafx.h"
#include "Matrix.h"


using namespace std;

CMatrix::CMatrix()
{
}

void CMatrix::Print()
{
	for (size_t i = 0; i < m_inputMatrix.size(); i++)
	{
		for (size_t j = 0; j < m_inputMatrix[0].size(); j++)
		{
			cout << m_inputMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

void CMatrix::GenerateMatrix(size_t sizeMatrix)
{
	m_inputMatrix.resize(sizeMatrix);
	srand(time(NULL));
	for (size_t i = 0; i < sizeMatrix; i++)
	{
		m_inputMatrix[i].resize(sizeMatrix);
		for (size_t j = 0; j < sizeMatrix; j++)
		{
			m_inputMatrix[i][j] = float(rand() % 10);
		}
	}
}

Matrix CMatrix::GetMatrix() const
{
	return m_inputMatrix;
}