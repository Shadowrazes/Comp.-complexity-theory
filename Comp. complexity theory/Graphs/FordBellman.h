//-------------------------------------------------------------------------------------------
// FordBellman.h
// Description: класс, реализующий метод Форда-Беллмана
// Date: 23.11.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once
#include "Graph.h"

namespace Graph
{
class FordBellman : public Graph
{
public:
	FordBellman(std::string fileName = "Graphs\\Graph.txt");
	~FordBellman() = default;

	virtual void Calculate();
	virtual void Output();
	virtual void Input();

protected:
	int m_source = 0;
	int m_countVertexEntry = 0;
	bool m_cycled = false;
	std::vector<int> m_parents;
	void PrintPath(int vertex);
	void PrintCyclePath(int vertex);
};
}