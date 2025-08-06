#include <bits/stdc++.h>
using namespace std; 

int dp[1000000];
int a[1000000];

int h_min(int i, int n, int k){
    if(i == n) return 0;
    if(dp[i]!=-1) return dp[i];
    int h = h_min(i+1, n, k) + abs(a[i+1]-a[i]);
    
    for(int j = 2; j<=k; j++){
        if(i+j<=n){
            h = min(h, h_min(i+j,n,k) +abs(a[i]-a[i+j]));
        }
    }
    return dp[i]=h;
}

int main()
{
    int n, k; cin>>n>>k;
    for(int i = 1; i<=n; i++)cin>>a[i];
    memset(dp, -1, sizeof(dp));
    int ans = h_min(1, n, k);
    cout<<ans;   
}