#include <bits/stdc++.h>
using namespace std;

bool isAPerfectSquare(){    
    int n; cin>>n;
    long long x = 0; 
    for(int i = 0; i<n; i++){
        long long z = 0; cin>>z;
        x+=z;
    }
    long long l = 1, r = 1e9; 
    while(l<=r){
        long long k = l + (r-l)/2;
        if(k*k == x) return true;
        if(k*k<x) l=k+1;
        else r=k-1;
    }
    return false;
}

int main()
{
    int t; cin>>t; 
    while(t--){
        bool ans = isAPerfectSquare();
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
