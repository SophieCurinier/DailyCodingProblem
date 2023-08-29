/* Given a string with repeated characters, rearrange the string so that no two adjacent characters are the same. If this is not possible, return None.

For example, given "aaabbc", you could return "ababac". Given "aaab", return None. */
#include <iostream>
#include <utility>
#include <vector>
#include <bits/stdc++.h>
#include <string>

using namespace std;

string rearrangeString(const string& str) {
    // Count the frequency of each character in the input string.
    unordered_map<char, int> charCount;
    for (char c : str) {
        charCount[c]++;
    }

    auto compare = [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second;
    };

    // Create a priority queue (max heap) to store characters based on their frequencies.
    priority_queue<std::pair<char, int>, vector<pair<char, int>>, decltype(compare)> maxHeap(compare);

    for (const auto& entry : charCount) {
        maxHeap.push(entry);
    }

    string result;
    while (!maxHeap.empty()) {
        pair<char, int> current = maxHeap.top();
        maxHeap.pop();

        if (!result.empty() && result.back() == current.first) {
            return "None"; // Not possible to rearrange
        }

        result += current.first;
        current.second--;
        if (current.second > 0) {
            maxHeap.push(current);
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    string failTestCase = "aaab";
    string validTestCase = "aacabbc";
    string result = rearrangeString(validTestCase);
    cout << result << endl;
};