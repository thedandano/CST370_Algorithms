# CST370_Algorithms

## Description

## Programs

### Homework 0

### Homework 1
1. [Displays the the closest distance between two numbers](/hw1/hw1_1)
2. [Checks if two strings are anagrams](/hw1/hw1_2)
3. [Displays the maximum number of events that take place concurrently](/hw1/hw1_3)
### Homework 2
1. [Converts a user input directed graph into an adjacency matrix format](/hw2/hw2_1)
2. [Displays all possible subsets using binary numbers](hw2/hw2_2)
3. [Collects max number of apples using brute force techniques](hw2/hw2_3)
### Homework 3
1. [Reverses a positive integer](/hw3/hw3_1)
2. [Presents a path for Traveling Salesman Problem](/hw3/hw3_2)
3. [Implements the Depth-First Search algorithm](/hw3/hw3_3)
### Homework 4
1. [Uses partitioning to place all negative numbers in the first half of the set](/hw4/hw4_1)
2. [Find the max number in an array using the Divide and Conquer technique](/hw4/hw4_2)
3. [Performs topological sorting based on Kahn's algorithm](/hw4/hw4_3)
### Homework 5
1. [Perform head operations (e.g., insert, delete max, display, update)](/hw5/hw5_1)
2. [Displays the performance of 3 sorting algorithms](/hw5/hw5_2)
3. [Bonus: Implements a hash table using Linear Probing](/hw5/hw5_3)
### Homework 6
1. [Performs Radix Sort](/hw6/hw6_1)
2. [Using Dynamic Programming, collects max number of coins in a board](/hw6/hw6_2)
3. [Implements Floyd's Algorithm to calculate all-pairs shortest paths](/hw6/hw6_3)

### Homework 2
#### Homework 2_1

This program takes in graph data from a user and converts the input data into an adjacency list.

##### Sample input:

```
5
5
2 3
3 4
1 2
0 2
2 4
```

##### Sample output:

```
0->2
1->2
2->3->4
3->4
4
```

#### Homework 2_2
Modifies a program from https://www.geeksforgeeks.org/power-set/ which allows the user to input a set of elements to generate all the possible subsets.
##### Sample input:
```
3
A B C
```
##### Sample output:
```
000:EMPTY
001:C
010:B
011:B C
100:A
101:A C
110:A B
111:A B C
```
#### Homework 2_3
Using some of the logic from the previous program, the program takes in a user data that consists of the number of boxes in a table and the amount of apples in each box. The program then calculates the ways to pick apples and picks the way to pick the most apples while allowing at least 1 box in between each box choice.
##### Sample input:
```
6
5
1
2
10
6
2
```
##### Sample output:
```
Boxes:0 3 5
Max Apples:17
```
