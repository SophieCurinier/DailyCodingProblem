/* On our special chessboard, two bishops attack each other if they share the same diagonal. This includes bishops that have another bishop located between them, i.e. bishops can attack through pieces.

You are given N bishops, represented as (row, column) tuples on a M by M chessboard. 
Write a function to count the number of pairs of bishops that attack each other. 
The ordering of the pair doesn't matter: (1, 2) is considered the same as (2, 1). */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// O(n^2)
int countNaif(vector<pair<int,int>>* bishopList){
    int n = (*bishopList).size();
    int numberAttack = 0;
    for (int k=0; k<n; k++){
        for (int q=k+1; q<n; q++){
            if ((*bishopList)[k].first - (*bishopList)[q].first == (*bishopList)[k].second - (*bishopList)[q].second){
                numberAttack += 1;
            }
            if ((*bishopList)[k].first + (*bishopList)[k].second == (*bishopList)[q].first + (*bishopList)[q].second){
                numberAttack += 1;
            }
        }
    }
    return numberAttack;
}

// O(nlog(n))
int countSort(vector<pair<int,int>>* bishopList){
    int n = (*bishopList).size();
    vector<pair<int,int>> rightSortedBishopList = vector<pair<int,int>>(n);
    vector<pair<int,int>> leftSortedBishopList = vector<pair<int,int>>(n);
    int rightSumCoor ;
    int leftSumCoor ;
    for (int i=0; i<n; i++){
        rightSumCoor = (*bishopList)[i].first - (*bishopList)[i].second;
        rightSortedBishopList[i] = pair<int,int>(rightSumCoor,i);
        leftSumCoor = (*bishopList)[i].first + (*bishopList)[i].second;
        leftSortedBishopList[i] = pair<int,int>(leftSumCoor,i);
    }

    sort(rightSortedBishopList.begin(), rightSortedBishopList.end());
    sort(leftSortedBishopList.begin(), leftSortedBishopList.end());

    int numberAttack = 0;
    int k = 0;
    int rightNumberAlignForK = 0;
    int rightSumValue = rightSortedBishopList[k].first ;
    int leftNumberAlignForK = 0;
    int leftSumValue = leftSortedBishopList[k].first ;

    while (k<n)
    {
        if (rightSumValue == rightSortedBishopList[k].first){
            rightNumberAlignForK += 1;
        } else {
            numberAttack += rightNumberAlignForK*(rightNumberAlignForK-1)*0.5 ;
            rightNumberAlignForK = 1;
            rightSumValue = rightSortedBishopList[k].first ;
        }
        if (leftSumValue == leftSortedBishopList[k].first){
            leftNumberAlignForK += 1;
        } else {
            numberAttack += leftNumberAlignForK*(leftNumberAlignForK-1)*0.5 ;
            leftNumberAlignForK = 1;
            leftSumValue = leftSortedBishopList[k].first ;
        }
        k ++ ;
    }
    numberAttack += rightNumberAlignForK*(rightNumberAlignForK-1)*0.5 ;
    numberAttack += leftNumberAlignForK*(leftNumberAlignForK-1)*0.5 ;

    return numberAttack ;
}

int main(int argc, char *argv[])
{
    vector<pair<int,int>> bishopList ;

    bishopList.push_back(pair<int,int>(0,0));
    bishopList.push_back(pair<int,int>(1,2));
    bishopList.push_back(pair<int,int>(2,2));
    bishopList.push_back(pair<int,int>(4,0));

    // cout << countNaif(&bishopList) << endl;
    // cout << countSort(&bishopList) << endl;
}