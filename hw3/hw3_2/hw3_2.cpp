/*
 * Title: hw3_3.cpp
 * Abstract: This program solves the Traveling Salesman Problem. It takes in 
 * user graph data then it presents the most shortest round trip path.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 11/12/2020
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct edge {
    int destination, cost;
};


void testPrint(map<int, vector<edge>> graph) {
    map<int, vector<edge>>::iterator itr;
    for (itr = graph.begin(); itr != graph.end(); itr++) {
        cout<< "V:" << itr->first;


        for (int x = 0; x < itr->second.size(); x++)
        {
            cout << " (" << itr->second[x].destination;
            cout << "," << itr->second[x].cost << ")";
        }
        
        cout << endl;
    }
}

map<int, vector<edge>> readInput() {
    map<int, vector<edge>> graph;
    int vertices, edges;
    cin >> vertices;

    for (int x = 0; x < vertices; x++) {
        graph[x];
    }

    int source, destination, cost;
    edge e;
    cin >> edges;
    for (int x = 0; x < edges; x++) {
        cin >> source >> destination >> cost;
        e.destination = destination;
        e.cost = cost;
        graph[source].push_back(e);
    }
    int start_vertex;
    cin >> start_vertex;

    return graph;
}
void createPermutations();
void findOptimalPath();
void printResults();

int main() {
    map<int, vector<edge>> graph;
    graph = readInput();
    testPrint(graph);

    return 0;
}
