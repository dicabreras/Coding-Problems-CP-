#include <bits/stdc++.h>
using namespace std; 

int dp[1000000][4];
int a[1000000][4];
int n;

int f(int d, int prev){
    if(d == n) return 0;
    if(dp[d][prev]!=-1) return dp[d][prev];

    int mx = INT_MIN;
    if(prev==1) {
        mx = max(mx, f(d+1, 2) + a[d+1][2]);
        mx = max(mx, f(d+1, 3) + a[d+1][3]);
    }
    else if(prev==2) {
        mx = max(mx, f(d+1, 1) + a[d+1][1]);
        mx = max(mx, f(d+1, 3) + a[d+1][3]);
    }
    else if(prev==3) {
        mx = max(mx, f(d+1, 1) + a[d+1][1]);
        mx = max(mx, f(d+1, 2) + a[d+1][2]);
    }
    else{
        mx = max(mx, f(d+1, 1) + a[d+1][1]);
        mx = max(mx, f(d+1, 2) + a[d+1][2]);
        mx = max(mx, f(d+1, 3) + a[d+1][3]);
    }

    return dp[d][prev]= mx; 
}

int main()
{
    cin>>n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=3; j++) cin>>a[i][j];
    }
    
    memset(dp, -1, sizeof(dp));
    cout<<f(0, 0);
    return 0;
}
