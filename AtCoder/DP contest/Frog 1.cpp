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
    
    
    int n; cin >> n; 
    int a[n];
    for(int i = 0; i<n; i++) cin >> a[i];
    int dp[n];
    dp[0] = 0; dp[1] = abs(a[1]-a[0]);
    for(int i = 2; i<n; i++){
        dp[i] = min(dp[i-2]+abs(a[i-2] - a[i]), dp[i-1] + abs(a[i-1] - a[i]));
    }
    cout<<dp[n-1];
        
    return 0;
}

