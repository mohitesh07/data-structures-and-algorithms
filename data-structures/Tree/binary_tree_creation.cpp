#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main(){
    struct node* root = create_node(11);
    root->right = create_node(12);
    root->left = create_node(10);
    root->left->left = create_node(9);
    ///////////////// Displaying the result
    cout<<root->data<<endl<<root->left->data<<endl<<root->right->data<<endl<<root->left->left->data<<endl;
    return 0;   //returns 0 to the Operating System
}