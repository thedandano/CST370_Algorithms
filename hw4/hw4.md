### Homework 4

#### [Homework 4_1](./hw4_1)

This program partitions a set of numbers by putting all negative numbers in the front and the positive numbers in the rear. Not ordered.
##### Sample input:
* First input indicates the set size
* The remaining values are the set

```
8 
-4 3 9 -6 2 -5 8 7 
```

##### Sample output:

```
-4 -5 -6 9 2 3 8 7 
-4 -6 -5 3 2 9 8 7 
```

#### [Homework 4_2](./hw4_2)

Return the maximum value in an array using Divide and Conquer.
##### Sample input:

- First input indicates the array size
- The remaining inputs are the elements in the array

```
8 
1 3 11 7 5 6 4 9 
```

##### Sample output:

```
11
```

#### [Homework 4_3](./hw4_3)

Performs topological sorting using Kahn's algorithm.
##### Sample input:

- First input indicates number of vertices
- Second input indicates number of edges
- Remaining inputs are input as (Source, Destination)

```
4  
5 
0 1 
0 2 
0 3 
1 3 
2 3 
```

##### Sample output:

```
In-degree[0]:0 
In-degree[1]:1 
In-degree[2]:1 
In-degree[3]:3 
Order:0->1->2->3 
```
