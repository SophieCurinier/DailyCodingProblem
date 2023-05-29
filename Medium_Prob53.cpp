/*  Implement a queue using two stacks. Recall that a queue is a FIFO (first-in, first-out) data structure with the following methods: enqueue, which inserts an element into the queue, and dequeue, which removes it. */

#include <iostream>
#include <stack>

using namespace std;
template <typename T>

class Queue{
    private :
        stack<T> stack1;
        stack<T> stack2;

    public:
        void enqueue(const T& newItem){
            if (!(stack1.empty())){
                while (!stack1.empty())
                {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
                stack1.push(newItem);
                while (!stack2.empty()){
                    stack1.push(stack2.top());
                    stack2.pop();
                }
            } else {
                stack1.push(newItem);
            }
        }

        void dequeue(){
            stack1.pop();
        }

        T top(){
            return stack1.top();
        }

        bool empty(){
            return stack1.empty();
        }
};


int main(int argc, char *argv[])
{
    Queue<int> queue ;
    for (int i=0; i<5; i++){
        queue.enqueue(i);
    }

    while (!queue.empty()){
        cout << queue.top() << endl;
        queue.dequeue();
    }
}