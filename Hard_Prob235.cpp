/* Given an array of numbers of length N, find both the minimum and maximum using less than 2 * (N - 2) comparisons.*/

#include <iostream>
#include <vector>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;

template <typename T>
struct MinMax {
    T min;
    T max;
};

template <typename T>
MinMax<T> findMinMax(vector<T> array) {
    int size = array.size();
    MinMax<T> result ;

    if (size < 1) {
        result ;
    } else if (size == 1) {
        result.min = array[0];
        result.max = array[0];
        return result;
    } else {
        MinMax<T> rightResult, leftResult;

        typename vector<T>::const_iterator beginIt = array.begin();
        typename vector<T>::const_iterator middleIt = array.begin() + int(size/2);
        typename vector<T>::const_iterator endIt = array.end();

        vector<T> rightArray(beginIt, middleIt);
        vector<T> leftArray(middleIt, endIt);

        rightResult = findMinMax(rightArray);
        leftResult = findMinMax(leftArray);

        if (rightResult.min > leftResult.min) {
            result.min = leftResult.min;
        } else {
            result.min = rightResult.min;
        }

        if (rightResult.max > leftResult.max) {
            result.max = rightResult.max;
        } else {
            result.max = leftResult.max;
        }
    }
    return result;
};

int main(int argc, char *argv[])
{
    vector<int> array = {5, 6, -1, 4};

    MinMax result = findMinMax(array);
    cout << result.min << " " << result.max << endl;
}