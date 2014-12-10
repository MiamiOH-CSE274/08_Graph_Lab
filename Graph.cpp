/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */
#include "Graph.h"
#include <iostream>

Graph::Graph(unsigned int numVertices){

}

/*
double Graph::getCost(int vert1, int vert2){
	for (unsigned int x = 0; x < adjList[vert1].edgeList.size; x++){
		if (adjList[vert1].edgeList[x].dest == vert2){
			return adjList[vert1].edgeList[x].cost;
		}
	}
  return -1.0;
}

*/
//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.

/*
void Graph::addEdge(int vert1, int vert2, double cost){
	if (cost < 0){
		throw std::string("Negative cost is not allowed");
	}
	for (unsigned int x = 0; x < adjList[vert1].edgeList.size; x++){
		if (adjList[vert1].edgeList[x].dest == vert2){
			adjList[vert1].edgeList[x] = Edge(cost, vert2);
		}
	}
	for (unsigned int x = 0; x < adjList[vert2].edgeList.size; x++){
		if (adjList[vert2].edgeList[x].dest == vert1){
			adjList[vert2].edgeList[x] = Edge(cost, vert1);
		}
	}
}

*/

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.

/*
void Graph::removeEdge(int vert1, int vert2){
	for (unsigned int x = 0; x < adjList[vert1].edgeList.size; x++){
		if (adjList[vert1].edgeList[x].dest == vert2){
			adjList[vert1].edgeList[x] = Edge();
		}
	}
	for (unsigned int x = 0; x < adjList[vert2].edgeList.size; x++){
		if (adjList[vert2].edgeList[x].dest == vert1){
			adjList[vert2].edgeList[x] = Edge();
		}
	}
}
*/

/*
void Graph::printEdges(unsigned int numVertices){
	for (unsigned int x = 0; x < numVertices; x++){
		std::cout << "Vertex " << x << " has " << adjList[x].edgeList.size << " edges." << "\n";
	}

	for (unsigned int x = 0; x < numVertices; x++){
		listEdges(adjList[x].edgeList);
	}

	
}
*/

/*
void Graph::listEdges(std::vector<Edge> edgeList){
	for (unsigned int x = 0; x < edgeList.size; x++){
		std::cout << "Destination node is " << edgeList[x].dest << "\n";
	}
}
*/