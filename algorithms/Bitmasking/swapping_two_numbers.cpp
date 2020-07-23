////////////////// BITMASKING /////////////////
// Swapping two numbers really fast          // 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int num1,num2;
    cout<<"Enter two numbers: ";
    cin>>num1>>num2;
    ////// Displaying num1 and num2
    cout<<"num1 = "<<num1<<", num2 = "<<num2<<endl;
    ////// Swapping two numbers
    num1 = num1^num2;
    num2 = num1^num2;
    num1 = num1^num2;
    ////// Displaying after swap
    cout<<"After swap --> num1 = "<<num1<<", num2 = "<<num2<<endl;
    return 0; 
}