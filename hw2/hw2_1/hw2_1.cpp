/*
 * Title: hw2_1
 * Abstract: This program takes in a directed graph's data from a user 
 * and displays it in an adjacency list format.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 11/6/2020
 */

#include <iostream>
using namespace std;

int main()
{
    int vertices;
    cin >> vertices;
    // creates a 0 filled 2d array based on input vertices
    int adj_matrix[vertices][vertices] = {};

    int edges;
    cin >> edges;

    //intakes the users graph data
    int source, destination;
    for (int x = 0; x < edges; x++)
    {
        cin >> source >> destination;
        adj_matrix[source][destination] = 1;
    }

    // diagnostic prints out the entire matrix
    // for(int x = 0; x < vertices; x++) {
    //     for (int y = 0; y < vertices; y++) {
    //         cout << adj_matrix[x][y];
    //     }
    //     cout << "\n";
    // }

    // prints out the adjacency list.
    for (int x = 0; x < vertices; x++)
    {
        cout << x;
        for (int y = 0; y < vertices; y++)
        {
            if (adj_matrix[x][y] > 0)
            {
                cout << "->" << y;
            }
        }
        cout << "\n";
    }

    return 0;
}
