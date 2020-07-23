#include<bits/stdc++.h>
using namespace std;

char tree[10];

int root(char key){
    if(tree[0]!='\0')
        cout<<"Tree's root already exists"<<endl;
    else
        tree[0] = key;
    return 0;
}

int insert_left(char key, int parent){
    if(tree[parent]=='\0')
        cout<<"Cannot set child at "<<(2*parent+1)<<", no parent found"<<endl;
    else 
        tree[parent*2+1] = key;
    return 0;
}

int insert_right(char key,int parent){
    if(tree[parent]=='\0')
        cout<<"Cannot set child at "<<(2*parent+2)<<", no parent found"<<endl;
    else 
        tree[parent*2+2] = key;
    return 0;
}

int print_tree(){
    for(int i=0;i<10;i++)
        if(tree[i]!='\0')
            cout<<tree[i]<<" ";
        else 
            cout<<"-"<<" ";
    return 0;
}

int main(){
    root('A');
    insert_left('B',0);
    insert_right('C',0);
    insert_left('D',1);
    insert_right('E',1);
    insert_left('F',2);
    ////////// Display 
    cout<<endl;
    print_tree();
    return 0;   //returns 0 to the Operating System
}
