//-------------------------------------------------------------------------------------------
// Dijkstra.h
// Description: класс, реализующий метод Дейкстры
// Date: 23.11.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once
#include "Graph.h"

namespace Graph
{
class Dijkstra : public Graph
{
public:
	Dijkstra(std::string fileName = "Graphs\\GraphDijkstra.txt");
	~Dijkstra() = default;

	virtual void Calculate();
	virtual void Output();
	virtual void Input();

protected:
	int m_source = 0;
	Edge* m_negativeWeightEdge = nullptr;
	std::vector<int> m_parents;
	std::vector<std::vector<Edge>> m_edgedGraph;
	void PrintPath(int vertex);
};
}