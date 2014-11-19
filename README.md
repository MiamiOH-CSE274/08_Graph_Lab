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

1. add - SUCCESS - Checks node1 adjList to see if an edge exists, taking a maximum of O(m) with m being the edges connected to node1.  If it doesn't exist, it skips ahead and adds the edge in constant time.  If edge does exist, does the same for node2 at O(m) for that adjList.
2. remove - SUCCESS - This has a very specific maximum running time. We need to go through both node's adjList searching for the other node (even if it doesn't exist), and then remove them from the list in constant time.  I believe it is O(m + n) with m and n as length of adjList for each respective node.
3. getCost - SUCCESS - getCost runs in the O(n) time, with n being the number of edges from node1.  We go through the adjList until we find the proper node2, and then return the cost, no need to check node2's m number of edges.

#### 2. For each of your methods, what is the worst-case running time? You may write your answer in terms of `n` (the number of vertices), `m` (the number of edges), `d` (the maximum degree of any node in the graph), or any combination of these. Try to give the most informative bound that you can.

*
**
*** I combined running times with my brief Responses above ***
**
*


#### 3. Exercise 12.1 from http://opendatastructures.org/ods-cpp/12_4_Discussion_Exercises.html. You may want to draw by hand, upload the picture online (Instagram, Twitter, imgur, or some place like that), and then just put a link here.

...	0 |	1 |	2 |	3 |	4 |	5 |	6 |	7 |	8 |	9
------------------------------------------
0 | 0 | 0 | 1 | 1 | 0 | 1 | 0 | 0 | 0 | 0
1 | 0 | 0 | 0 | 1 | 1 | 0 | 1 | 0 | 0 | 0
2 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 1 | 0 | 0
3 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0
4 | 0 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1
5 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 1
6 | 0 | 1 | 0 | 0 | 0 | 1 | 0 | 1 | 0 | 0
7 | 0 | 0 | 1 | 0 | 0 | 0 | 1 | 0 | 1 | 0
8 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 1 | 0 | 1 
9 | 0 | 0 | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 0

0 - 2, 3, 5
1 - 3, 4, 6
2 - 0, 4, 7
3 - 0, 1, 8
4 - 1, 2, 9
5 - 0, 6, 9
6 - 1, 5, 7
7 - 2, 6, 8
8 - 3, 7, 9
9 - 4, 5, 8

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Why was my compiler complaining about the position of the #include statements at the beginning? I had to do a fair amount of switiching to make it work like I wanted.