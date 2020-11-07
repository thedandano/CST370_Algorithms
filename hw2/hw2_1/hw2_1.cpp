/*
 * Title: hw2_1.cpp
 * Abstract: This program takes in a directed graph's data from a user 
 * and displays it in an adjacency list format.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 11/6/2020
 */

#include <iostream>
#include <list>
#include <map>
using namespace std;

int main() {
    map<int, list<int>> graph;

    // input vertices
    int vertices;
    cin >> vertices;
    // ends program if vertices entered are 0
    if (vertices == 0) {
        return 0;
    }
    // initializes the map with the number of vertices
    for (int x = 0; x < vertices; x++) {
        graph[x];
    }

    // input edges
    int edges;
    cin >> edges;
    // intakes the users graph data and loads to list of the corresponding vertex.
    int source, destination;
    for (int x = 0; x < edges; x++) {
        cin >> source >> destination;
        graph[source].push_back(destination);
    }

    //iterate through map values
    map<int, list<int>>::iterator itr;
    for (itr = graph.begin(); itr != graph.end(); itr++) {
        cout << itr->first;

        itr->second.sort();  // sort the list for each map key first
        list<int>::iterator it;
        for (it = itr->second.begin(); it != itr->second.end(); it++) {
            cout << "->" << *it;
        }
        cout << endl;
    }

    return 0;
}
