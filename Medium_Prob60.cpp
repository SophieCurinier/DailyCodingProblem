/*  Given a multiset of integers, return whether it can be partitioned into two subsets whose sums are the same. */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumElem(vector<int>* multiset){
    int sum = 0;
    for (int i=0; i<(*multiset).size(); i++){
        sum += (*multiset)[i] ;
    }
    return sum;
}

// ProgDynResult
bool progDynResult(vector<int>* multiset){
    int n = (*multiset).size();
    int sum = sumElem(multiset);
    if (sum%2 == 1){
        return false ;
    }

    vector<vector<bool>> progDynTab = vector<vector<bool>>(n+1,vector<bool>(sum/2 + 1, false));
    for (int i=0; i<= n; i++){
        progDynTab[i][0] = true;
    }

    for (int j=1; j<= sum/2 ; j++){
        for (int i=1; i<= n; i++){
            if (progDynTab[i-1][j]){
                progDynTab[i][j] = true;
            } else {
                int ibis = j-(*multiset)[i-1] ;
                if ((ibis >= 0)){
                    if (progDynTab[i-1][ibis])
                        progDynTab[i][j] = true;

                }
            }
        }
    }

    return progDynTab[n][sum/2];

}


int main(int argc, char *argv[])
{
    vector<int> multiset1{15, 5, 20, 10, 35, 15, 10};
    vector<int>multiset2{15, 5, 20, 10, 35};
    cout << progDynResult(&multiset1) << endl;
    cout << progDynResult(&multiset2) << endl;
}