/*
*  push(): adds from the begining
*  append(): adds from the back
*  insertAfter(): adds after a node
*/

#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

Node* push(int newData, Node* head) {
    Node* newHead = new Node();
    newHead->data = newData;
    newHead->next = head;
    return newHead;
}

Node* append(int newData, Node* head) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    Node* newHead = head;

    if(head==NULL)
        newHead = newNode;
    else{
        while(head->next!=NULL) {
            head = head->next;
        }
        head->next = newNode;
    }
    return newHead;
}

void insertAfter(int newData, Node* prevNode) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode; 
}

void printList(Node* n){
    while(n!=NULL) {
        cout << n->data << ", ";
        n = n->next;
    }
}

int main() {
    Node* first = NULL;
    Node* second = NULL;
    Node* third = NULL;

    first = new Node();
    second = new Node();
    third = new Node();

    first->data = 11;
    first->next = second;

    second->data = 22;
    second->next = third;

    third->data = 33;
    third->next = NULL;

    printList(first);
    cout << endl;

    // insert 2 elements push() at begining
    first = push(2, first);
    first = push(4, first);

    printList(first);
    cout << endl;

    // Insert two elements at the back
    first = append(101, first);
    first = append(102, first);

    printList(first);
    cout << endl;

    // InsertAfter
    insertAfter(200, first);
    printList(first);
    cout << endl;

    return 0;
}