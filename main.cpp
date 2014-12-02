#include "Graph.h"
#include <iostream>
#include <string>

void testGraph(){
	Graph g(10);
	g.addEdge(0, 1, 50);
	if (g.getCost(1, 0) != 50 || g.getCost(0, 1) != 50){
		std::cout << "ERROR: Expected edge cost of 50, got " << g.getCost(1, 0) << std::endl;
		exit(1);
	}
	else {
		std::cout << "SUCCESS: Got the right edge cost" << std::endl;
	}

	if (g.getCost(2, 3) != -1){
		std::cout << "ERROR: Expected edge cost of -1, got " << g.getCost(2, 3) << std::endl;
		exit(1);
	}
	else {
		std::cout << "SUCCESS: Got the right edge cost for non-existent edge" << std::endl;
	}

	g.removeEdge(1, 0);
	if (g.getCost(0, 1) != -1 || g.getCost(1, 0) != -1){
		std::cout << "ERROR: Expected edge cost of -1, got " << g.getCost(1, 0) << std::endl;
		exit(1);
	}
	else {
		std::cout << "SUCCESS: Got the right edge cost for removed edge" << std::endl;
	}

}

int main(){
	testGraph();
	Graph testGraph(6);
	testGraph.addEdge(0, 5, 1);
	testGraph.addEdge(5, 2, 1);
	testGraph.addEdge(2, 3, 1);
	testGraph.addEdge(3, 4, 1);
	testGraph.addEdge(4, 1, 1);
	testGraph.addEdge(1, 0, 1);
	testGraph.addEdge(5, 4, 1);
	
	try{
		testGraph.DFS(6);
	}catch(std::string e){
		std::cout << "Caught exception: " << e << std::endl;
	}
	
	std::cout << "DFS graph traversal: ";
	testGraph.DFS(2);

	return 0;
}
