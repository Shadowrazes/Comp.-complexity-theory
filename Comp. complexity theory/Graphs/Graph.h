//-------------------------------------------------------------------------------------------
// Graph.h
// Description: базовый класс для решения задач с графами
// Date: 23.11.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once

#include "../Input/FileInput.h"

namespace Graph 
{
class Graph : public Input::FileInput
{
public:
	Graph(std::string fileName = "Graphs\\Graph.txt");
	~Graph() = default;

	struct Edge {
		int Start = 0;
		int Close = 0;
		int Weight = 0;
	};

	virtual void Calculate() = 0;
	virtual void Output(){};
	virtual void Input();
	virtual int  FindVertexCount();
	virtual void EdgesToMatrix();
	virtual int  GetComplexity() { return m_complexity; }

protected:
	std::vector<Edge> m_graph;
	std::vector< std::vector<int>> m_matrixGraph;
	std::vector<int> m_result;
	int m_vertexCount = 0;
	int m_complexity = 0;
};
}
