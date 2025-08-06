#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    int n, upper; cin>> n >> upper;
    int dp[n][upper+2]={};
    int a[n];
    for(int i = 0; i<n; i++)cin>>a[i];

    if(n==1){
        if(a[0]==0)cout<<upper;
        else cout<<1;
    }
    else{
        if(a[0]==0){
            for(int i = 1; i<=upper; i++)dp[0][i] = 1;
        }
        else dp[0][a[0]] = 1;

        for(int y = 1; y<n; y++){
            if(a[y]==0){
                for(int x = 1; x<=upper; x++){
                    dp[y][x] = dp[y-1][x-1];
                    dp[y][x]%=mod;
                    dp[y][x] += dp[y-1][x] ;
                    dp[y][x]%=mod;
                    dp[y][x] += dp[y-1][x+1];
                    dp[y][x]%=mod;
                }
            }
            else{
                dp[y][a[y]] = dp[y-1][a[y]-1];
                dp[y][a[y]]%=mod;
                dp[y][a[y]] += dp[y-1][a[y]];
                dp[y][a[y]]%=mod; 
                dp[y][a[y]] += dp[y-1][a[y]+1];
                dp[y][a[y]]%=mod;
            }
        }
        int ans=0;
        for(int i = 1; i<=upper; i++){
            ans+=dp[n-1][i];
            ans%=mod;
        }
        cout<<ans; 
    }
}
