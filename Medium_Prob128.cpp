/* The Tower of Hanoi is a puzzle game with three rods and n disks, each a different size.
All the disks start off on the first rod in a stack. They are ordered by size, with the largest disk on the bottom and the smallest one at the top.
The goal of this puzzle is to move all the disks from the first rod to the last rod while following these rules:
    You can only move one disk at a time.
    A move consists of taking the uppermost disk from one of the stacks and placing it on top of another stack.
    You cannot place a larger disk on top of a smaller disk.
Write a function that prints out all the steps necessary to complete the Tower of Hanoi. You should assume that the rods are numbered, with the first rod being 1, the second (auxiliary) rod being 2, and the last (goal) rod being 3. */

#include <iostream>
#include <stack>

using namespace std;

void move(stack<int>* beginStack, stack<int>* endingStack, stack<int>* interStack, int numberOfDisk, int beginStackNumber, int endingStackNumber, int interStackNumber){
    if (numberOfDisk == 1){
        int element = (*beginStack).top();
        (*beginStack).pop();
        (*endingStack).push(element);
        cout << "Move " << beginStackNumber << " to " << endingStackNumber << endl;
    } else {
        move(beginStack, interStack, endingStack, numberOfDisk - 1, beginStackNumber, interStackNumber, endingStackNumber);
        move(beginStack, endingStack, interStack, 1, beginStackNumber, endingStackNumber, interStackNumber);
        move(interStack, endingStack, beginStack, numberOfDisk - 1, interStackNumber, endingStackNumber, beginStackNumber);
    }
}

int main(int argc, char *argv[])
{
    stack<int> stack1 ;
    stack<int> stack2 ;
    stack<int> stack3 ;

    int n = 3;
    for (int i=0; i<n; i++){
        stack1.push(n-i);
    }

    move(&stack1, &stack3, &stack2, n, 1, 3, 2);

    // std::cout << "Stack 1 : ";
    // while (!stack1.empty()) {
    //     cout << stack1.top() <<" ";
    //     stack1.pop();
    // }
    // std::cout << " " << std::endl;
    // std::cout << "Stack 2 : " ;
    // while (!stack2.empty()) {
    //     cout << stack2.top() <<" ";
    //     stack2.pop();
    // }
    // std::cout << " " << std::endl;
    // std::cout << "Stack 3 : " ;
    // while (!stack3.empty()) {
    //     cout << stack3.top() <<" ";
    //     stack3.pop();
    // }
}