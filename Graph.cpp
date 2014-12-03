/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */


//  Round 2
#include "Graph.h"
#include <string>
#include <algorithm>


Graph::Graph(unsigned int numNodes) : adjList(numNodes){
	adjList.resize(numNodes);
	this->V = numNodes;
}


double Graph::getCost(int node1, int node2){
	//// Original Way:
	//auto iter = std::find_if(std::begin(adjList[node1].edgeList),
	//						 std::end(adjList[node1].edgeList),
	//						 [&](const Edge edge) {
	//							return edge.dest == node2;
	//						 });
	//if (iter == std::end(adjList[node1].edgeList)) {
	//	return -1.0;
	//}
	//return (*iter).cost;
	
	// Being careful
	

	for (int i = 0; i < adjList[node1].edgeList.size();i++) {
		if (adjList[node1].edgeList[i].dest == node2)
			return adjList[node1].edgeList[i].cost;
	}
	// didn't find it?
	return -1.0;

}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
// IF the edge already exists, update the cost
void Graph::addEdge(int node1, int node2, double cost){
	//if (cost < 0) {
	//	throw std::string("Cost is too small!");
	//}
	//Edge edge1(cost, node2);
	//Edge edge2(cost, node1);
	//adjList[node1].edgeList.push_back(edge1);
	//adjList[node2].edgeList.push_back(edge2);

	if (node1 >= adjList.size() || node2 >= adjList.size()) throw std::string("Bad node, can't add");

	if (cost < 0) throw std::string("Can't have add something with a negative cost!");

	// find the edge if it exists
	for (int i = 0; i < adjList[node1].edgeList.size(); i++) {
		if (adjList[node1].edgeList[i].dest == node2) {
			//found it
			adjList[node1].edgeList[i].cost = cost;
			adjList[node2].edgeList[node1].cost = cost;
								  //^ can I do this?
		} // end if
	} // end for

	adjList[node1].edgeList.push_back(Edge(cost, node2));
	adjList[node2].edgeList.push_back(Edge(cost, node1));

}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
	//auto iter = std::find_if(std::begin(adjList[node1].edgeList),
	//						std::end(adjList[node1].edgeList),
	//						[&](const Edge edge) {
	//							return edge.dest == node2;
	//						});
	//if (iter == std::end(adjList[node1].edgeList)) {
	//	return;
	//}
	//adjList[node1].edgeList.erase(iter);
	//// once more for the folks back home
	//iter = std::find_if(std::begin(adjList[node2].edgeList),
	//					std::end(adjList[node2].edgeList),
	//					[&](const Edge edge) {
	//						return edge.dest == node1;
	//});
	//adjList[node2].edgeList.erase(iter);

	if (node1 >= adjList.size() || node2 >= adjList.size()) throw std::string("Bad node, can't remove.");

	for (int i = 0; i < adjList[node1].edgeList.size(); i++){
		// find it
		if (adjList[node1].edgeList[i].dest == node2) {
			// delete it
			// but delete it where? use begin + i
			adjList[node1].edgeList.erase(adjList[node1].edgeList.begin() + i);
			
			// now you we have to find and delete the other one

			for (int j = 0; j < adjList[node2].edgeList.size(); j++){
				if (adjList[node2].edgeList[j].dest == node1)
					adjList[node2].edgeList.erase(adjList[node2].edgeList.begin() + j);
			}
		}


	}
}
// A simple Breadth-First Search for the portfolio
void Graph::BFS(int x) {
	bool *closedList = new bool[V];
	for (int i = 0; i < V; i++) // make the closed list and mark not visited
		closedList[i] = false;

	std::vector<int> queue; // make the open list, queue, thing??

	// Start with the current node, mark it closed and put in the queue/
	closedList[x] = true;
	queue.push_back(x);

	std::vector<int>::iterator iter; // make an iterator...I wish I understood this fully

	// Empty the queue.
	while (!queue.empty()) {
		// Dequeue a vertex
		x = queue.front();
		std::cout << x << " " << std::endl;

		// Find the neighbors / neighbors of neighbors etc.
		//for (iter = adjList[x].edgeList.begin(); iter != adjList[x].edgeList.end(); ++iter){ // is there a reason we use ++i?
		for (iter = adj[x].begin(); iter != adj[x].end(); ++iter) {
			if (closedList[*iter] == false){
				closedList[*iter] = true;
				queue.push_back(*iter);
			} // end if
		} // end for
	} // end while

}

