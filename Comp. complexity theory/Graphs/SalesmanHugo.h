//-------------------------------------------------------------------------------------------
// Salesman.h
// Description: класс, реализующий решения задачи коммивояжера
// Date: 25.11.2022
// Authors: Хьюго М.А.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once
#include "Graph.h"

namespace Graph
{
class Salesman : public Graph
{
public:
	Salesman(std::string fileName = "Graphs\\GraphRGR.txt");
	~Salesman() = default;

	virtual void Calculate() override;
	virtual void Output();
	virtual void Input();

	struct PathNode {
		std::vector<std::vector<int>>& matrixGraph;
		int Cost = -1;
		int VertexNum = -1;
		PathNode* Parent = nullptr;
		PathNode* Left = nullptr;
		PathNode* Right = nullptr;
	};

protected:
	int m_minPathWeight = INT_MAX;
	int m_countVertexEntry = 0;
	int m_curRecurionDepth = 0;
	int m_totalMinCost = 14;
	bool m_firstIterationPass = false;
	std::vector<int> m_path;
	std::vector<int> m_passedCycles;
	PathNode* m_root;
	PathNode* m_pointer = m_root;
	virtual void Overkill();
	virtual void BranchesAndBoundaries(std::vector<std::vector<int>> matrixGraphParent, int cost);
	virtual int RowsAndColumnsReduction(std::vector<std::vector<int>>& matrixGraph, int cost);
	virtual int ZeroesSurcharge(std::vector<std::vector<int>>& matrixGraph, int& row, int& column);
	virtual int RowColumnMinimumsSum(std::vector<std::vector<int>>& matrixGraph, int rowInd, int columnInd);
};
}