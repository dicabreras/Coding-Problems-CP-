/*
Coded by Diego Cabrera
*/
#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ln '\n'
#define yes "YES"
#define no "NO"
 
const int M = 1e9+7;

 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    
    int n, k; cin >> n >> k; 
    int a[n];
    for(int i = 0; i<n; i++) cin >> a[i];
    int dp[n];
    for(int i = 0; i<n; i++) dp[i] = 1e9+7;
    dp[0] = 0;
    for(int i = 1; i<n; i++){
        for(int j = 1; j<=k; j++){
            if(i-j>=0){
                dp[i] = min(dp[i-j] + abs(a[i-j] - a[i]), dp[i]);
            }
            else break;
        }
    }
    cout<<dp[n-1];
        
    return 0;
}