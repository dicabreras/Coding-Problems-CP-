#include <bits/stdc++.h>
using namespace std;

#define ln '\n';
#define INF 1e9;
typedef long long ll;
const int mod = 1e9 + 7;

int main(){
    int n; cin>>n;
    string grid[n];
    int dp[n][n]={};

    for(int i = 0; i<n; i++) cin>>grid[i]; 
    if(grid[0][0] != '*') dp[0][0] = 1;
    for(int y = 0; y<n; y++){
        for(int x = 0; x<n; x++){
            if(grid[y][x] != '*'){
                if(y-1 >= 0) {
                    dp[y][x] += dp[y-1][x];
                    dp[y][x]%=mod;
                }
                if(x-1 >= 0) {
                    dp[y][x] += dp[y][x-1];
                    dp[y][x]%=mod;
                }
            }
        }
    }
    cout<<dp[n-1][n-1];

    return 0;
}