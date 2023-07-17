/* Given a string, return the first recurring character in it, or null if there is no recurring character.

For example, given the string "acbbac", return "b". Given the string "abcdef", return null. */
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<vector>
#include <utility>

using namespace std;

char findFirstRecurringChar(string str) {
    map<char, int> dict;

    char* recurringChar = NULL;
    for (char c : str) {
        if (dict.count(c) == 0) {
            dict[c] = 0;
        } else {
            dict[c] += 1;
            recurringChar = &c;
            break;
        }
    }

    // return recurringChar ;
    if (recurringChar == NULL) {
        return '\0' ;
    } else {
        return *recurringChar;
    }
}

int main(int argc, char *argv[])
{
    string str1 = "abcddefb";
    string str2 = "abcdef";

    cout << findFirstRecurringChar(str1) << endl;
    cout << findFirstRecurringChar(str2) << endl;
};