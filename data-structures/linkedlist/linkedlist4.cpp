/* Delete a node in linkedlist when the postion "index" is given */
#include <iostream>
using namespace std;

// Structure of Node
class Node {
    public:
        int data;
        Node* next;
};

// Add node from the begining
Node* push(int data, Node* head){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if(head!=NULL)
        newNode->next = head;
    return newNode;
}

void printList(Node* n){
    cout << "The Linked-List is: ";
    while(n!=NULL){
        cout << n->data << ", ";
        n = n->next;
    }
    cout << endl;
}

Node* removeIndex(int index, Node* head) {
    int pos = 0;
    if(head==NULL) {
        cout << "The LinkedList is empty. Nothing to delete." << endl;
        return head;
    }
    if(index == 0) {
        cout << head->data << " is removed at index " << index << endl;
        head = head->next;
        return head;
    }
    else {
        Node* prev;
        Node* n = head;
        pos = 0;
        while(n!=NULL){
            if(pos==index) {
                cout << n->data << " is removed at index " << index << endl;
                prev->next = n->next;
                break;
            }
            prev = n;
            n = n->next;
            ++pos;
        }
    }

    if(pos>=index)
        cout << "Linked-List index out of bounds: List has " << (pos) << " elements and trying to access " << index << "th index is not possible." << endl;
    return head;
}

int main() {
    // Makeup a linkedlist
    Node* head = NULL;
    head = push(11, head);
    head = push(22, head);
    head = push(33, head);
    head = push(44, head);
    head = push(55, head);
    head = push(66, head);
    head = push(77, head);
    head = push(88, head);
    head = push(99, head);
    head = push(100, head);

    printList(head);

    head = removeIndex(9, head);
    head = removeIndex(100, head);
    printList(head);

    return 0;   // returns 0 to the operating system
}