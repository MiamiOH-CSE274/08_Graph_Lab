08_Graph_Lab
============

Implement a simple graph class

Requirements
------------

1. Implement all methods of the `Graph` class.

Reading
=======
"Open Data Structures," Chapter 12, the whole chapter. http://opendatastructures.org/ods-cpp/12_Graphs.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. add - Working! Adds an edge from node1 to node2 as well as from node2 to node1.
2. remove - Working! Removes an edge from node1 to node2 and from node2 to node1 if it that edge is found, otherwise does nothing.
3. getCost - Working! Returns the cost from a node to another node.

#### 2. For each of your methods, what is the worst-case running time? You may write your answer in terms of `n` (the number of vertices), `m` (the number of edges), `d` (the maximum degree of any node in the graph), or any combination of these. Try to give the most informative bound that you can.

1. add - O(1 + m + m) because add() accesses the node via index postion which is constant time but then must cycle through m edges of that node. The worse-case scenario would be to find the edges at the end of their respective arrays which would require cycling through all edges.
2. remove - O(1 + m + m) because you access the node via the index in the array which is constant time and then must cycle through the list of edges, once for the removing of node2 from node1 and another for removing node1 from node2.
3. getCost - O(1 + m) because you access node1 via its index in the array which is constant time and then getCost() cycles through m edges for node2.

TODO

#### 3. Exercise 12.1 from http://opendatastructures.org/ods-cpp/12_4_Discussion_Exercises.html. You may want to draw by hand, upload the picture online (Instagram, Twitter, imgur, or some place like that), and then just put a link here.

Link to the picture I drew: http://i.imgur.com/tLwnkd3.jpg

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

When erasing an edge between nodes I was forced to do "edgeList.begin() + i" instead of just "edgeList[i]". Why is that?