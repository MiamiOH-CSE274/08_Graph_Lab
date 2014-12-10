/*****
 * Author   : Chris Mabe
 * Date     : 2014-11-18
 * Sources  : Headers - Dr. Brinkman, Inside of methods - Chris Mabe
 */
#include "Graph.h"

Graph::Graph(unsigned int numNodes){
	adjList.resize(numNodes);
}

double Graph::getCost(int node1, int node2){
	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++) {
		if (adjList[node1].edgeList[i].dest == node2) {
			return adjList[node1].edgeList[i].cost;
		}
	}

  return -1;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
	// ERROR CHECKING
	if (cost < 0){
		throw std::string("Error: The cost cannot be lower than 0");
	}
	if (node1 < 0 || node1 > adjList.size()){
		throw std::string("Node 1 was either below 0 or too big");
	}
	if (node2 < 0 || node1 > adjList.size()){
		throw std::string("Node 2 was either below 0 or too big");
	}

	// ADDING
	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++) {
		if (adjList[node1].edgeList[i].dest == node2) {
			adjList[node1].edgeList[i].cost == cost;
			for (unsigned int x = 0; x < adjList[node2].edgeList.size(); x++){
				if (adjList[node2].edgeList[x].dest == node1){
					adjList[node2].edgeList[x].cost = cost;
				}
				return;
			}
		}
	}

	adjList[node1].edgeList.push_back(Edge(cost, node2));
	adjList[node2].edgeList.push_back(Edge(cost, node1));

}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
	if (node1 < 0 || node1 > adjList.size()){
		throw std::string("Node 1 was either below 0 or too big");
	}
	if (node2 < 0 || node1 > adjList.size()){
		throw std::string("Node 2 was either below 0 or too big");
	}

	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++) {
		if (adjList[node1].edgeList[i].dest == node2) {
			adjList[node1].edgeList.erase(adjList[node1].edgeList.begin() + i);

			for (unsigned int x = 0; x < adjList[node1].edgeList.size(); x++) {
				if (adjList[node2].edgeList[x].dest == node1) {
					adjList[node2].edgeList.erase(adjList[node2].edgeList.begin() + x);
				}
			}
		}
	}

}
