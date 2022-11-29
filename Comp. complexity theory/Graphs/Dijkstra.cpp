#include "Dijkstra.h"
#include <iomanip>
#include <set>

namespace Graph
{
	Dijkstra::Dijkstra(std::string fileName) : Graph(fileName) {

}

void Dijkstra::Input() {
	Graph::Input();
	FindVertexCount();

	while (1) {
		std::cout << "Input source vertex: ";
		std::cin >> m_source;

		if (m_source > m_vertexCount - 1)
			std::cout << "This source wasn't found, try again\n";
		else
			break;
	}

	m_edgedGraph = std::vector<std::vector<Edge>>(m_vertexCount);
	for (auto& item : m_graph) {
		m_edgedGraph[item.Start].push_back(item);

		if (item.Weight < 0) {
			m_negativeWeightEdge = &item;
			break;
		}
	}
}

void Dijkstra::PrintPath(int vertex)
{
	if (vertex < 0) {
		return;
	}

	PrintPath(m_parents[vertex]);
	if (vertex != m_source) {
		std::cout << ", ";
	}
	std::cout << vertex;
}

void Dijkstra::Output() {
	if (m_negativeWeightEdge == nullptr) {
		for (int i = 0; i < m_vertexCount; i++)
		{
			if (i != m_source && m_result[i] < INT_MAX)
			{
				std::cout << "Distance from source = " << m_source << " to " << i << " = " << m_result[i] << "\t Path: [";
				PrintPath(i);
				std::cout << "]" << std::endl;
			}
		}
	}
	else {
		std::cout << "Edge with negative weight was found: " << m_negativeWeightEdge->Start << " "
				  << m_negativeWeightEdge->Close << " " << m_negativeWeightEdge->Weight << "\nExit";
	}
}

void Dijkstra::Calculate() {
	if (m_negativeWeightEdge != nullptr)
		return;

	m_parents = std::vector<int>(m_vertexCount, -1);
	m_result = std::vector<int>(m_vertexCount, INT_MAX);
	std::set<std::pair<int, int>> unused;
	unused.insert(std::make_pair(0, m_source));
	m_result[m_source] = 0;

	while (!unused.empty()) {
		int i = unused.begin()->second;
		unused.erase(unused.begin());

		for (auto& edge : m_edgedGraph[i]) {
			if (edge.Weight != INT_MAX && m_result[i] != INT_MAX && m_result[i] + edge.Weight < m_result[edge.Close]) {
				unused.erase(std::make_pair(m_result[edge.Close], edge.Close));
				m_result[edge.Close] = m_result[i] + edge.Weight;
				m_parents[edge.Close] = i;
				unused.insert(std::make_pair(m_result[edge.Close], edge.Close));
			}
		}
	}
}
}