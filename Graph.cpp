/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */
#include "Graph.h"

Graph::Graph(unsigned int numNodes){
	adjList = std::vector<Node>(numNodes);
}

int Graph::getCost(int node1, int node2){
<<<<<<< HEAD
	for(int i = 0; i < adjList.at(node1); 
	if(adjList.at(node1) == adjList.at(node2)){

	}
=======
	std::vector<Edge> one = (adjList.at(node1)).edgeList;

	for (int i = 0; i < one.size(); i++){
		Edge edge1 = one.at(i);
		if (edge1.dest == node2){
			return edge1.cost;
		}
	}

>>>>>>> a278a10e643d3179b1ba75069ce9aebd1ca90399
  return -1;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
<<<<<<< HEAD
	
=======
	if (cost < 0){
		throw std::string("Can't have a cost less than 0");
	}

	Edge one = Edge(cost, node2);
	Edge two = Edge(cost, node1);

	(adjList.at(node1).edgeList).push_back(one);
	(adjList.at(node2).edgeList).push_back(two);
>>>>>>> a278a10e643d3179b1ba75069ce9aebd1ca90399
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
<<<<<<< HEAD
  //TODO
=======
	std::vector<Edge> one = (adjList.at(node1)).edgeList;

	for (int i = 0; i < one.size(); i++){
		Edge edge1 = one.at(i);
		if (edge1.dest == node2){
			one.erase(one.begin()+i);
		}
	}
>>>>>>> a278a10e643d3179b1ba75069ce9aebd1ca90399
}