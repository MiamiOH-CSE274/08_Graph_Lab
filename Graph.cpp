/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */
#include "Graph.h"
#include <list>
#include <stack>

Graph::Graph(unsigned int numNodes){
	adjList.resize(numNodes);
}

double Graph::getCost(int node1, int node2){
	
	int size = adjList.size(); //if a negative number is entered the function will return -1.0;
	if(node1 < size){
		for(unsigned int i = 0; i < adjList[node1].edgeList.size(); i++){
			if(adjList[node1].edgeList[i].dest == node2){
				return adjList[node1].edgeList[i].cost;
			}
		}	 
	}
	return -1.0;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
	
	if(cost < 0){ //Throws string if given invalid cost
		throw std::string("the cost is not valid");
	}
	

	int size = adjList.size();

	//program crashes if an invalid node is entered, so I created a throw::string exception
	if(node1 < 0 || node1 >= size){ // throws string if given invalid node
		throw std::string("node1 is not valid");
	}
	if(node2 < 0 || node2 >= size){
		throw std::string("node2 is not valid");
	}
	

	//if edge already exists, update cost
	for(unsigned int i = 0; i < adjList[node1].edgeList.size(); i ++){
		if(adjList[node1].edgeList[i].dest == node2){
			adjList[node1].edgeList[i].cost = cost;
		}
	}
	for(unsigned int i = 0; i < adjList[node2].edgeList.size(); i++){
		if(adjList[node2].edgeList[i].dest == node1){
			adjList[node2].edgeList[i].cost = cost;
			return; // exits function so that the pushback function doesn't occur if the edge already exists
		}
	}
	
	//add node1 and node2 to eachother's edgeList
	adjList[node1].edgeList.push_back(Edge(cost, node2));
	adjList[node2].edgeList.push_back(Edge(cost, node1));
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){

	//no need for 
	
	
	for(unsigned int i = 0; i < adjList[node1].edgeList.size(); i++){		
		if(adjList[node1].edgeList[i].dest == node2){
			//erase edge for node2 in node1's edgelist
			adjList[node1].edgeList.erase(adjList[node1].edgeList.begin() + i);
		
			//then erase edge for node1 in node2's edgelist
			for(unsigned int j = 0; j < adjList[node2].edgeList.size(); j++){
				if(adjList[node2].edgeList[j].dest == node1){
					adjList[node2].edgeList.erase(adjList[node2].edgeList.begin() + j);
				}
			}	
		}
	}
}




bool Graph::dfs(int node1, int node2) {
 
	std::list<int> openList;
	bool *closedList = new bool[adjList.size()];

	openList.push_back(node1);

	while(openList.size() > 0){
		for (unsigned int i = 0; i < adjList[openList.front()].edgeList.size(); i++){
			
			if(adjList[openList.front()].edgeList[i].dest == node2){
				return true;
			}
			
			else if(closedList[adjList[openList.front()].edgeList[i].dest] == false){
				openList.push_back((adjList[openList.front()].edgeList[i].dest));
			}
			
		}
		int index = openList.front();
		closedList[index] = true;
		openList.pop_front();
	}
	
	delete[] closedList;

	return false;
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*bool *seen = new bool[adjList.size()];
  
	std::list<Node> q;
  
	q.push_back(adjList[node1]);
  
	seen[node1] = true;
  
	while (q.size() > 0) {
		
		 std::stack<int> edges;
		 
		 for (int i = 0; i < adjList[node1].edgeList.size(); i++) {
			 int index = adjList[node1].edgeList[i].dest;

			
			 
			 if (!seen[index]) {
				q.push_back(j);
				seen[j] = true;
			}

			if(index == node2) return true;
			else{
				return 
			}
		
		
			
			
			
			int i = q.pop_front()
      }
    }
  }
  delete[] seen;
  */
}
