/*
 * Title: hw4_2.cpp
 * Abstract: This program displays the biggest number in an array using the 
 * divide-and-conquer technique.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 11/26/20
 */

#include <iostream>
#include <vector>
using namespace std;

//prototypes
vector<int> input();
int find_max(vector<int> v, int start, int end);

int main() {
    vector<int> numbers = input();
    int max = find_max(numbers, 0, numbers.size() - 1);
    cout << max << endl;
    return 0;
}

/**
 * Receives user input and puts the values into an array.
 * @returns vector<int> of user input data
 */
vector<int> input() {
    vector<int> v;
    int size;

    cin >> size;
    v.resize(size);

    for (int x = 0; x < size; x++) {
        cin >> v[x];
    }

    return v;
}

/**
 * Finds the maximum value in the array using divide and conquer. 
 * @param vector<int> v the array holding the values.
 * @param int start indicates the start of the array
 * @param int end indicates the end of the array
 * @returns the maximum value in the array.
 */
int find_max(vector<int> v, int start, int end) {
    if (start == end)  // initial condition
        return v[start];

    // the actual divide and conquer.
    int max1 = find_max(v, start, (start + end) / 2);
    int max2 = find_max(v, (start + end) / 2 + 1, end);

    // compares the call's returned value
    if (max1 > max2)
        return max1;
    else
        return max2;
}
