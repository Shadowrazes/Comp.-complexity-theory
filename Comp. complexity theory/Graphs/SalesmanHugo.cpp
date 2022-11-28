#include "SalesmanHugo.h"
#include <iomanip>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <numeric>

namespace Graph
{
Salesman::Salesman(std::string fileName) : Graph(fileName) {

}

void Salesman::Input() {
	Graph::Input();
	EdgesToMatrix();
	m_passedCycles = std::vector<int>(m_vertexCount, 0);
}

void Salesman::Output() {
	if (!m_firstIterationPass) {
		int str = 0;
		for (const auto& stroke : m_matrixGraph) {
			std::cout << std::setw(3) << str++ << " |";
			for (const auto& column : stroke) {
				std::cout << std::setw(3) << (column != INT_MAX && column != -INT_MAX ? std::to_string(column) : "i");
			}
			std::cout << std::endl;
		}

		std::cout << "\nOverkill: \n";

		auto item = std::find_if(m_graph.begin(), m_graph.end(),
			[&](const Edge& elem) {return  m_path.back() == elem.Start && m_path.front() == elem.Close; });

		m_path.push_back(m_path.front());
		m_minPathWeight += (*item).Weight;

		std::cout << std::endl;

		std::cout << "Shortest path: ";
		for (const auto& vertex : m_path)
			std::cout << vertex << " ";

		std::cout << "\nWeight: " << m_minPathWeight;
		std::cout << "\nComplexity: " << m_complexity;
		std::cout << std::endl;
	}
	else {
		std::cout << "\nBranches and boundaries: \n";

		std::vector<Edge> edges;
		for (int i = 0; i < m_path.size(); i += 2) {
			auto item = std::find_if(m_graph.begin(), m_graph.end(),
				[&](const Edge& elem) {return  m_path[i] == elem.Start && m_path[i + 1] == elem.Close; });
			m_minPathWeight += (*item).Weight;
			edges.push_back(*item);
		}
		m_path.clear();

		m_path.push_back(edges[0].Start);

		for (int i = 0; i < edges.size(); i++) {
			auto item = std::find_if(edges.begin(), edges.end(),
				[&](const Edge& elem) {return  m_path.back() == elem.Start; });
			m_path.push_back((*item).Close);
		}

		std::cout << std::endl;

		std::cout << "Shortest path: ";
		for (const auto& vertex : m_path)
			std::cout << vertex << " ";

		std::cout << "\nWeight: " << m_minPathWeight;
		std::cout << "\nComplexity: " << m_complexity;
		std::cout << std::endl;
	}
}

void Salesman::Calculate() {
	Overkill();
	m_complexity -= tgamma(m_vertexCount);
	Output();

	m_path.clear();
	m_complexity = 0;
	m_minPathWeight = 0;
	BranchesAndBoundaries(m_matrixGraph, m_totalMinCost);
	Output();

}

void Salesman::Overkill() {
	for (int j = 0; j < m_vertexCount; j++) {
		if (m_passedCycles[m_curRecurionDepth] < m_vertexCount && m_curRecurionDepth != m_vertexCount - 1) {
			m_curRecurionDepth++;
			Overkill();
		}

		std::unordered_set check(m_passedCycles.begin(), m_passedCycles.end());
		if (check.size() == m_passedCycles.size()) {
			int tempPath = 0;
			for (int i = 0; i < m_passedCycles.size() - 1; i++) {
				tempPath += m_matrixGraph[m_passedCycles[i]][m_passedCycles[i + 1]];
			}

			if (tempPath < m_minPathWeight && tempPath > -1) {
				m_minPathWeight = tempPath;
				m_path = m_passedCycles;
			}

			m_complexity++;
		}
		m_passedCycles[m_curRecurionDepth]++;
	}

	m_passedCycles[m_curRecurionDepth] = 0;
	m_curRecurionDepth--;
	return;
}

int Salesman::RowsAndColumnsReduction(std::vector<std::vector<int>>& matrixGraph, int cost) {
	std::vector<int> strokesMinimums;
	std::vector<int> columnsMinimums;

	for (auto& stroke : matrixGraph) {
		int strokeMin = INT_MAX;
		for (auto& column : stroke) {
			if (column < strokeMin && column != -INT_MAX) {
				strokeMin = column;
			}
		}

		for (auto& column : stroke) {
			if (column != INT_MAX && column != -INT_MAX) {
				column -= strokeMin;
			}
		}

		strokesMinimums.push_back(strokeMin);
	}

	for (int i = 0; i < matrixGraph.size(); i++) {
		int columnMin = INT_MAX;
		for (int j = 0; j < matrixGraph.size(); j++) {
			if (matrixGraph[j][i] < columnMin && matrixGraph[j][i] != -INT_MAX) {
				columnMin = matrixGraph[j][i];
			}
		}

		for (int j = 0; j < matrixGraph.size(); j++) {
			if(matrixGraph[j][i] != INT_MAX && matrixGraph[j][i] != -INT_MAX)
				matrixGraph[j][i] -= columnMin;
		}

		columnsMinimums.push_back(columnMin);
	}

	int rowSum = 0, columnSum = 0;
	for (int i = 0; i < strokesMinimums.size(); i++) {
		if(strokesMinimums[i] != INT_MAX && strokesMinimums[i] != -INT_MAX)
			rowSum += strokesMinimums[i];

		if (columnsMinimums[i] != INT_MAX && columnsMinimums[i] != -INT_MAX)
			columnSum += columnsMinimums[i];
	}

	return cost + rowSum + columnSum;
}

int Salesman::RowColumnMinimumsSum(std::vector<std::vector<int>>& matrixGraph, int rowInd, int columnInd) {
	int rowMin = INT_MAX;
	int columnMin = INT_MAX;

	for (int i = 0; i < matrixGraph.size(); i++) {
		rowMin = rowMin > matrixGraph[rowInd][i] && i != columnInd && matrixGraph[rowInd][i] != -INT_MAX ? matrixGraph[rowInd][i] : rowMin;
	}

	for (int i = 0; i < matrixGraph.size(); i++) {
		columnMin = columnMin > matrixGraph[i][columnInd] && i != rowInd && matrixGraph[i][columnInd] != -INT_MAX ? matrixGraph[i][columnInd] : columnMin;
	}

	if (rowMin == INT_MAX) rowMin = 0;
	if (columnMin == INT_MAX) columnMin = 0;

	return rowMin + columnMin;
}

void ZeroingRowColumn(std::vector<std::vector<int>>& matrixGraph, int rowInd, int columnInd) {
	for (int i = 0; i < matrixGraph.size(); i++) {
		if (matrixGraph[rowInd][i] != INT_MAX) {
			matrixGraph[rowInd][i] = -INT_MAX;
		}
	}

	for (int i = 0; i < matrixGraph.size(); i++) {
		if (matrixGraph[i][columnInd] != INT_MAX) {
			matrixGraph[i][columnInd] = -INT_MAX;
		}
	}

	matrixGraph[columnInd][rowInd] = -INT_MAX;
}

int Salesman::ZeroesSurcharge(std::vector<std::vector<int>>& matrixGraph, int& row, int& column) {
	int maxSurcharge = 0;
	for (int i = 0; i < matrixGraph.size(); i++) {
		for (int j = 0; j < matrixGraph.size(); j++) {
			if (matrixGraph[i][j] == 0) {
				int tempSurcharge = RowColumnMinimumsSum(matrixGraph, i, j);
				if (maxSurcharge <= tempSurcharge) {
					maxSurcharge = tempSurcharge;
					row = i;
					column = j;
				}
			}
		}
	}
	return maxSurcharge;
}

void Salesman::BranchesAndBoundaries(std::vector<std::vector<int>> matrixGraphParent, int cost) {
	if (m_path.size() == m_vertexCount * 2)
		return;

	m_complexity++;
	int rightCost = 0;
	if(m_firstIterationPass)
		rightCost = RowsAndColumnsReduction(matrixGraphParent, cost);
	else
		rightCost = RowsAndColumnsReduction(matrixGraphParent, 0);

	if (!m_firstIterationPass)
		m_firstIterationPass = true;

	int row = 0, column = 0, maxSurcharge = ZeroesSurcharge(matrixGraphParent, row, column);
	int leftCost = cost + maxSurcharge;
	m_path.push_back(row);
	m_path.push_back(column);

	std::vector<std::vector<int>> rightMatrix = matrixGraphParent;
	ZeroingRowColumn(rightMatrix, row, column);

	const bool toRight = leftCost >= rightCost;

	if (toRight) {
		m_totalMinCost = rightCost;
		BranchesAndBoundaries(rightMatrix, rightCost);
		if (leftCost < m_totalMinCost) {
			m_path.pop_back();
			m_path.pop_back();
			BranchesAndBoundaries(matrixGraphParent, leftCost);
		}
	}
	else {
		m_totalMinCost = leftCost;
		BranchesAndBoundaries(matrixGraphParent, leftCost);
		if (rightCost < m_totalMinCost) {
			m_path.pop_back();
			m_path.pop_back();
			BranchesAndBoundaries(rightMatrix, rightCost);
		}
	}
}
}