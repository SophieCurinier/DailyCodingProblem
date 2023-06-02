/* Given an array of integers in which two elements appear exactly once and all other elements appear exactly twice, find the two elements that appear only once. */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void findOnceElement(vector<int>& list){
    map<int, unsigned int> occurElement ;
    int elem ;
    map<int, unsigned int>::iterator it;

    for (int i=0; i<list.size(); i++){
        elem = list[i];
        it = occurElement.find(elem);
        if (it == occurElement.end()){
           occurElement[elem] = 1;
        } else{
            occurElement.erase(it);
        }
    }

    for (auto rit = occurElement.crbegin(); rit != occurElement.crend(); ++rit){
        cout << rit->first << " ";
    }
    cout << "\n";
}

void findOnceElement2(vector<int>& list){
    int xorResult = 0;

    for (int num : list){
        xorResult ^= num;
    }

    int significantBit = xorResult & -xorResult;

    int group1 = 0;
    int group2 = 0;

    for (int num : list) {
        if (num & significantBit) {
            group1 ^= num;
        } else {
            group2 ^= num;
        }
    }

    cout << group1 << " " << group2 << endl;
}

int main(int argc, char *argv[])
{
    vector<int> list ;
    for (int i=0; i<5; i++){
        list.push_back(i);
        list.push_back(i);
    }

    list.push_back(10);
    list.push_back(12);

    findOnceElement(list);
    findOnceElement2(list);
}