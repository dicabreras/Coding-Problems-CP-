#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int solve(){
    int n , m; cin>>n>>m; 
    int mp[7] = {};
    int ans = 0;
    for(int i = 0; i<n; i++){
        char c; cin>>c;
        mp[(int)c-65]++;
    }

    for(int i = 0; i<7; i++){
        if(m-mp[i]>0)
            ans+=(m-mp[i]);
    }
    return ans;
}
int main(){
    int t; cin>>t; 
    while(t--){
        int ans = solve();
        cout<<ans<<'\n';
    }
    return 0;
}
//https://codeforces.com/contest/1980/problem/A
