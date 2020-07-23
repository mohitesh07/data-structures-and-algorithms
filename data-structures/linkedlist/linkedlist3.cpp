/* Deletes all occurences of a paticular element */
#include <iostream>
using namespace std;

// Structure of the single node in the LinkedList
class Node {
    public:
        int data;
        Node* next;
};

Node* push(int newData, Node* head) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    Node* newHead = head;
    if(head==NULL)
        newHead = newNode;
    else{
        newNode->next = head;
        newHead = newNode;
    }
    return newHead;
}

Node* remove(int dataToDel, Node* head) {
    // LinkedList is empty
    if(head==NULL){
        cout << "List is already empty" << endl;
        return head;
    }
    // First Node data to delete
    else if(head->data == dataToDel) {
        while(head->data == dataToDel) {
            cout << head->data << " is deleted" << endl;
            head = head->next;
        }
        return head;
    }
    else {
        Node* prev;
        Node* n = head;
        while(n!=NULL) {
            if(n->data==dataToDel) {
                cout << dataToDel << " is deleted" << endl;
                prev->next = n->next;
                n = n->next;
                continue;
            }
            prev = n;
            n = n->next;
        }
    }
    return head;
}

void printList(Node* n){
    cout << "Linkedlist is :";
    while(n!=NULL){
        cout << n->data << ", ";
        n = n->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    head = push(11, head);
    head = push(11, head);
    head = push(22, head);
    head = push(22, head);
    head = push(22, head);
    head = push(33, head);
    head = push(44, head);
    head = push(55, head);
    head = push(55, head);

    printList(head);

    head = remove(22, head);
    printList(head);

    return 0;   // returns 0 to the operating system
}