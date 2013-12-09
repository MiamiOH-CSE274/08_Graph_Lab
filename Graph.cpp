/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */
#include "Graph.h"
/*
* The methods and logic in this lab were derived from class lecture,
* the textbook, and with liberal use of the vector reference page at http://www.cplusplus.com/reference/vector/vector/.
* I didn't know how vectors worked at all, so the reference page was
* an invaluable resource to me.
*/
Graph::Graph(unsigned int numNodes){
  adjList.resize(numNodes);
  for (int i = 0; i < adjList.size(); i++) {
	  adjList[i].edgeList.resize(numNodes);
  }
}

int Graph::getCost(int node1, int node2){
  // Iterate through the edgeList until we find the edge that leads to node2,
  // then return the cost of that edge
	for (int i = 0; i < adjList[node1].edgeList.size(); i++) {
	  if (adjList[node1].edgeList[i].dest == node2) {
		  return adjList[node1].edgeList[i].cost;
	  }
  }

  // If no such edge is found, -1 is returned
  return -1;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
  if (cost < 0) {
	  throw (std::string) "Cost can't be negative";
  }

  Edge* newEdge = new Edge(cost, node2);  // Make a new Edge for the adjList/edgeList
  adjList[node1].edgeList.push_back(*newEdge);  // Add it to the adjList/edgeList
  newEdge = new Edge(cost, node1);  // Same as before
  adjList[node2].edgeList.push_back(*newEdge);
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
  // Iterate through the edgeList at node1, until reaching an edge to node2.
  // If such an edge is found, remove it.
  for (int i = 0; i < adjList[node1].edgeList.size(); i++) {
	  if (adjList[node1].edgeList[i].dest == node2) {
		  adjList[node1].edgeList[i].cost = -1;
	  }
  }

  for (int i = 0; i < adjList[node2].edgeList.size(); i++) {
	  if (adjList[node2].edgeList[i].dest == node1) {
		  adjList[node2].edgeList[i].cost = -1;
	  }
  }

}
