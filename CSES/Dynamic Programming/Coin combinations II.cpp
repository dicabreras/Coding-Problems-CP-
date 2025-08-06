#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main(){
    int n, x; cin>> n >>x;
    int a[n], dp[x+1];
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    for(int i = 0; i<n; i++)cin>>a[i];
    for(auto c : a){
        for(int sum = 1; sum<=x; sum++){
            if(sum-c >= 0){
                dp[sum]+=dp[sum-c];
                dp[sum]%=mod; 
            } 
        }
    }
    cout<<dp[x];
    return 0;
}
