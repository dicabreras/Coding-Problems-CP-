#include <bits/stdc++.h>
using namespace std;

vector<int> fibonnaci(int n, int x, int y){
    if(2*y + x == n){
        vector<int> ans = {x, y, y};
        return ans;
    }
    else return fibonnaci(n, y, x+y);
}

int main()
{
    int n; cin>>n;
    if(n!=0 && n!=1){
        vector<int> ans = fibonnaci(n, 0, 1);
        for(int i = 0; i<3; i++){
            cout<<ans[i]<<" "; 
        }
    }
    else{
        if(n==0)cout<<"0 0 0";
        else cout<<"1 0 0";
    }
    return 0;
}
// https://codeforces.com/problemset/problem/199/A 

