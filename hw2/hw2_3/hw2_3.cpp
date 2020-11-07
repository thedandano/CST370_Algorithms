/*
 * Title: hw2_3.cpp
 * Abstract: This program collects the maximum number of apples in boxes. The
 * program then determines the maximum number of apples you can collect from the
 * boxes.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 11/06/2020
 */

#include <math.h>

#include <bitset>
#include <iostream>
#include <map>
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
void printPowerSet(map <int,int> *table, int boxes) {
    unsigned int pow_boxes = pow(2, boxes);
    size_t bits = boxes;
    bool is_empty = true;

    for (int x = 0; x < pow_boxes; x++) {
        printBits(x, boxes);
        // checks the least significant bit first
        for (int y = boxes - 1; y >= 0; y--) {
            if (x & (1 << y)) {
                cout << &table[y] << " ";
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
    // create table
    map<int, int> table;

    // input number of boxes on table
    int boxes;
    cin >> boxes;

    // input apples into boxes
    int apples;
    for (int x = 0; x < boxes; x++) {
        cin >> apples;
        table[x] = apples;
    }

    printPowerSet(&table,boxes);

    // diagnostic
    // for (auto &b : table) {
    //     cout << b.first << " : "
    //          << b.second << endl;
    // }

    return 0;
}
