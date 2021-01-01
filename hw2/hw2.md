### Homework 2
#### [Homework 2_1](/hw2_1)

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

#### [Homework 2_2](/hw2_2)
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
#### [Homework 2_3](/hw2_3)
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