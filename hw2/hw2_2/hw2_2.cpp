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
// #include <boost/dynamic_bitset.hpp>
#include <iostream>
using namespace std;

void printPowerSet(string *set, int set_size) {
    unsigned int pow_set_size = pow(2, set_size);
    const long unsigned int bits = set_size;

    for (int x = 0; x < pow_set_size; x++) {
        cout << bitset<3>(x) << ": ";
        for (int y = 0; y < set_size; y++) {
            if (x & (1 << y)) {
                cout << set[y] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    if (__cplusplus == 201703L)
        std::cout << "C++17" << endl;
    else if (__cplusplus == 201402L)
        std::cout << "C++14" << endl;
    else if (__cplusplus == 201103L)
        std::cout << "C++11" << endl;
    else if (__cplusplus == 199711L)
        std::cout << "C++98" << endl;
    else
        std::cout << "pre-standard C++" << endl;

    int set_size;
    cin >> set_size;
    string set[set_size];

    for (int x = 0; x < set_size; x++) {
        cin >> set[x];
        // cout << set[x];
    }

    printPowerSet(set, set_size);
    return 0;
}
