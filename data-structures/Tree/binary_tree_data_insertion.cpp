#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorder(struct node* temp){
    if(!temp)
        return;
    inorder(temp->left);
    cout<<temp->data<<"\t";
    inorder(temp->right);
}

void row_wise(struct node* temp){
    queue<struct node*> q;
    q.push(temp);
    while(!q.empty()){
        struct node* tmp = q.front();
        cout<<tmp->data<<"\t";
        q.pop();
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
    }
}

void insert_data(struct node* temp, int data){
    queue<struct node*> q;
    q.push(temp);
    while(!q.empty()){
        struct node* tmp = q.front();
        q.pop();
        if(!tmp->left){
            tmp->left = create_node(data);
            break;
        }
        else
            q.push(tmp->left);
        if(!tmp->right){
            tmp->right = create_node(data);
            break;
        }
        else 
            q.push(tmp->right);
    }
}

int main(){
    struct node* root = create_node(10);
    root->left = create_node(11);
    root->right = create_node(12);
    root->left->left = create_node(9);

    ///////// Displaying the tree
    cout<<"The binary tree looks like:- ";
    inorder(root);
    cout<<endl;
    /////////Adding data to the tree
    insert_data(root,25);

    /////////// Displaying th tree
    cout<<"The binary tree after addition looks like:- ";
    row_wise(root);

    return 0;   //returning 0 to the OS
}