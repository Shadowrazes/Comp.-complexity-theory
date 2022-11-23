#include "Graph.h"
#include <string>

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
}