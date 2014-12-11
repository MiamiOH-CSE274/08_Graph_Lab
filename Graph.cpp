/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */
#include "Graph.h"
#include <stack>

Graph::Graph(unsigned int numNodes){
	adjList.resize(numNodes);
}

double Graph::getCost(int node1, int node2){
	for(unsigned int i=0; i < adjList[node1].edgeList.size(); i++)
		{
			if(adjList[node1].edgeList[i].dest == node2)
			{ return adjList[node1].edgeList[i].cost; }
		}
  return -1.0;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
  if(cost < 0)
	  throw std::string ("Cost is below 0");

  Edge* first = new Edge(cost, node2);
  Edge* second = new Edge(cost, node1);

  for(unsigned int i=0; i<adjList[node1].edgeList.size(); i++)
  {
	  if(adjList[node1].edgeList[i].dest == node2)
	  { adjList[node1].edgeList[i].cost = cost; }
  }

  for(unsigned int i=0; i<adjList[node2].edgeList.size(); i++)
  {
	  if(adjList[node2].edgeList[i].dest == node1)
	  { adjList[node2].edgeList[i].cost = cost; }
  }

  adjList[node1].edgeList.push_back(*(first));
  adjList[node2].edgeList.push_back(*(second));

}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
 
  for(unsigned int i=0; i<adjList[node1].edgeList.size(); i++)
  {
	  if(adjList[node1].edgeList[i].dest == node2)
	  { adjList[node1].edgeList[i] = Edge(); }
  }

  for(unsigned int i=0; i<adjList[node2].edgeList.size(); i++)
  {
	  if(adjList[node2].edgeList[i].dest == node1)
	  { adjList[node2].edgeList[i] = Edge(); }
  }

}

//need an open list, closed list
/*add x to open list
	compare other nodes to see if theres an edge
		add those nodes to open list (check for duplicates)*/

void Graph::DFS(int x)
{
	std::stack<int> open;
	std::vector<int> closed;

	open.push(x);
	while(!open.empty())
	{
		int currVert = open.top();
		open.pop();
		//moving from open to closed. giving it a 1 to indicate it has been visited
		closed[currVert] = 1;

		for (unsigned int i = 0; i < adjList[currVert].edgeList.size(); i++)
		{
				if (closed[adjList[currVert].edgeList[i].dest] == 0)
				{
					//deleting node from stack
					open.push(adjList[currVert].edgeList[i].dest);
					//marking in closed list as visited
					closed[adjList[currVert].edgeList[i].dest] = 1;
				}
		}
	}}