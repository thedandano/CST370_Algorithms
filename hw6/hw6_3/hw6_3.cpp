/*
 * Title: hw6_1.cpp
 * Abstract: This program implements floyds algorithm to get the shortest distance
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

vector<vector<int>> inputMatrix()
{
    int nodes;
    cin >> nodes;
    nodes++;

    vector<vector<int>> A;
    A.resize(nodes, vector<int>(nodes));
    // fill matrix starting at row1 col1
    for (int x = 1; x < nodes; x++)
    {
        for (int y = 1; y < nodes; y++)
        {
            cin >> A[x][y];
        }
    }
    return A;
}

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

int min(int a, int b)
{
    if (a == INFINITY){
        a = MAX;
    }
    if (a > b)
    {
        return b;
    }
    return a;
}

void floyd(vector<vector<int>> &A)
{
    vector<vector<int>> R = A;
    int node, row, col;
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

int main()
{
    vector<vector<int>> A = inputMatrix();
    // vector<vector<int>> A = {{0, 0, 0, 0},
    //                          {0, 0, 4, 5},
    //                          {0, 2, 0, -1},
    //                          {0, -1, -3, 0}};
    floyd(A);
    print(A);
    return 0;
}