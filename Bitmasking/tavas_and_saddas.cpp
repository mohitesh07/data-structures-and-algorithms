#include<bits/stdc++.h>
using namespace std;

int main(){
    int lucky_number;
    cin>>lucky_number;
    int n_digits = 0;
    int tmp = lucky_number;
    int i = 0;
    int sum_res = 0;
    while(tmp>0){
        int d = tmp%10;
        if(d == 7)
            sum_res += 1<<i;
        tmp /= 10;
        n_digits++;
        i++;
    }
    cout<<(sum_res + (1<<n_digits) - 1);
    return 0;   // returning 0 to the OS //
}