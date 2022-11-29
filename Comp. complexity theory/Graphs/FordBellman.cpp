#include "FordBellman.h"
#include <iomanip>

namespace Graph
{
FordBellman::FordBellman(std::string fileName) : Graph(fileName) {

}

void FordBellman::Input() {
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
}

void FordBellman::PrintCyclePath(int vertex)
{
	if (vertex < 0 || m_countVertexEntry > 1) {
		return;
	}

	if (vertex == m_source)
		m_countVertexEntry++;

	PrintCyclePath(m_parents[vertex]);
	std::cout << vertex << " ";
}

void FordBellman::PrintPath(int vertex)
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

void FordBellman::Output() {
	if (!m_cycled) {
		for (int i = 0; i < m_vertexCount; i++) {
			if (i != m_source && m_result[i] < INT_MAX) {
				std::cout << "Distance from source = " << m_source << " to " << i << " = " << m_result[i] << "\t Path: [";
				PrintPath(i);
				std::cout << "]" << std::endl;
			}
		}
	}
	else {
		std::cout << "Negative cycle was found, path: ";
		PrintCyclePath(m_source);
		std::cout << "\nExit";
	}
}

void FordBellman::Calculate() {
	m_parents = std::vector<int>(m_vertexCount, -1);
	m_result = std::vector<int>(m_vertexCount, INT_MAX);
	m_result[m_source] = 0;

	for (int i = 0; i < m_graph.size() + 1; ++i) {
		for (auto& edge : m_graph){
			if (edge.Weight != INT_MAX && m_result[edge.Start] != INT_MAX && m_result[edge.Start] + edge.Weight < m_result[edge.Close]) {
				m_result[edge.Close] = m_result[edge.Start] + edge.Weight;
				m_parents[edge.Close] = edge.Start;

				if (i == m_graph.size()) {
					m_cycled = true;
					break;
				}
			}
		}
	}
}
}