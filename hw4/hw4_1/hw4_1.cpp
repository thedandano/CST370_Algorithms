/*
 * Title: hw4_1.cpp
 * Abstract: This program reads in signed integers and places all negative
 * numbers in the front and all non-negative numbers in the back.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 11/25/2020
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Prototypes
vector<int> input();
void print(vector<int> v);
void method1(vector<int> &v);
void method2(vector<int> &v);

int main() {
    vector<int> numbers = input();
    vector<int> m1 = numbers;
    vector<int> m2 = numbers;

    method1(m1);
    print(m1);
    method2(m2);
    print(m2);
    return 0;
}

/**
 * Processes user input.
 * @returns a vector<int> with the user's input.
 */
vector<int> input() {
    int size;
    cin >> size;
    vector<int> arr;
    arr.resize(size);

    for (int x = 0; x < size; x++) {
        cin >> arr[x];
    }

    return arr;
}

/**
 * Partitions the user's input by starting at each end of the array
 * @param vector<int> &v is passed in by reference.
 */
void method1(vector<int> &v) {
    int front = 0;           // points to the front
    int end = v.size() - 1;  // points to the end

    while (end > front) {
        if (v[front] > 0 && v[end] < 0) {
            swap(v[front], v[end]);
            front++;
            end--;
        } else if (v[front] < 0 && v[end] < 0) {
            front++;
        } else {
            end--;
        }
    }
}

/**
 * Partitions the user's input by using two pointers to scan from left to right.
 * The marker finds a positive and waits for the scout to find a number to swap 
 * positions with
 * @param vector<int> &v is passed in by reference.
 */
void method2(vector<int> &v) {
    int marker = 0;  // marks positive numbers
    int scout = 0;   // scouts for negative numbers
    while (scout < v.size()) {
        if (!v[marker] > 0) {
            marker++;
        }
        if (v[scout] < 0) {
            swap(v[marker], v[scout]);
            marker++;
            scout++;
        } else {
            scout++;
        }
    }
}

/**
 * Prints out the vectors
 */
void print(vector<int> v) {
    for (auto x : v) {
        cout << x << " ";
    }
    cout << "\n";
}
