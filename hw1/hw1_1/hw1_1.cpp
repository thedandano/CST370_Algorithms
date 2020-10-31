/*
 * Title: hw1_1.cpp
 * Abstract: This program reads inputs from the user and displays the closest
 * distance between two numbers among all input numbres.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 10/29/2020
 */

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// function prototypes
void sortAcend(int arr[], int arrLen);
void getMinDistance(int arr[], int arrLen);

int main() {
    int arrLen = 0;
    cin >> arrLen;

    int numbers[arrLen];
    for (int x = 0; x < arrLen; x++) {
        cin >> numbers[x];
    }

    sortAcend(numbers, arrLen);

    cout << endl;

    getMinDistance(numbers, arrLen);

    return 0;
}

/**
 * Sorts the array in decending order
 * @param int array[]
 * @param int arrLen
 */
void sortAcend(int arr[], int arrLen) {
    int temp;

    for (int x = 0; x < arrLen; x++) {
        for (int y = 0; y < arrLen; y++) {
            if (arr[x] < arr[y]) {
                // sorting!
                temp = arr[x];
                arr[x] = arr[y];
                arr[y] = temp;
            }
        }
    }
}

/**
 * Calculates the minimum distane between 2 numbers and prints the min disantce
 * and which two numbers.
 * @param int arr[]
 * @param int arrLen
 */
void getMinDistance(int arr[], int arrLen) {
    // initializes with first a distance of first two numbers
    int num1 = arr[0];
    int num2 = arr[1];
    int distance = arr[1] - arr[0];
    int tempDis;

    for (int x = 0; x < arrLen; x++) {
        for (int y = 0; y < arrLen; y++) {
            tempDis = arr[y] - arr[x];

            // only takes positive numbers and if less than current distance
            if (tempDis > 0 && tempDis < distance) {
                distance = tempDis;
                num1 = arr[x];
                num2 = arr[y];
            }
        }
    }
    cout << "Min distance: " << distance << endl;
    cout << "Two numbers for min distance: " << num1 << " and " << num2 << endl;
}