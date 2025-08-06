#include <bits/stdc++.h>
using namespace std;

#define ln '\n';
#define INF 1e9;
typedef long long ll;
const int mod = 1e9 + 7;

//(0/1 Knapsack problem)   -   Saving memory space too by maintainig only 2 rows in the dp matrix

int main(){
    int n, x; cin>> n >> x; 
    int dp[2][x+1] = {};
    int h[n], s[n];
    for(int i = 0; i<n; i++) cin>>h[i];  
    for(int i = 0; i<n; i++) cin>>s[i];  
    
    for(int i = 1; i<=n; i++){
        int cost_i = h[i-1], reward_i = s[i-1]; 
        int ii = i%2, new_i = ii;
        for(int j = 0; j<=x; j++){
            if(ii==0)new_i = 2;
            if(j-cost_i>=0){
                dp[ii][j] = max(dp[new_i-1][j], reward_i + dp[new_i-1][j-cost_i]);     
            }
            else{
                dp[ii][j] = dp[new_i-1][j];
            }
        }
    }
    int y = n%2;
    cout<<dp[y][x];
    
    return 0;
}
