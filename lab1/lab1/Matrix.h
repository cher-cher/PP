#pragma once

typedef std::vector<std::vector<float>> Matrix;

class CMatrix
{
public:
	CMatrix();
	~CMatrix() = default;
	void Print();
	Matrix GetMatrix() const;
	void GenerateMatrix(size_t sizeMatrix);
private:
	Matrix m_inputMatrix;
};