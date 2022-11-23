#include "FordBellman.h"
#include <iomanip>

namespace Graph
{
FordBellman::FordBellman(std::string fileName) : Graph(fileName) {

}

void FordBellman::Input() {
	std::cout << "Input source vertex: ";
	std::cin >> m_source;
	Graph::Input();
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
	for (int i = 0; i < m_vertexCount; i++){
		if (i != m_source && m_result[i] < INT_MAX){
			std::cout << "Distance from source = " << m_source << " to " << i << " = " << m_result[i] << "\t Path: [";
			PrintPath(i); 
			std::cout << "]" << std::endl;
		}
	}
	std::cout << "Complexity: " << m_complexity << std::endl;
}

void FordBellman::Calculate() {
	FindVertexCount();
	m_parents = std::vector<int>(m_vertexCount, -1);
	m_result = std::vector<int>(m_vertexCount, INT_MAX);
	m_result[m_source] = 0;
	bool quit = false;

	for (int i = 0; i < m_graph.size() && !quit; ++i) {
		quit = true;
		for (auto& edge : m_graph){
			if (m_result[edge.Start] != INT_MAX && m_result[edge.Start] + edge.Weight < m_result[edge.Close]) {
				m_result[edge.Close] = m_result[edge.Start] + edge.Weight;
				m_parents[edge.Close] = edge.Start;
				m_complexity++;
				quit = false;
			}
		}
	}
}
}