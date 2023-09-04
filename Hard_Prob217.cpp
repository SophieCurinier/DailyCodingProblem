/* We say a number is sparse if there are no adjacent ones in its binary representation. For example, 21 (10101) is sparse, but 22 (10110) is not. For a given input N, find the smallest sparse number greater than or equal to N.

Do this in faster than O(N log N) time.*/

#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

void intToBits(int n, vector<bool>& bits) {
    bits.clear();
    
    int k = 0;
    while (n >> (k) != 0)
    {
        k ++;
    }
    
    k --;
    for (int i=k; i>= 0; i--) {
        int r = (n>>i)%2;
        bits.push_back(r);
        n = n - (r<<i);
    }
}

int bitsToInt(vector<bool>& bits) {
    int n = 0;

    for (int k=0; k<bits.size(); k++) {
        n += bits[k]<<(bits.size()-k-1);
    }

    return n;
}
void printBits(vector<bool> bits) {
    for (int k=0; k<bits.size(); k++){
        cout << bits[k] << " " ;
    }
    cout << "\n";
}

int findNextSparse(int n) {
    vector<bool> bits ; 
    intToBits(n, bits);

    int result = n;

    for (int deg=bits.size()-1; deg>=0; deg--) {
        if (bits[deg] == 1 & bits[deg+1] == 1 & bits[deg-1] != 1) {
            for (int k=bits.size(); k>=deg-1; k--) {
                bits[k] = 0;
            }

            if (deg-1 < 0) {
                bits.insert(bits.begin(),1);
            } else {
                bits[deg-1] = 1;
            }
        }
    }

    result = bitsToInt(bits);
    
    return result;    
}

int main(int argc, char *argv[]) {
    cout << findNextSparse(6) << endl;
    cout << findNextSparse(4) << endl;
    cout << findNextSparse(38) << endl;
    cout << findNextSparse(44) << endl;
}