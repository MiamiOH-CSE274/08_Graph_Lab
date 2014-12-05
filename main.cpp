#include "Graph.h"

#include <stdlib.h>
#include <iostream>

void testGraph(){
	Graph g(10);
	g.addEdge(0,1,50);
	if(g.getCost(1,0) != 50 || g.getCost(0,1) != 50){
		std::cout << "ERROR: Expected edge cost of 50, got " << g.getCost(1,0) << std::endl;
		exit(1);
	} else {
		std::cout << "SUCCESS: Got the right edge cost" << std::endl;
	}

	if(g.getCost(2,3) != -1){
		std::cout << "ERROR: Expected edge cost of -1, got " << g.getCost(2,3) << std::endl;
		exit(1);
	} else {
		std::cout << "SUCCESS: Got the right edge cost for non-existent edge" << std::endl;
	}
  
	g.removeEdge(1,0);
	if(g.getCost(0,1) != -1 || g.getCost(1,0) != -1){
		std::cout << "ERROR: Expected edge cost of -1, got " << g.getCost(1,0) << std::endl;
		exit(1);
	} else {
		std::cout << "SUCCESS: Got the right edge cost for removed edge" << std::endl;
	}

}

void test_distance(void)
{
	Graph g(4);

	g.addEdge(0, 1, 50);
	g.addEdge(1, 2, 100);
	g.addEdge(2, 3, 200);
	
	g.addEdge(0, 2, 50);

	g.addEdge(0, 3, 1000);

	std::cout << "distancde from 0 to 3 is: " << g.distance(0, 3) << std::endl;
	std::cout << "distancde from 0 to 2 is: " << g.distance(0, 2) << std::endl;
	std::cout << "distancde from 1 to 2 is: " << g.distance(1, 2) << std::endl;
	std::cout << "distancde from 3 to 3 is: " << g.distance(3, 3) << std::endl;
}

int main(){
//  testGraph();
	
	test_distance();

	return 0;
}
