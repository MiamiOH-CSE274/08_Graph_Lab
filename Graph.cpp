/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */


// A very tired Sam Hausfeld with quite a bit of help...will come back to this during the weekend.
#include "Graph.h"
#include <string>
#include <algorithm>

Graph::Graph(unsigned int numNodes) : adjList(numNodes){
  //TODO, OR NAH
}

double Graph::getCost(int node1, int node2){
	auto iter = std::find_if(std::begin(adjList[node1].edgeList),
							 std::end(adjList[node1].edgeList),
							 [&](const Edge edge) {
								return edge.dest == node2;
							 });
	if (iter == std::end(adjList[node1].edgeList)) {
		return -1.0;
	}
	return (*iter).cost;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
	if (cost < 0) {
		throw std::string("Cost is too small!");
	}
	Edge edge1(cost, node2);
	Edge edge2(cost, node1);

	adjList[node1].edgeList.push_back(edge1);
	adjList[node2].edgeList.push_back(edge2);
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
	auto iter = std::find_if(std::begin(adjList[node1].edgeList),
							std::end(adjList[node1].edgeList),
							[&](const Edge edge) {
								return edge.dest == node2;
							});
	if (iter == std::end(adjList[node1].edgeList)) {
		return;
	}

	adjList[node1].edgeList.erase(iter);

	// once more for the folks back home
	iter = std::find_if(std::begin(adjList[node2].edgeList),
						std::end(adjList[node2].edgeList),
						[&](const Edge edge) {
							return edge.dest == node1;
	});

	adjList[node2].edgeList.erase(iter);
	
}
