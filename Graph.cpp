/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */
#include "Graph.h"

Graph::Graph(unsigned int numNodes){

	adjList.resize(numNodes);

}

double Graph::getCost(int node1, int node2){

	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++)
		if (adjList[node1].edgeList[i].dest == node2)
			return adjList[node1].edgeList[i].cost;


  return -1.0;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
  //TODO
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
  //TODO
}
