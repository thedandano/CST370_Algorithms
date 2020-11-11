/*
 * Title: hw3_1
 * Abstract: This program reads in a positive integer number from the user
 * and reverses the number while eliminating leading zeros.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 11/11/30
 */

#include <iostream>
#include <vector>
using namespace std;

int removeTrailingZero(unsigned int n) {
    while (n % 10 == 0) {
        n /= 10;
    }
    return n;
}

vector<int> toArrayReverse(unsigned int n) {
    vector<int> v;
    // if zero is input
    if (n == 0) {
        v.push_back(n);
        return v;
    } else {
        // convert int into array while removing trailing zeros from original int.
        n = removeTrailingZero(n);
        while (true) {
            v.push_back(n % 10);
            n /= 10;
            if (n == 0) {
                return v;
            }
        }
    }
}

void printResult(vector<int> v) {
    for (int i : v) {
        cout << i;
    }
    cout << endl;
}

int main() {
    vector<int> v;
    unsigned int number;
    cin >> number;
    v = toArrayReverse(number);
    printResult(v);

    return 0;
}
