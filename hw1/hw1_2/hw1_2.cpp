/*
 * Title: hw1_2.cpp
 * Abstract: This program checks two strings to see if they are an anagram.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 10/29/2020
 */

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool sameLength(string word1, string word2);
bool isAnagram(string word1, string word2);
map<char, int> countChars(string word1);
void printCharCounts(map<char, int> map);

int main()
{
    string word1;
    cin >> word1;
    string word2;
    cin >> word2;

    if (sameLength(word1, word2))
    {
        //sort both words first
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());

        if (isAnagram(word1, word2))
        {
            cout << "ANAGRAM" << endl;

            printCharCounts(countChars(word1));
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

/**
 *Compares the length of two strings returns true if they are the same 
 * @param string word1
 * @param string word2
 * @returns true if word lenght matches false otherwise.
 */
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

/**
 * Takes in sorted strings to compare them, and returns true or false.
 * @param string word1
 * @param string word2
 * @returns bool if the strings are an anagram.
 */
bool isAnagram(string word1, string word2)
{
    bool isAnagram = false;

    if (word1.compare(word2) == 0)
    {
        isAnagram = true;
    }

    return isAnagram;
}

/**
 * Calculates the counts of each character and adds them to a map, then it returns the map.
 * @param string word
 * @returns a map of <char, int> with the counts of each character.
 */
map<char, int> countChars(string word)
{
    //laod counts
    map<char, int> counts;
    for (int x = 0; x < word.length(); x++)
    {
        // adds the character to the map. Any duplicates will just have the value updated.
        counts[word.at(x)] += 1; 
    }
    return counts;
}

/**
 * Prints out the counts map of <char, int>.
 * @param map<char,int> counts
 */
void printCharCounts(map<char, int> counts)
{
    for (auto &x : counts)
    {
        cout << x.first << " : " << x.second << endl;
    }
}
