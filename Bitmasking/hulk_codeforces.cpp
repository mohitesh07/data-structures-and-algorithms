#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"I hate it";
        return 0;
    }
    int tmp = n/2;
    string result="";
    while(tmp>0){
        result += "I hate that I love ";
        if(tmp!=1)
            result += "that "; 
        tmp--;
    }
    if(n%2)
        result += "that I hate ";
    result += "it";
    cout<<result; 
    return 0;
}