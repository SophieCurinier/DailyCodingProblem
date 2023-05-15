/* Let's represent an integer in a linked list format by having each node represent a digit in the number. The nodes make up the number in reversed order.
For example, the following linked list:
1 -> 2 -> 3 -> 4 -> 5
is the number 54321.

Given two linked lists in this format, return their sum in the same linked list format.
For example, given
9 -> 9
5 -> 2
return 124 (99 + 25) as:
4 -> 2 -> 1 */


#include <iostream>
#include <cmath>

class Node {
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data) 
{ 
        
    // 1. allocate node
    Node* new_node = new Node(); 
    
    // 2. put in the data
    new_node->data = new_data; 
    
    // 3. Make next of new node as head
    new_node->next = (*head_ref); 
    
    // 4. Move the head to point to 
    // the new node
    (*head_ref) = new_node; 
}

int toValue(Node* node)
{
    int value = 0;
    int k=0;
    while (node != NULL) 
    { 
        value = value + (node->data)*pow(10,k);
        k += 1; 
        node = node->next; 
    }
    return value;
}

void toNode(int value, Node** head_ref){
    signed int nbInteger = 0;
    int quotient = value;
    while (quotient > 10){
        nbInteger += 1 ;
        quotient = (int) value / pow(10,nbInteger);
    }
    nbInteger += 1;
    
    quotient = 0;
    int dataToPush = 0 ;
    for (int i=nbInteger; i>0; i--){
        dataToPush = (value - quotient)/(pow(10,i-1));
        quotient += dataToPush*pow(10,i-1);
        push(head_ref,dataToPush);
    }
}

void printList(Node *node) 
{ 
    bool begining = true;
    while (node != NULL) 
    { 
        if (begining){
            std::cout<<node->data; 
            begining = false;
        } else {
            std::cout<<" -> "<<node->data; 
        }
        node = node->next; 
    }
    std::cout<<" "<<std::endl;
}

void add(Node* head_ref_sum1, Node* head_ref_sum2, Node** head_ref_result)
{
    int value1 = 0;
    int value2 = 0;
    value1 = toValue(head_ref_sum1);
    value2 = toValue(head_ref_sum2);
    int result = value1 + value2;
    std::cout << value1 << " " << value2 << std::endl;
    toNode(result,head_ref_result);
}

int main(int argc, char *argv[])
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* headResult = NULL;
    toNode(99,&head1);
    toNode(25,&head2);
    printList(head1);
    printList(head2);
    add(head1,head2, &headResult);
    printList(headResult);

}