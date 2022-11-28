#include "Graph.h"
#include <string>
#include <algorithm>

namespace Graph
{
Graph::Graph(std::string fileName) : Input::FileInput(fileName)
{

}

void Graph::Input(){
	FileInput::Input();

	std::string weight;
	Edge temp;
	while (!m_file.eof()) {
		m_file >> temp.Start >> temp.Close >> weight;
		temp.Weight = KeyboardInput::StringIsDigit(weight) ? std::stoi(weight) : INT_MAX;
		m_graph.push_back(temp);
	}
}

int Graph::FindVertexCount() {
	m_vertexCount = 0;
	std::vector<int> vertexes;
	for (const auto& edge : m_graph) {
		if (std::find(vertexes.begin(), vertexes.end(), edge.Start) == vertexes.end())
			vertexes.push_back(edge.Start);

		if (std::find(vertexes.begin(), vertexes.end(), edge.Close) == vertexes.end())
			vertexes.push_back(edge.Close);
	}

	m_vertexCount = vertexes.size();
	return m_vertexCount;
}

void Graph::EdgesToMatrix() {
	auto comparator = [&](Edge& a, Edge& b) { if(a.Start == b.Start) return a.Close < b.Close;
																	 else return a.Start < b.Start;};
	std::sort(m_graph.begin(), m_graph.end(), comparator);

	if (m_vertexCount == 0)
		FindVertexCount();

	m_matrixGraph = std::vector< std::vector<int>>(m_vertexCount, std::vector<int>(m_vertexCount, INT_MAX));
	for (auto& edge : m_graph) {
		m_matrixGraph[edge.Start][edge.Close] = edge.Weight;
	}

	for (int i = 0; i < m_matrixGraph.size(); i++) {
		for (int j = 0; j < m_matrixGraph.size(); j++) {
			if (m_matrixGraph[i][j] == INT_MAX && i != j) {
				m_matrixGraph[i][j] = -INT_MAX;
			}
		}
	}
}
}