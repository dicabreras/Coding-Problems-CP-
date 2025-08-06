#include <bits/stdc++.h>
using namespace std;

#define ln '\n';
#define INF 1e9;
typedef long long ll;
const int mod = 1e9 + 7;

/*

//My recursive aproach seems not to work for numbers higher than 100000  :(

int dp[1000010]={};

int solve(int n){
    if(n == 0)return 0;
    if(dp[n] != 0) return dp[n];
    int mn = 1e6 + 7;
    
    int temp = n;  
    while(temp!=0){
        int d = temp%10;
        if(d!=0){
            mn = min(mn, solve(n-d)+1);
        }
        temp/=10;
    }
    dp[n] = mn;
    return mn;
}


int main(){
    int n; cin>>n;
    cout<<solve(n);

    return 0;
}
*/ 

// Iterative aproach

int main(){
    int n; cin>>n;
    int dp[n+1]={};
    for(int x = 1; x<=n; x++){
        int temp = x; 
        int mn = INF;
        while(temp>0){   //this takes log_10(x)
            int d = temp%10;
            if(d>0){
                mn = min(mn, dp[x-d]+1);
            }
            temp/=10;
        }
        dp[x] = mn;
    }
    cout<<dp[n];
    
    return 0;
}