/* Given two rectangles on a 2D graph, return the area of their intersection. If the rectangles don't intersect, return 0. */
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<vector>
#include <utility>

using namespace std;

bool cmp(pair<char, int>& a,
        pair<char, int>& b) {
    return a.second < b.second;
};

void sortMap(map<char, int>& M) {
    vector<pair<char, int> > A;
 
    for (auto& it : M) {
        A.push_back(it);
    }
 
    sort(A.begin(), A.end(), cmp);
};

bool isMappedString(string str1, string str2) {
    map<char, int> dict1;
    map<char, int> dict2;

    bool isMapped = true;

    for (char c : str1) {
        if (dict1.count(c) == 0) {
            dict1[c] = 0;
        } else {
            dict1[c] += 1;
        }
    }

    for (char c : str2) {
        if (dict2.count(c) == 0) {
            dict2[c] = 0;
        } else {
            dict2[c] += 1;
        }
    }

    sortMap(dict1);
    sortMap(dict2);

    if (dict1.size() == dict2.size()) {
        map<char,int>::iterator it1 = dict1.begin();
        map<char,int>::iterator it2 = dict2.begin();
        for (int i=0; i<dict1.size(); i++){
            if (it1->second != it2->second) {
                isMapped = false;
                break;
            }
            it1 ++;
            it2 ++;
        }
    } else {
        isMapped = false;
    }

    return isMapped;
};

int main(int argc, char *argv[])
{
    string str1 = "abs";
    string str2 = "cdb";
    string str3 = "abb";

    cout << isMappedString(str1, str2) << endl;
    cout << isMappedString(str1, str3) << endl;
};