/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */
#include "Graph.h"

Graph::Graph(unsigned int numNodes){
	adjList.resize(numNodes);
}

int Graph::getCost(int node1, int node2){
	int retCost = -1;

	int edgeListSize = adjList.at(node1).edgeList.size();
	int edgeListSize2 = adjList.at(node2).edgeList.size();

	if(edgeListSize > adjList.size() || edgeListSize2 > adjList.size()){
		throw std::string("Edge Lists cannot have more items than nodes in the graph!");
	}

	for(int i = 0; i < edgeListSize2; i++){
		Edge edgeElement = adjList.at(node1).edgeList.at(i);
		if(edgeElement.dest == node2)
			retCost = edgeElement.cost;
	}
	return retCost;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
	
	int edgeListSize1 = adjList.at(node1).edgeList.size();
	int edgeListSize2 = adjList.at(node2).edgeList.size();

	if(cost < 0)
		throw std::string("Cost cannot be less than zero");
	
	Edge j;
	j.cost = cost;
	j.dest = node2;
	Edge k;
	k.cost = cost;
	k.dest = node1;
	

	if(getCost(node1, node2) != 0){
		for(unsigned int i = 0; i < edgeListSize1; i++){
			if(adjList.at(node1).edgeList.at(i).dest == node2)
				adjList.at(node1).edgeList.at(i).cost = cost;
		}
		for(unsigned int i = 0; i < edgeListSize2; i++){
			if(adjList.at(node2).edgeList.at(i).dest == node1)
				adjList.at(node2).edgeList.at(i).cost = cost;
		}
	}

	adjList.at(node1).edgeList.push_back(j);
	adjList.at(node2).edgeList.push_back(k);
	
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
	if(adjList.size() < 1)
		throw std::string("No items to remove!");
	
	int edgeListSize1 = adjList.at(node1).edgeList.size();
	int edgeListSize2 = adjList.at(node2).edgeList.size();
	
	if(edgeListSize1 > adjList.size() || edgeListSize2 > adjList.size()){
		throw std::string("Edge Lists cannot have more items than nodes in the graph!");
	}

	for(unsigned int i = 0; i < edgeListSize1; i++){
		Edge edgeElement = adjList.at(node1).edgeList.at(i);
		if(edgeElement.dest == node2)
			adjList.at(node1).edgeList.erase(adjList.at(node1).edgeList.begin() + i);
	}

	for(int i = 0; i < edgeListSize2; i++){
		Edge edgeElement = adjList.at(node2).edgeList.at(i);
		if(edgeElement.dest == node1)
			adjList.at(node2).edgeList.erase(adjList.at(node2).edgeList.begin() + i);
	}
	
}

void Graph::dfs(int node){
	std::vector<Edge> closedList;
	std::vector<Edge> openList;
	int edgeListSize = adjList.at(node).edgeList.size();

	// initialize open list with destinations of the first node.
	for(int i = 0; i < edgeListSize; i++){
		Edge toAdd = adjList.at(node).edgeList.at(i);
		openList.push_back(toAdd);
	}

	// take first node, put in closed list, slowly empty open list
	while(openList.size() != 0){
		// add the last element of the open list to closed list
		closedList.push_back(openList.back());
		openList.pop_back();
		
		// see if the node in the closed list has any new neighbors
		int lastIndex = closedList.size() - 1;
		int edgeListSize = adjList.at(lastIndex).edgeList.size();
		for(int i = 0; i < edgeListSize; i++){
			for(int i = 0; i < openList.size(); i++){
				Edge inClosedList = adjList.at(lastIndex).edgeList.at(i);
				Edge inOpenList = openList.at(i);
				if(inClosedList.dest != inOpenList.dest && inClosedList.cost != inOpenList.cost)
					openList.push_back(inClosedList);
			}
		}
	}
}
