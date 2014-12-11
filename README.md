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

1. add - Yes, it works. This method adds an edge to the edge lists of the two nodes being passed to it. The new edge has a cost of the passed int value. If the edge already exists, it updates the cost.
2. remove - My remove method works. If the edge doesn't exist we do nothing. If it does, we erase the edge from the edge lists of both nodes with said edge.
3. getCost - Yes, this method simply returns the cost of the edge in question if it exists. If it doesn't exist, return -1.0.

#### 2. For each of your methods, what is the worst-case running time? You may write your answer in terms of `n` (the number of vertices), `m` (the number of edges), `d` (the maximum degree of any node in the graph), or any combination of these. Try to give the most informative bound that you can.

1. add - The worst case we could get happens when the edge already exists, at the end of each of the two nodes' edge lists. This would mean the add method must iterate through each edge in two nodes' edge lists. This would mean we have O(d) twice, or O(2d), in the worst case, and therefore our worst running time is O(d).
2. remove - Just like in the add method, our worst case in remove is that we must iterate through each of the two passed nodes' edge lists entirely. This means the worst running time would be O(2d) again, or O(d).
3. getCost - Again, we are simply iterating through a node's edge list. The worst case would be that we must iterate through the entirety of the longest edge list, and therefore our running time would be O(d).

#### 3. Exercise 12.1 from http://opendatastructures.org/ods-cpp/12_4_Discussion_Exercises.html. You may want to draw by hand, upload the picture online (Instagram, Twitter, imgur, or some place like that), and then just put a link here.
http://i.imgur.com/sNls3nY.jpg

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
Remove was hard at first. Honestly, in my opinion, this lab was pretty easy to understand.
