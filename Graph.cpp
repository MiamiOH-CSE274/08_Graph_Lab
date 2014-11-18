/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */
#include "Graph.h"

#include <string>
#include <algorithm>

Graph::Graph(unsigned int numNodes) : adjList(numNodes)
{
}

double Graph::getCost(int node1, int node2)
{
	auto iterator = std::find_if(std::begin(adjList[node1].edgeList),
				     std::end(adjList[node1].edgeList),
				     [&] (const Edge edge) {
					     return edge.dest == node2;
				     });

	if (iterator == std::end(adjList[node1].edgeList)) {
		// no edge from node1 to node2
		return -1.0;
	}

	return (*iterator).cost;
}

// Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost)
{
	if (cost < 0) {
		throw std::string("error: cost is < 0");
	}

	Edge edge1(cost, node2);
	Edge edge2(cost, node1);

	adjList[node1].edgeList.push_back(edge1);
	adjList[node2].edgeList.push_back(edge2);
}

// Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2)
{
	auto iterator = std::find_if(std::begin(adjList[node1].edgeList),
				     std::end(adjList[node1].edgeList),
				     [&] (const Edge edge) {
					     return edge.dest == node2;
				     });

	if (iterator == std::end(adjList[node1].edgeList)) {
		// there is no edge from node1 to node2
		return;
	}

	adjList[node1].edgeList.erase(iterator);

	iterator = std::find_if(std::begin(adjList[node2].edgeList),
				std::end(adjList[node2].edgeList),
				[&] (const Edge edge) {
					return edge.dest == node1;
				});

	// we dont need to make sure this iterator is valid because we know
	// it will be
	adjList[node2].edgeList.erase(iterator);
}
