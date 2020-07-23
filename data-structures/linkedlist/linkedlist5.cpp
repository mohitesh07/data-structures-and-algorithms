/* Delete a linkedlist. Free individual memory blocks */
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

// Adds Node at the begining of the list
Node* push(int newData, Node* head) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    if(head!=NULL) {
        newNode->next = head;
    }
    return newNode;
}

void printList(Node* n) {
    cout << "The Linked-list is: ";
    if(n==NULL) {
        cout << "<empty-list>";
        return;
    }
    while(n!=NULL) {
        cout << n->data << ", ";
        n = n->next;
    }
    cout << endl;
}

Node* deleteList(Node* head) {
    if(head==NULL)
        return head;
    else{
        Node* curr = head;
        while(head!=NULL){
            curr = head;
            head = head->next;
            free(curr);
        }
    }
    return NULL;
}

int main() {
    Node* head = NULL;
    head = push(11, head);
    head = push(22, head);
    head = push(24, head);
    head = push(26, head);
    head = push(27, head);
    head = push(30, head);
    head = push(33, head);

    // Print list
    printList(head);

    // Delete entire list
    head = deleteList(head);
    printList(head);

    return 0;   // returns 0 to the Operating-system
}