/* Given a list of numbers, create an algorithm that arranges them in order to form the largest possible integer. 
For example, given [10, 7, 76, 415], you should return 77641510.*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int cmp(int a, int b) {
    int a_digit = int(log10(a) + 1);
    int b_digit = int(log10(b) + 1);

    int a_first_digit = int(a - a % ((int)pow(10,a_digit-1)))/(pow(10,a_digit-1));
    int b_first_digit = int(b - b % ((int)pow(10,b_digit-1)))/(pow(10,b_digit-1));

    if (a_first_digit>b_first_digit) {
        return true;
    } else if (a_first_digit < b_first_digit) {
        return false;
    } else {
        if ((a*pow(10,b_digit-1) + b) > (b*pow(10,a_digit-1)+a)) {
            return true;
        } else {
            return false;
        }
    }
}

int rearrange(vector<int> list) {
    
    sort(list.begin(), list.end(), cmp);

    int sum = 0;
    for (int i=0; i<list.size(); i++) {
        sum = sum*pow(10,int(log10(list[i]) + 1)) + list[i];
    }

    return sum;
}

int main(int argc, char *argv[])
{
    vector<int> list = {10, 7, 76, 415};
    cout << rearrange(list) << endl;
    
}