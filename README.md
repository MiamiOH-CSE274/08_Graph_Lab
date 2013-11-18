Author
==========
"Monnin, Sebastian", monninse
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

1. add - works as it shoul
2. remove - works as it should
3. getCost - works wells

#### 2. For each of your methods, what is the worst-case running time? You may write your answer in terms of `n` (the number of vertices), `m` (the number of edges), `d` (the maximum degree of any node in the graph), or any combination of these. Try to give the most informative bound that you can.

1. add - It will be constant time because because you can just jump to the specific node and the vector is random access 
2. remove - 0(d) because again it is random access
3. getCost - 0(d)

TODO

#### 3. Exercise 12.1 from http://opendatastructures.org/ods-cpp/12_4_Discussion_Exercises.html. You may want to draw by hand, upload the picture online (Instagram, Twitter, imgur, or some place like that), and then just put a link here.

      http://www.imageshack.com/i/jt00jcj

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

      The one things that confused me the most about this lab was trying to understand how exactly how to add vectors
