/* ou come across a dictionary of sorted words in a language you've never seen before. Write a program that returns the correct order of letters in this language.

For example, given ['xww', 'wxyz', 'wxyw', 'ywx', 'ywz'], you should return ['x', 'z', 'w', 'y'].*/

#include <iostream>
#include <vector>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;

vector<char> orderLetter(vector<string> sortedWords) {
    int numbersWords = sortedWords.size();

    vector<char> sortedLetters ;

    for (int i=0; i<numbersWords-1; i++) {
        int j = i+1;
            if (i != j) {
                string word1 = sortedWords[i];
                string word2 = sortedWords[j];
                
                // Find difference character between 2 words
                int index = 0; 
                bool notDiff = index<word1.size() && index<word2.size() && word1[i] == word2[i];
                while (notDiff) {
                    index ++;
                    notDiff = index<word1.size() && index<word2.size() && word1[index] == word2[index];
                }

                // cout << word1[index] << " " << word2[index] << endl;

                // Adjust order in 
                if (index >= word1.size()) {
                    // cout << "Inutile" << endl;
                } else {
                    // Find if word1[index] is already in sortedLetters
                    bool char1isIn = false;
                    for (char c : sortedLetters) {
                        if (word1[index] == c) {
                            char1isIn = true;
                            break;
                        }
                    }

                    // Find if word2[index] is already in sortedLetters
                    bool char2isIn = false;
                    for (char c : sortedLetters) {
                        if (word2[index] == c) {
                            char2isIn = true;
                            break;
                        }
                    }

                    if (char1isIn && char2isIn) {
                        // Verify is char1 is before char2
                        vector<char>::iterator char1Index = sortedLetters.begin();
                        vector<char>::iterator char2Index = sortedLetters.begin();

                        for (vector<char>::iterator k=sortedLetters.begin(); k<sortedLetters.end(); k++) {
                            if (*k == word1[index]) {
                                char1Index = k;
                            } else if (*k == word1[index]) {
                                char2Index = k;
                            }
                        }

                        if (char1Index > char2Index) {
                            sortedLetters.erase(char1Index);
                            sortedLetters.insert(char2Index,word1[index]);
                        }
                    } else if (char1isIn && !char2isIn) {
                        // Find index of char2
                        vector<char>::iterator char1Index = sortedLetters.begin();
                        for (vector<char>::iterator k=sortedLetters.begin(); k<sortedLetters.end(); k++) {
                            if (*k == word1[index]) {
                                char1Index = k;
                                break;
                            }
                        }

                        sortedLetters.insert(char1Index+1, word2[index]);
                    } else if (!char1isIn && char2isIn) {
                        // Find index of char2
                        vector<char>::iterator char2Index = sortedLetters.begin();
                        for (vector<char>::iterator k=sortedLetters.begin(); k<sortedLetters.end(); k++) {
                            if (*k == word2[index]) {
                                char2Index = k;
                                break;
                            }
                        }

                        sortedLetters.insert(char2Index, word1[index]);

                    } else {
                        sortedLetters.push_back(word1[index]);
                        sortedLetters.push_back(word2[index]);
                    }

                }

            }
    }
    return sortedLetters;
}

int main(int argc, char *argv[])
{
    vector<string> sortedWords = {"xvw", "xvwy", "wxyz", "wxyw", "ywx"};
    vector<char> order = orderLetter(sortedWords);

    for (int i=0; i<order.size(); i++) {
        cout << order[i] << " " ;
    }

    cout << "\n";
}