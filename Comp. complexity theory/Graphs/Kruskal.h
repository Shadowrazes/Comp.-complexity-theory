//-------------------------------------------------------------------------------------------
// Kruskal.h
// Description: класс, реализующий метод Форда-Беллмана
// Date: 23.11.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once
#include "Graph.h"

namespace Graph
{
class Kruskal : public Graph
{
public:
	Kruskal(std::string fileName = "Graphs\\Graph.txt");
	~Kruskal() = default;

	virtual void Calculate();
	virtual void Output();
	virtual void Input();

protected:
	std::vector<Edge> m_spanningTree;
};
}