#include <bits/stdc++.h>
using namespace std; 

//Iterative implementation
const int m = 1e9 + 7;
const int a[] = {1, 2, 3, 4, 5, 6};
int dp[1000010] = {}; 

int main(){
    dp[0] = 1;
    int n; cin>>n;
    for(int x = 1; x<=n; x++){
        for(auto c : a){
            if(x-c>=0){
                dp[x]+=dp[x-c];
                dp[x]%=m;
            } 
        }
    }
    cout<<dp[n];
    
    return 0;
}
