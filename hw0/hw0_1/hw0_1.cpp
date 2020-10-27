/*
 * Title: hw0_1.cpp
 * Abstract: This program takes a key and 2 numbers as user input and peforms a 
 * summation or subtractons based on they key entered.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 10/26/2020
 */

#include <iostream>
using namespace std;

int main()
{
    int key = 0; // stores the operation key
    int num1 = 0;
    int num2 = 0;
    int sum = 0;
    int diff = 0;

    while (true)
    {
        //handles input
        cin >> key;
        // breaks the loop if the key is 9
        if (key == 9)
        {
            break;
        }
        //intakes input for other numbers
        cin >> num1;
        cin >> num2;
        //processes the sum
        if (key == 1)
        {
            sum = num1 + num2;
            cout << sum << endl;
        }
        // processes the difference
        else if (key == 2)
        {
            diff = num1 - num2;
            cout << diff << endl;
        }
    }

    return 0;
}