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

//A struct to hold the results of boxes chosen.
struct Results {
    unsigned int boxes;  // decimal
    int maxApples;
};

// Function prototypes
Results chooseBoxes(map<int, int> table, int boxes);
int sumChosenBoxes(unsigned int number, map<int, int> table);
void printResults(Results p);

int main() {
    // create table
    map<int, int> table;
    Results chosenBoxes;

    // input number of boxes on table
    int boxes;
    cin >> boxes;

    // input apples into boxes
    int apples;
    for (int x = 0; x < boxes; x++) {
        cin >> apples;
        table[x] = apples;
    }

    chosenBoxes = chooseBoxes(table, boxes);
    printResults(chosenBoxes);

    return 0;
}

/**
 * Choses the boxes and returns the results of the way to get the most boxes.
 * @param map<int, int> table
 * @param int boxes
 * @returns Results p
 */
Results chooseBoxes(map<int, int> table, int boxes) {
    unsigned int pow_boxes = pow(2, boxes);
    Results r;  // stores results
    // initialize
    r.boxes = 0;
    r.maxApples = 0;

    int sum = 0;
    for (int x = 0; x < pow_boxes; x++) {
        sum = sumChosenBoxes(x, table);
        if (sum > r.maxApples) {
            r.boxes = x;
            r.maxApples = sum;
        }
    }
    return r;
}

/**
 * Returns the total sum of chosen boxes.
 * @param unsigned int number
 * @param map<int, int> table
 * @returns sum
 */
int sumChosenBoxes(unsigned int number, map<int, int> table) {
    bitset<16> bit(number);  // convert decimal number to binary

    int limit = 15;  // 16-1 bits // 16 errors out for some reason.
    int sum = 0;
    for (int x = 0; x <= limit; x++) {
        // if true then it is a chosen box
        if (bit.test(x)) {
            // if chosen box is first in array then check the next box
            if (x == 0) {
                if (!bit.test(x + 1)) {
                    sum += table[x];
                }
            }
            // if chosen box is last in array check previous box
            else if (x == limit) {
                if (!bit.test(x - 1)) {
                    sum += table[x];
                }
            }
            // other wise check next and prev box for all other boxes
            else {
                if (!bit.test(x + 1) && !bit.test(x - 1)) {
                    sum += table[x];
                }
            }
        }
    }
    return sum;
}

/**
 * Prints the results of the selection process.
 * @param Results p
 */
void printResults(Results r) {
    bitset<16> bit(r.boxes);
    //print chosen boxes
    cout << "Boxes:";
    for (int x = 0; x <= 15; x++) {
        if (bit.test(x)) {
            cout << x << " ";
        }
    }
    cout << endl;
    // print max number of apples
    cout << "Max Apples:" << r.maxApples << endl;
}
