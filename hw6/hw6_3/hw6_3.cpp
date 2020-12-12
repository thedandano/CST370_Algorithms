/*
 * Title: hw6_1.cpp
 * Abstract: This program implements floyds algorithm to calculate the
 * all-pairs shortest paths.
 * pairs.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 12/11/2020
 */

#include <iostream>
#include <vector>
using namespace std;

#define INFINITY -1
#define MAX 0x7FFFFFFF

//prototypes
vector<vector<int>> inputMatrix();
void print(vector<vector<int>> A);
int min(int a, int b);
void floyd(vector<vector<int>> &A);

int main()
{
    vector<vector<int>> A = inputMatrix();
    floyd(A);
    print(A);
    return 0;
}

/**
 * Receives handles input from user and builds the matrix.
 * @returns vector<vector<int>>
 */
vector<vector<int>> inputMatrix()
{
    int nodes;
    cin >> nodes;
    nodes++;

    vector<vector<int>> A;
    A.resize(nodes, vector<int>(nodes));
    // fill matrix starting at row1 col1
    int input;
    for (int x = 1; x < nodes; x++)
    {
        for (int y = 1; y < nodes; y++)
        {
            cin >> A[x][y];
        }
    }
    return A;
}

/**
 * Prints out the matrix
 * @param vector<vector<int>> A Matrix to be printed.
 */
void print(vector<vector<int>> A)
{
    vector<vector<int>> R = A;
    int x, y;
    for (x = 1; x < R.size(); x++)
    {
        for (y = 1; y < R.size(); y++)
        {
            cout << A[x][y] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * Returns the minimum of the two input values. With a plot twist. 
 * Converts -1 (i.e., INFINITY) to the max signed 4 byte int value.
 * @param int a first number
 * @param int b second number
 */
int min(int a, int b)
{
    if (a == INFINITY)
    {
        a = MAX;
    }
    if (a > b)
    {
        return b;
    }
    return a;
}

/**
 * Performs floyds algorithm to find the shortist distance.
 * @param vector<vector<int>> A to be analyzed.
 */
void floyd(vector<vector<int>> &A)
{
    vector<vector<int>> R = A;
    int node, row, col; // used this naming convention to help me understand each iteration.
    for (node = 1; node < R.size(); node++)
    {
        for (row = 1; row < R.size(); row++)
        {
            for (col = 1; col < R.size(); col++)
            {
                if (R[row][node] != INFINITY && R[node][col] != INFINITY)
                {
                    R[row][col] = min(R[row][col], R[row][node] + R[node][col]);
                }
            }
        }
    }
    A = R;
}