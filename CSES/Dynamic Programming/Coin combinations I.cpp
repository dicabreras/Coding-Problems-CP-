#include <bits/stdc++.h>
using namespace std;
/*

//Recursive solution

int dp[1000010]={};
int a[110], n;
const int m = 1e9+7;
int solve(int x){
    if(x == 0) return 1;  //trivial case
    if(dp[x]!=-1) return dp[x];
    int count = 0;
    for(int i = 0; i<n; i++){
        if(x-a[i]>=0){
            count+=solve(x-a[i]);
            count%=m;
        }  
    }
    dp[x]=count;
    return count;    
}

int main(){
    int x; cin>> n >> x; 
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i<n; i++)cin>>a[i];
    cout<<solve(x);
    return 0;
}
*/

// Iterative solution


const int m = 1e9 + 7;
int dp[1000020]={};

int main(){
  //  memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int n, x; cin>> n >> x; 
    int a[n];
    for(int i = 0; i<n; i++) cin>>a[i];

    for(int sum = 1; sum<=x; sum++){
        for(auto c : a){
            if(sum-c>=0){
                dp[sum]+=dp[sum-c];
                dp[sum]%=m;
            }
        }   
    }
    cout<<dp[x];
    
    return 0;
}
