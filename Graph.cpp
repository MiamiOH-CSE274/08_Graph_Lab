/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */
#include "Graph.h"

#include <string>
#include <algorithm>
#include <array>
#include <queue>
#include <iostream>

Graph::Graph(unsigned int numNodes) : adjList(numNodes)
{
}

double Graph::getCost(int node1, int node2)
{
	auto iterator = std::find_if(std::begin(adjList[node1].edgeList),
				     std::end(adjList[node1].edgeList),
				     [&] (const Edge &edge) {
					     return edge.dest == node2;
				     });

	if (iterator == std::end(adjList[node1].edgeList)) {
		// no edge from node1 to node2
		return -1.0;
	}

	return (*iterator).cost;
}

// Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost)
{
	if (cost < 0) {
		throw std::string("error: cost is < 0");
	}
	
	if (getCost(node1, node2) == -1.0) {
		// no edge exists yet, add them
		
		Edge edge1(cost, node2);
		Edge edge2(cost, node1);

		adjList[node1].edgeList.push_back(edge1);
		adjList[node2].edgeList.push_back(edge2);
	} else {
		// this edge already exists, just update its value
		
		auto iterator = std::find_if(std::begin(adjList[node1].edgeList),
					     std::end(adjList[node1].edgeList),
					     [&] (const Edge &edge) {
					             return edge.dest == node2;
					     });
					     
		iterator->dest = node2;
		
		iterator = std::find_if(std::begin(adjList[node2].edgeList),
					     std::end(adjList[node2].edgeList),
					     [&] (const Edge &edge) {
					             return edge.dest == node1;
					     });
					     
		iterator->dest = node1;
	}
}

// Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2)
{
	auto iterator = std::find_if(std::begin(adjList[node1].edgeList),
				     std::end(adjList[node1].edgeList),
				     [&] (const Edge &edge) {
					     return edge.dest == node2;
				     });

	if (iterator == std::end(adjList[node1].edgeList)) {
		// there is no edge from node1 to node2
		return;
	}

	adjList[node1].edgeList.erase(iterator);

	iterator = std::find_if(std::begin(adjList[node2].edgeList),
				std::end(adjList[node2].edgeList),
				[&] (const Edge &edge) {
					return edge.dest == node1;
				});

	// we dont need to make sure this iterator is valid because we know
	// it will be
	adjList[node2].edgeList.erase(iterator);
}

std::vector<Edge> Graph::neighbors(int node)
{
	return adjList[node].edgeList;
}

std::vector<double> Graph::dijkstra(int source)
{
	// stores the distance from source to each node
	std::vector<double> distances(adjList.size());

	// stores which nodes have been looked at
	std::vector<bool> visited_nodes(adjList.size());

	// stores the pervious node of each node in the optimal path
	std::vector<int> prev_node(adjList.size());

	// the compare function for the priority queue, the nodes are
	// added to the queue along with there distance from the source
	// and should be sorted by that distance
	auto compare = [&] (std::pair<int, double> &n1,
			    std::pair<int, double> &n2) {
		if (n1.second == -1) {
			return false;
		}

		if (n2.second == -1) {
			return true;
		}
		
		return n1.second < n2.second;
	};

	std::vector< std::pair<int, double> > node_queue(adjList.size());

	// initialize distance to every node to infitity (-1 in this case
	// since negative edge lengths arent used in this graph.  add add every
	// node to the queue of nodes
	for (unsigned int i = 0; i < adjList.size(); i++) {
		// the distance to the source item should be 0
		if (i == source) {
			distances[i] = 0;
		} else {
			distances[i] = -1;
			prev_node[i] = -1;
		}
		
		node_queue[i] = (std::make_pair(i, distances[i]));
		visited_nodes[i] = false;
	}

	// std::priority_queue does not have the ability to decrease the priority
	// of an item, so we will use a simple array for this and just make it a heap
	std::sort(node_queue.begin(), node_queue.end(), compare);

	while (node_queue.size() != 0) {
		// get the item in node_queue with the smallest distance

		std::pair<int, double> node_pair = node_queue.front();
		node_queue.erase(node_queue.begin());
		int node1 = node_pair.first;
		double dist = node_pair.second;

		// mark this node as visited
		visited_nodes[node1] = true;

		// loop through every neighbor of this node
		for (auto &edge : neighbors(node1)) {
			int node2 = edge.dest;
			
			// only look at this neighbor if it hasnt been looked at yet
			if (visited_nodes[node2] == false) {
				double temp_dist = distances[node1] + edge.cost;

				// if this distance is smaller than our current best guess, update it
				if (temp_dist < distances[node2] || distances[node2] < 0) {
					distances[node2] = temp_dist;
					prev_node[node2] = node1;

					auto it = std::find_if(node_queue.begin(),
							       node_queue.end(),
							       [&] (const std::pair<int, double> &n) {
								       return n.first == node2;
							       });

					// update the priority for this node, this check of < 0 must
					// be done because -1 is used to represent a priority of infinity
					if (it->second < 0) {
						it->second = temp_dist;
					} else {
						it->second -= temp_dist;
					}

					// make sure the node_queue vector continues to act like a queue
					std::sort(node_queue.begin(), node_queue.end(), compare);
				}
			}
		}
	}
	
	return distances;
}

double Graph::distance(int source, int dest)
{
	return dijkstra(source)[dest];
}
