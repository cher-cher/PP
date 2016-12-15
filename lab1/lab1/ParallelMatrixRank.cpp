#include "stdafx.h"
#include "ParallelMatrixRank.h"

using namespace std;

CParallelMatrixRank::CParallelMatrixRank()
{
}

CParallelMatrixRank::CParallelMatrixRank(size_t threads)
	:m_numbThreads(threads)
{
}

void CalculateRankOnThread(CParallelMatrixRank * matrix, size_t numb)
{
	matrix->CalculateRank(numb);
}

size_t CParallelMatrixRank::MatrixRank(Matrix matrix)
{
	m_matrix = matrix;
	m_rank = m_matrix.size();

	std::vector<std::thread> threads;
	threads.resize(m_numbThreads);

	for (size_t i = 0; i <= m_numbThreads - 1; i++)
	{
		threads[i] = thread(CalculateRankOnThread, this, i);
	}
	for (size_t i = 0; i <= m_numbThreads - 1; i++)
	{
		threads[i].join();
	}
	return m_rank;
}

void CParallelMatrixRank::CalculateRank(size_t numbThread)
{
	size_t minSize = m_matrix.size() / m_numbThreads * numbThread;
	size_t maxSize;
	if (numbThread == (m_numbThreads - 1))
	{
		maxSize = m_matrix.size();
	}
	else
	{
		maxSize = minSize + m_matrix.size() / m_numbThreads;
	}
	vector<bool> lineUsed(m_rank);
	for (size_t i = minSize; i < maxSize; ++i)
	{
		size_t j;
		for (j = 0; j < m_matrix.size(); ++j)
		{
			if (!lineUsed[j] && abs(m_matrix[j][i]) > EPS)
			{
				break;
			}
		}
		if (j == m_matrix.size())
		{
			--m_rank;
		}
		else
		{
			lineUsed[j] = true;
			for (size_t k = i + 1; k < m_matrix.size(); ++k)
			{
				m_matrix[j][k] /= m_matrix[j][i];
			}
			for (size_t n = 0; n < m_matrix.size(); ++n)
			{
				if (n != j && abs(m_matrix[n][i] > EPS))
				{
					for (size_t k = i + 1; k < m_matrix.size(); ++k)
					{
						m_matrix[n][k] -= m_matrix[j][k] * m_matrix[n][i];
					}
				}
			}
		}
	}
}

CParallelMatrixRank::~CParallelMatrixRank()
{
}