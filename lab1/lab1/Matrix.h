#pragma once

typedef std::vector<std::vector<float>> Matrix;

class CMatrix
{
public:
	CMatrix();
	~CMatrix() = default;
	void Print();
	friend std::ostream& operator<<(std::ostream& os, const Matrix & inputMatrix);
	Matrix GetMatrix() const;
	void GenerateMatrix(size_t sizeMatrix);
private:
	std::vector<std::vector<float>> m_inputMatrix;
};