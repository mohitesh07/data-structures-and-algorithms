#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

struct node* create_node(int data){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

void inorder(struct node* tmp){
    if(!tmp)
        return;
    inorder(tmp->left);
    cout<<tmp->data<<" ";
    inorder(tmp->right);
}

void level_order(struct node* tmp){
    queue<struct node*> q;
    q.push(tmp);
    while(!q.empty()){
        tmp = q.front();
        cout<<tmp->data<<" ";
        q.pop();
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
    }
}

void delete_deepest(struct node* root, struct node* d_node){
    struct node* tmp;
    queue<struct node*> q;
    q.push(root);
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        if(tmp == d_node){
            tmp = NULL;
            delete (d_node);
            return;
        }
        if(tmp->left){
            if(tmp->left == d_node){
                tmp->left = NULL;
                delete d_node;
                return;
            }
            else 
                q.push(tmp->left);
        }
        if(tmp->right){
            if(tmp->right == d_node){
                tmp->right = NULL;
                delete d_node;
                return;
            }
            else 
                q.push(tmp->right);
        }
    }
}

struct node* delete_node(struct node* root, int data){
    if(root==NULL)
        return NULL;
    else if(root->left==NULL && root->right==NULL){
        if(root->data == data)
            return NULL;
        else 
            return root;
    }
    struct node* tmp = root;
    struct node* key_node = NULL;
    queue<struct node*> q;
    q.push(tmp);
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        if(tmp->data == data)
            key_node = tmp;
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
    }
    if(key_node){
        int x = tmp->data;
        delete_deepest(root,tmp);
        key_node->data = x;
    }
    return root;
}

int size(struct node* tmp){
    if(tmp==NULL)
        return 0;
    return size(tmp->left) + 1 + size(tmp->right);
}

int maximum_tree(struct node* root){
    if(!root)
        return INT_MIN;
    int maxi;
    int res = root->data;
    int l_res = maximum_tree(root->left);
    int r_res = maximum_tree(root->right);
    if(res>l_res)
        maxi = res;
    else
        maxi = l_res;
    if(r_res>maxi)
        maxi = r_res;
    return maxi;
}

int minimum_tree(struct node* root){
    if(!root)
        return INT_MAX;
    int res = root->data;
    int l_res = minimum_tree(root->left);
    int r_res = minimum_tree(root->right);
    if(l_res<res)
        res = l_res;
    if(r_res<res)
        res = r_res;
    return res;
}

int main(){
    struct node* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    ////////// Displaying the binary tree
    cout<<"In-order traversal: ";
    inorder(root);
    cout<<endl;

    cout<<"Level-order traversal: ";
    level_order(root);
    cout<<endl;
    /////// Deleting a node
    delete_node(root,2);
    delete_node(root,3);
    /////// Displaying the tree after deletion
    cout<<"In-order traversal after deletion: ";
    inorder(root);
    cout<<endl;

    cout<<"Level-order traversal after deletion: ";
    level_order(root);
    cout<<endl;
    //////// Size of the tree is
    cout<<"Size(number of elements of tree) = "<<size(root)<<endl;

    /////// Maximum and minimum of tree is
    cout<<"Maximum of tree = "<<maximum_tree(root)<<endl;
    cout<<"Minumum of tree = "<<minimum_tree(root)<<endl;
    return 0;
}