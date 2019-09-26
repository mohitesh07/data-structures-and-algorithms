#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node*));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorder(struct node* temp){
    if(!temp)
        return;
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}

void level_order(struct node* temp){
    queue<struct node*> q;
    q.push(temp);
    while(!q.empty()){
        temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

void delete_deepest(struct node* root, struct node* d_node){
    queue<struct node*> q;
    q.push(root);
    struct node* temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp==d_node){
            temp==NULL;
            delete d_node;
        }
        if(temp->right){
            if(temp->right == d_node){
                temp->right = NULL;
                delete d_node;
            }
            else 
                q.push(temp->right);
        }
        if(temp->left){
            if(temp->left == d_node){
                temp->left = NULL;
                delete d_node;
            }
            else 
                q.push(temp->left);
        }
    }
}

struct node* delete_node(struct node* temp,int data){
    struct node* root = temp;
    if(temp==NULL)
        return NULL;
    else if(temp->left==NULL && temp->right==NULL){
        if(temp->data == data)
            return NULL;
        else 
            return temp;
    }
    
    queue<struct node*> q;
    q.push(temp);
    struct node* key_node = NULL;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->data == data)
            key_node = temp;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    if(key_node){
        int x = temp->data;
        delete_deepest(root,temp);
        key_node->data = x;
    }
    return root;
}

int main(){
    struct node* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(6);
    root->left->right = create_node(12);
    root->right->left = create_node(15);
    root->right->right = create_node(16);
    //////// Displaying the tree
    cout<<"in-order traversal is:  ";
    inorder(root);
    cout<<endl;

    cout<<"level-order traversal is:  ";
    level_order(root);
    cout<<endl<<endl;
    ///////// Deleting two nodes in the three
    root = delete_node(root,1);
    root = delete_node(root,12);

    //////// Displaying the tree after deletion
    cout<<"in-order traversal after deletion is:  ";
    inorder(root);
    cout<<endl;

    cout<<"level-order traversal after deletion is:  ";
    level_order(root);

    return 0;   //returns 0 to the Operating System
}