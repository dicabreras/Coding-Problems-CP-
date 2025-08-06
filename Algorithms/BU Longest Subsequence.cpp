#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int, int> vi;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ln '\n'
#define yes "YES"
#define no "NO"

const int M = 1e9+7;


int main(){
    int n; cin>>n;
    int A[n], dp[n] = {}, S[n], mx = 1, idx = 0;
    dp[0] = 1, S[0]= 0;
    for(int i = 0; i<n; i++) cin>>A[i];

    for(int k = 1; k<n; k++){
        dp[k] = 1; S[k] = k;
        for(int i = k-1; i>=0; i-- ){
            int temp = dp[k];
            if(A[k]>A[i]){
                temp = max(dp[k], dp[i]+1);
            }
            if(temp>dp[k]){
                dp[k]= temp;
                S[k] = i;
            }
        }
        if(dp[k]>mx) {
            mx = dp[k];        
            idx = k;
        }
    }
    cout<<mx<<ln;
    int LS[mx];
    for(int i = mx-1; i>=0; i--){
        LS[i] = A[idx];
        idx = S[idx]; 
    }
    for(auto a : LS) cout<<a<<" ";
    cout<<ln;

    return 0;
}