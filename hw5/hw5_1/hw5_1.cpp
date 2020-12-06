/*
 * Title: hw5_1.cpp
 * Abstract: This program implements a heat data structure using an array using
 * the following commands:
 * - insert (followed by an int)
 * - delete (followed by an int)
 * - update (followed by an int)
 * - heapify
 * - displayMax
 * - deleteMax
 * 
 * Author: Dan Sedano
 * ID: 0254
 * Date: 12/4/2020 
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//prototypes
void inputHeap(vector<int> &heap);
void print(vector<int> v);
bool isMaxHeap(vector<int> heap);
void heapify(vector<int> &heap);
void inputCommands(vector<int> &heap);
void insert(vector<int> &heap, int node_val);
void deleteNode(vector<int> &heap, int node_val);
void update(vector<int> &heap, int node_index, int new_val);
void displayMax(vector<int> heap);
void deleteMax(vector<int> &heap);

int main() {
    vector<int> heap;
    inputHeap(heap);
    if (isMaxHeap(heap)) {
        cout << "This is a heap." << endl;
    } else {
        cout << "This is NOT a heap." << endl;
        //call heapify
        heapify(heap);
    }
    //print(heap);
    // call input commands
    inputCommands(heap);
    return 0;
}

/**
 * Intakes user data to build a heap in array form.
 * @param vector<int> &heap passed by reference to build the heap
 */
void inputHeap(vector<int> &heap) {
    int cycles;
    cin >> cycles;
    heap.resize(cycles + 1);
    int input;
    for (int x = 1; x < cycles + 1; x++) {
        cin >> input;
        heap[x] = input;
    }
}

/**
 * Prints out the type in array form
 * @param vector<int> v the heap to be printed
 */
void print(vector<int> v) {
    for (int x = 1; x < v.size(); x++) {
        cout << v[x] << " ";
    }
    cout << endl;
}

/**
 * Checks if a heap is a Max Heap.
 * @param vector<int> heap the heap to be checked
 * @returns a boolean value
 */
bool isMaxHeap(vector<int> heap) {
    int parent;
    int l_child;
    int r_child;
    for (int x = heap.size() / 2; x > 0; x--) {
        parent = x;
        l_child = x * 2;      // left child
        r_child = x * 2 + 1;  // right child
        if (l_child < heap.size()) {
            //check left child
            if (heap[l_child] > heap[parent]) {
                return false;
            }
        }
        if (r_child < heap.size()) {
            // check right child
            if (heap[r_child] > heap[parent]) {
                return false;
            }
        }
    }
    return true;
}

/**
 * Performs the heapify function on a heap
 * @param vector<int> &heap the heap to be heapified
 */
void heapify(vector<int> &heap) {
    int parent;
    int currVal;
    bool is_heap;
    int l_child;
    int r_child;

    while (!isMaxHeap(heap)) {
        for (parent = heap.size() / 2; parent > 0; parent--) {
            is_heap = false;
            l_child = 2 * parent;
            r_child = 2 * parent + 1;

            while (!is_heap && l_child < heap.size()) {
                if (l_child < heap.size()) {
                    if (heap[l_child] < heap[r_child]) {
                        l_child = r_child;  // assignes right to left
                    }
                    if (heap[parent] >= heap[l_child]) {
                        is_heap = true;
                    } else {
                        // if parent is not greater than the left child
                        swap(heap[parent], heap[l_child]);
                    }
                }
            }
        }
    }
}

/**
 * Inserts a new node into the heap and then heapifies
 * @param vector<int> &heap the heap where the new node will be added
 * @param the new value of the node
 */
void insert(vector<int> &heap, int node_val) {
    heap.push_back(node_val);
    heapify(heap);
}

/**
 * Deletes a node entere by value.
 * @param vector<int> &heap the heap where the node will be deleted
 * @param int node_vale the value of the node that will be deleted
 */
void deleteNode(vector<int> &heap, int node_val) {
    for (int x = 1; x < heap.size(); x++) {
        if (heap[x] == node_val) {
            heap[x] = heap.back();
            heap.pop_back();
            heapify(heap);
            break;
        }
    }
}

/**
 * Updates a nodes value then heapifies
 * @param vector<int> &heap the head where the ndoe will be updated.
 * @param int node_index the index of the node that will be updated.
 * @param int new_val the value that will replace the old value.
 */
void update(vector<int> &heap, int node_index, int new_val) {
    heap[node_index] = new_val;
    heapify(heap);
}

/**
 * Display the maximum value in a passed heap.
 * @param vector<int> heap that we want the max value from.
 */
void displayMax(vector<int> heap) {
    cout << heap[1] << endl;
}

/**
 * Deletes the max value from the passed heap.
 * @param vector<int> &heap the heap where the max value will be deleted from.
 */
void deleteMax(vector<int> &heap) {
    heap[1] = heap.back();
    heap.pop_back();
    heapify(heap);
}

/**
 * Intake the users commands and values and executes the proper funtions.
 * @param vector<int> &heap the heap where the command will be performed on.
 */
void inputCommands(vector<int> &heap) {
    int num_commands;
    cin >> num_commands;

    string command;
    int node_val;    // used to reference a node either by index or value
    int update_val;  // used to change a nodes data.

    for (int x = 0; x < num_commands; x++) {
        cin >> command;

        // switch-like if statments to execute commands
        if (command == "insert") {
            cin >> node_val;
            insert(heap, node_val);
        } else if (command == "delete") {
            cin >> node_val;
            deleteNode(heap, node_val);
        } else if (command == "update") {
            cin >> node_val >> update_val;
            update(heap, node_val, update_val);
        } else if (command == "display") {
            print(heap);
        } else if (command == "displayMax") {
            displayMax(heap);
        } else if (command == "deleteMax") {
            deleteMax(heap);
        }
    }
}
