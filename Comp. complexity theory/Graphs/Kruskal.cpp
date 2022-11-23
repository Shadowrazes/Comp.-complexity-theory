#include "Kruskal.h"
#include <algorithm>
#include <cmath>
#include <iomanip>

namespace Graph
{
Kruskal::Kruskal(std::string fileName) : Graph(fileName) {

}

void Kruskal::Input() {
	Graph::Input();
}

void Kruskal::Output() {
	int weight = 0;
	for (const auto& edge : m_spanningTree) {
		std::cout << edge.Start << " " << edge.Close << std::endl;
		weight += edge.Weight;
	}
	std::cout << "\nWeight: " << weight << std::endl;
	std::cout << "\nComplexity: " << m_complexity << std::endl;
}

void Kruskal::Calculate() {
	auto comparator = [&](Edge& a, Edge& b) {return a.Weight < b.Weight; };
	std::sort(m_graph.begin(), m_graph.end(), comparator);
	m_complexity += m_graph.size() * static_cast<int>(log2f(m_graph.size()));

	bool firstAdded = false;
	for (const auto& edge : m_graph) {
		if (!firstAdded) {
			m_spanningTree.push_back(edge);
			firstAdded = true;
			continue;
		}

		auto first = std::find_if(m_spanningTree.begin(), m_spanningTree.end(),
			[&](const Edge& elem) {return  edge.Start == elem.Start || edge.Start == elem.Close; });

		auto second = std::find_if(m_spanningTree.begin(), m_spanningTree.end(),
			[&](const Edge& elem) {return edge.Close == elem.Start || edge.Close == elem.Close; });

		if (first == m_spanningTree.end() && second != m_spanningTree.end() ||
			first != m_spanningTree.end() && second == m_spanningTree.end()) {
			m_spanningTree.push_back(edge);
			m_complexity++;
		}
		m_complexity++;
	}
}
}