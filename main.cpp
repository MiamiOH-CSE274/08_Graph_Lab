#include "Graph.h"
#include <iostream>

void testGraph(){
  Graph g(10);
  g.addEdge(0,1,50);
  g.addEdge(0,4,100);
  g.addEdge(0,2,75);
  g.addEdge(2,1,60);



  if(g.getCost(1,0) != 50 || g.getCost(0,1) != 50){
    std::cout << "ERROR: Expected edge cost of 50, got " << g.getCost(1,0) << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Got the right edge cost" << std::endl;
  }

   if(g.getCost(1,2) != 60 || g.getCost(2,1) != 60){
    std::cout << "ERROR: Expected edge cost of 60, got " << g.getCost(1,0) << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Got the right edge cost" << std::endl;
  }

   if(g.getCost(0,4) != 100 || g.getCost(4,0) != 100){
    std::cout << "ERROR: Expected edge cost of 100, got " << g.getCost(1,0) << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Got the right edge cost" << std::endl;
  }

   g.removeEdge(4,0);
   if(g.getCost(0,4) != -1){
    std::cout << "ERROR: Expected edge cost of -1, got " << g.getCost(2,3) << std::endl;
    exit(1);
   } else {
    std::cout << "SUCCESS: Got the right edge cost for removed edge" << std::endl;
   }


  if(g.getCost(2,3) != -1){
    std::cout << "ERROR: Expected edge cost of -1, got " << g.getCost(2,3) << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Got the right edge cost for non-existent edge" << std::endl;
  }

  try {
     g.addEdge(10,3, 3);
  } catch (std::string s) {
    std::cout << "SUCCESS: Caught exception: " << std::endl;
  } catch (...) {
    std::cout << "ERROR: Caught an exception, but it wasn't a string type" << std::endl;

  }

  try {
     g.addEdge(-7, 3, 3);
  } catch (std::string s) {
    std::cout << "SUCCESS: Caught exception " << std::endl;
  } catch (...) {
    std::cout << "ERROR: Caught an exception, but it wasn't a string type" << std::endl;

  }
   try {
     g.addEdge(11, 3, -3);
  } catch (std::string s) {
    std::cout << "SUCCESS: Caught exception: " << std::endl;
  } catch (...) {
    std::cout << "ERROR: Caught an exception, but it wasn't a string type" << std::endl;
  }

  try {
     g.addEdge(11, 3, -3);
  } catch (std::string s) {
    std::cout << "SUCCESS: Caught exception: " << std::endl;
  } catch (...) {
    std::cout << "ERROR: Caught an exception, but it wasn't a string type" << std::endl;
  }

  
  g.addEdge(1,3, 12);
  g.addEdge(1,3, 3);

  if(g.getCost(1,3) != 3){
    std::cout << "ERROR: Expected edge cost of 3, got " << g.getCost(1,3) << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Got the right edge cost updated edge" << std::endl;
  }
  
  g.removeEdge(1,0);
  if(g.getCost(0,1) != -1 || g.getCost(1,0) != -1){
    std::cout << "ERROR: Expected edge cost of -1, got " << g.getCost(1,0) << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Got the right edge cost for removed edge" << std::endl;
  }

  std::cout << g.dfs(0, 4) << std::endl;


}

int main(){
  testGraph();

  return 0;
}
