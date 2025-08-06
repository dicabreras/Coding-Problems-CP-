#include <bits/stdc++.h>
using namespace std; 

int main(int argc, char const *argv[])
{
    int n, mod_4, remainders[4] ={8,4,2,6} ;
    cin>>n; 
    if(n!=0){
        mod_4=n%4;
        if(mod_4==0)
            cout<<remainders[3];
        else{
            cout<<remainders[(mod_4-1)];
        }    
    }
    else{
        cout<<1;
    }
    return 0;
}
// https://codeforces.com/problemset/problem/742/A
