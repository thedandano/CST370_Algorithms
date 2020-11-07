/*
 * Title: hw2_2.cpp
 * Abstract: This program reads a number of elements in a set and then the elements
 * of the set. Then the this program will display all possible binary numbers and 
 * corresponding subsets one by one.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 11/6/2020
 */

#include <math.h>

#include <bitset>
#include <iostream>
using namespace std;

/**
 * This function prints out the binary form of a decimal number limited by the 
 * size of the set.
 * @param int n and int set_size
 */
void printBits(int n, int set_size) {
    int binaryNum[set_size] = {};
    int i = set_size;

    // if set is 0 then cannot convert to binary
    if (set_size == 0) {
        cout << set_size;
    } else {
        while (n > 0) {
            binaryNum[i - 1] = n % 2;
            n = n / 2;
            i--;
        }
        for (auto x : binaryNum) {
            cout << x;
        }
    }
    cout << ":";
}

/**
 * Prints out the power set and subsets of user input.
 * @param string *set 
 * @param int set_size
 * 
 */
void printPowerSet(string *set, int set_size) {
    unsigned int pow_set_size = pow(2, set_size);
    size_t bits = set_size;
    bool is_empty = true;

    for (int x = 0; x < pow_set_size; x++) {
        printBits(x, set_size);
        // checks the least significant bit first 
        for (int y = set_size - 1; y >= 0; y--) {
            if (x & (1 << y)) {
                cout << set[y] << " ";
                is_empty = false;
            }
        }
        if (is_empty) {
            cout << "EMPTY";
        }
        cout << endl;
    }
}

int main() {
    int set_size;
    cin >> set_size;
    string set[set_size];

    // inputs set
    for (int x = 0; x < set_size; x++) {
        cin >> set[set_size - x - 1];
    }

    printPowerSet(set, set_size);
    return 0;
}
