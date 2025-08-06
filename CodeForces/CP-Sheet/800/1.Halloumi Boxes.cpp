#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k){
    int a[n];
    bool flag = true;
    for(int i = 0; i<n; i++)cin>>a[i];
    if(k==1){
        for(int i=0, j=1; j<n; j++, i++){
            if(a[j]<a[i])flag = false;
        }     
    }
    if(flag)cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    int t, n, k; cin>>t;
    
    while(t--){
        cin>> n >> k;     
        solve(n,k);
    }
    
    return 0;
}

// https://codeforces.com/problemset/problem/1903/A