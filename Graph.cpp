/*****
 * Author   : Garrett Emrick
 * Date     : November 13, 2013
 * Sources  : All code is original!
 */
#include "Graph.h"
#include <iostream>

Graph::Graph(unsigned int numNodes){
  adjList = std::vector<Node>(numNodes);
  std::vector<Node>::iterator it;

  // Initialize all vectors so I don't have to worry about that extra check
  // Later
  for(it = adjList.begin(); it != adjList.end(); it++){
	(*it).edgeList = std::vector<Edge>();
  }
}

int Graph::getCost(int node1, int node2){

	/* If the EdgeList contains that edge (node2), return -1. */
	for(int i = 0; i < adjList[node1].edgeList.size(); i++){
		if(adjList[node1].edgeList[i].dest == node2)
			return adjList[node1].edgeList[i].cost;
	}
	
  return -1;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
	if(cost < 0.0) throw "Cost must be positive!";

	std::vector<Edge>::iterator it;
	int i;
	for(it = adjList[node1].edgeList.begin(); it != adjList[node1].edgeList.end(); it++, i++){
		if((*it).dest == node2){
			(*it).cost = cost;
			adjList[node2].edgeList[i].cost = cost;
		}
		if((*it).dest > node2){
			it--;
			Edge* temp = new Edge(cost, node2);
			Edge* temp2 = new Edge(cost, node1);
			adjList[node1].edgeList.insert(it, *temp);
			adjList[node2].edgeList.insert(it, *temp2);
			return;
		}

	}

	//If the node isn't contained and is max, push_back into the list.
	Edge* temp = new Edge(cost, node2);
	Edge* temp2 = new Edge(cost, node1);
	adjList[node1].edgeList.push_back(*temp);
	adjList[node2].edgeList.push_back(*temp2);

	return;

}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
  //TODO
}
