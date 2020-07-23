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

void level_order(struct node* tmp){
    queue<struct node*> q;
    q.push(tmp);
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        cout<<tmp->data<<" ";
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
    }
}

void left_view_util(struct node *tmp,int level,int *max_level){
    if(!tmp)
        return;
    if(level>*max_level){
        cout<<tmp->data<<" ";
        *max_level = level;
    }
    left_view_util(tmp->left,level+1,max_level);
    left_view_util(tmp->right,level+1,max_level);
}

void left_view(struct node* root){
    int max_level = 0;
    left_view_util(root,1,&max_level);
}

int main(){
    struct node* root = create_node(2);
    root->left = create_node(3);
    root->right = create_node(5);
    root->left->left = create_node(6);
    root->left->right = create_node(7);
    ///// Display
    cout<<"Level-order-traversal: ";
    level_order(root);
    cout<<endl;
    ////Left view
    cout<<"Left-view: ";
    left_view(root);
    cout<<endl;
    return 0;
}