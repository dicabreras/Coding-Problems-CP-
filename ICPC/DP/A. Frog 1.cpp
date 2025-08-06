#include <bits/stdc++.h>
using namespace std; 

int dp[1000000];
int a[1000000];

int h_min(int i, int n){
    if(i == n) return 0;
    if(dp[i]!=-1) return dp[i];
    int h = h_min(i+1, n) + abs(a[i+1]-a[i]);
    if(i+2<=n) h = min(h, h_min(i+2,n) +abs(a[i]-a[i+2]));
    return dp[i]=h;
}

int main()
{
    int n; cin>>n;
    for(int i = 1; i<=n; i++)cin>>a[i];
    memset(dp, -1, sizeof(dp));
    int ans = h_min(1,n);
    cout<<ans;   
}
