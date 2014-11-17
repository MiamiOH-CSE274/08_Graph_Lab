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

1. add - Add works well, as it is compromised of two parts. Firstly, if an edge to be added is already contained within the edge list, it is overwritten with the new cost. The other part 
	of the function adds in the edge as if it were not previously there before. This takes constant time because it is just accessing vector elements.
2. remove - Remove works, and uses some of the logic used in getCost in that each node is iterated through their respective edges to find the correct edge, and then that edge is erased. If
	no edge is found that matches the requirements, nothing happens as the function is of type void.
3. getCost - Get cost works, as it traverses through the edge list each element has to see if the node to be paired with is contained within. If no egde is shared between the nodes,
	then a value of -1 is returned. 

#### 2. For each of your methods, what is the worst-case running time? You may write your answer in terms of `n` (the number of vertices), `m` (the number of edges), `d` (the maximum degree of any node in the graph), or any combination of these. Try to give the most informative bound that you can.

1. add - Add will always take 0(1) time because it is directly accessing the vector through the vector functions provided by the cpp library.
2. remove - Remove will take 0(d) time, where d is some constant, being that no node has more than d neighbors. 
3. getCost - This will take 0(m) timne because this function has to loop through the number of edges a node has to find the correct edge and then delete it. If the edge is the last on the
	list, it will be the worst case scenario.


#### 3. Exercise 12.1 from http://opendatastructures.org/ods-cpp/12_4_Discussion_Exercises.html. You may want to draw by hand, upload the picture online (Instagram, Twitter, imgur, or some place like that), and then just put a link here.

	http://imgur.com/f9SFeWR

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Understanding vectors and how to use their functions as defined by the cpp library was a little tough in the beginning, but essential to complete the lab.