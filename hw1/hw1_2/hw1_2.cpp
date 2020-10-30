/*
 * Title: hw1_1.cpp
 * Abstract: This program checks two strings to see if they are an anagram.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 10/29/2020
 */

#include <iostream>
#include <algorithm>
using namespace std;

bool sameLength(string word1, string word2);
bool isAnagram(string word1, string word2);
void printAnagramCounts(string word1);

int main()
{
    string word1;
    cin >> word1;
    string word2;
    cin >> word2;

    if (sameLength(word1, word2))
    {
        if (isAnagram(word1, word2))
        {
            //cout << "Yes" << endl;
            printAnagramCounts(word1);
        }
        else
        {
            cout << "NO ANAGRAM" << endl;
        }
    }
    else
    {
        cout << "NO ANAGRAM" << endl;
    }

    return 0;
}
bool sameLength(string word1, string word2)
{
    int len1 = word1.length();
    int len2 = word2.length();
    bool isSameLen = false;

    if (len1 == len2)
    {
        isSameLen = true;
    }
    return isSameLen;
}

bool isAnagram(string word1, string word2)
{
    bool isAnagram = false;
    // int stringLen = word1.length();

    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());

    if (word1.compare(word2) == 0)
    {
        isAnagram = true;
    }

    return isAnagram;
}

void printAnagramCounts(string word1)
{
    string array;
    int letterCount = 0;
    sort(word1.begin(), word1.end());
    for (int x = 0; x < word1.length(); x++)
    {
        letterCount = 0;
        for (int y = 0; y < word1.length(); y++)
        {
            if (word1.at(x) == word1.at(y))
            {
                letterCount++;
                array = new string*[x];
                array[x] = new string[y];
                array[x][0] = word1.at(y);
                array[x][1] = atoi(letterCount); 
                cout << word1.at(y) << " : " << letterCount << endl;
                break;
            }
        }
    }
    cout << letterCount << endl;
}
