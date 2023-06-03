/* Given a pivot x, and a list lst, partition the list into three parts.

    The first part contains all elements in lst that are less than x
    The second part contains all elements in lst that are equal to x
    The third part contains all elements in lst that are larger than x

Ordering within a part can be arbitrary. */

#include <iostream>
#include <vector>

using namespace std;

void partition(vector<int>& list, int pivot){
    vector<int> part1 ;
    vector<int> part2 ; 
    vector<int> part3 ;

    for (int i=0; i<list.size(); i++){
        if (list[i] < pivot){
            part1.push_back(list[i]);
        } else if(list[i] == pivot){
            part2.push_back(list[i]);
        } else {
            part3.push_back(list[i]);
        }
    }

    cout << "Part 1 : ";
    for (int i=0; i<part1.size(); i++){
        cout << part1[i] << " "; 
    }
    cout << "\n" << "Part 2 : ";
    for (int i=0; i<part2.size(); i++){
        cout << part2[i] << " "; 
    }
    cout << "\n" << "Part 3 : ";
    for (int i=0; i<part3.size(); i++){
        cout << part3[i] << " "; 
    }
    cout << "\n";
}

int main(int argc, char *argv[])
{
    vector<int> list ;
    int n = 10;
    for (int i=0; i<n; i++){
        list.push_back(n-i);
    }

    partition(list, 4);
}