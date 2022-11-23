#include "Dijkstra.h"
#include <iomanip>

namespace Graph
{
	Dijkstra::Dijkstra(std::string fileName) : Graph(fileName) {

}

void Dijkstra::Input() {
	std::cout << "Input source vertex: ";
	std::cin >> m_source;
	Graph::Input();
	FindVertexCount();
	m_edgedGraph = std::vector<std::vector<Edge>>(m_vertexCount);
	for (auto& item : m_graph) {
		m_edgedGraph[item.Start].push_back(item);
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
	for (int i = 0; i < m_vertexCount; i++)
	{
		if (i != m_source && m_result[i] < INT_MAX)
		{
			std::cout << "Distance from source = " << m_source << " to " << i << " = " << m_result[i] << "\t Path: [";
			PrintPath(i); 
			std::cout << "]" << std::endl;
		}
	}
	std::cout << "Complexity: " << m_complexity << std::endl;
}

void Dijkstra::Calculate() {
	FindVertexCount();
	m_parents = std::vector<int>(m_vertexCount, -1);
	m_result = std::vector<int>(m_vertexCount, INT_MAX);
	m_result[m_source] = 0;

	std::vector<bool> used(m_vertexCount);
	int minDist = 0;
	int minVertex = m_source;
	while (minDist < INT_MAX){
		int i = minVertex;
		used[i] = true;

		for (auto& edge : m_edgedGraph[i]){
			if (m_result[i] + edge.Weight < m_result[edge.Close]){
				m_result[edge.Close] = m_result[i] + edge.Weight;
				m_parents[edge.Close] = i;
				m_complexity++;
			}
		}

		minDist = INT_MAX;

		for (int j = 0; j < m_vertexCount; ++j) {
			if (!used[j] && m_result[j] < minDist){
				minDist = m_result[j];
				minVertex = j;
			}
		}
	}
}
}