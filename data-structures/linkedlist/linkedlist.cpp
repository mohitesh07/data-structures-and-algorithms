/* Linked List Menu Driven Program
*  @author: Mohitesh Ch Agarwal
*  @date: 22/07/2020
*/

#include <iostream>
using namespace std;

class Node {
    public:
        int data;   // Stores the data. Can store the complex data types also
        Node* next; // Pointer of type node. Points to the next Node
};

void printList(Node* n) {
    while(n != NULL) {
        cout << n->data << ", ";
        n = n->next;
    }
}

int main() {
    // Creates a linkedlist with 3 nodes
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // Allocate three nodes in the Heap
    head = new Node();
    second = new Node();
    third = new Node();

    // Assign data and address to each node
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // print list
    printList(head);

    return 0;   // returns 0 to the operating system
}