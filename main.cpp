/*****
* Author   : Chris Mabe
* Date     : 2014-11-18
* Sources  : Headers - Dr. Brinkman, Inside of methods - Chris Mabe
*
* This project is all about graphs, edges, and nodes. It tests our
* knowledge of adding/removing nodes and calculating edge costs.
*/

#include "Graph.h"
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

int main(){
  testGraph();

  return 0;
}
