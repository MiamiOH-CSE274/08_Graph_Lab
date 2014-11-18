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

1. add - Yes, finds node1 in the list, adds an edge to node2, then vice versa for node2. If edge already exists, update the cost.
2. remove - Yes, removes the edge between node1 and node2 and vice versa. If edge does not exist do nothing.
3. getCost - Yes, returns the cost of the edge between node1 and node2.

#### 2. For each of your methods, what is the worst-case running time? You may write your answer in terms of `n` (the number of vertices), `m` (the number of edges), `d` (the maximum degree of any node in the graph), or any combination of these. Try to give the most informative bound that you can.

1. add - There are two cases for add();

Case 1: The edge already exists - In this case first we have to loop through the edgeList of node1 in order to find the the edge from node1 to node2, which in worst case is O(d), then we update the cost of that edge, an O(1) operation, totalling O(d) still for the operation thus far, then we do the same for node 2, which is also O(d) in the worst-case, giving the total operation O(2d), which means this operation is O(d).

Case 2: The edge does not exist - In this case we have already looped through the edgelist for node1, so it is already O(d) in the best-case. In this case we simply call vector::push_back, which in worst case it reallocates, meaning O(n) so push_back is O(d) for in the worst case. This means case 2 is also O(d), so the worst case for add is O(d).

2. remove - Remove is very similar to add(), in that we have to loop through the edgeLists of node1 and node2 in order to find the correct edges, and we've established that the operation for doing so is O(d) in the worst case. That means we only have to look at the complexity of the erase method, which in the worst case(deleting the first element), would have to move all the elements behind it forward, which is also an O(d) operation, so the total complexity for remove() is O(d).

3. getCost - In this operation we access the edgeList for node1 with the iterator, which is O(1), then we loop through that edgeList to find the edge to node 2, which is O(d), so the total complexity for this operation is O(d).



#### 3. Exercise 12.1 from http://opendatastructures.org/ods-cpp/12_4_Discussion_Exercises.html. You may want to draw by hand, upload the picture online (Instagram, Twitter, imgur, or some place like that), and then just put a link here.

Link to my masterpiece: http://i.imgur.com/FgJazb0.jpg?1

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Read up on the vector class for methods and given variables so you can easily understand what you're actually doing, especially with things like begin() (took me a long time to figure that one out).
