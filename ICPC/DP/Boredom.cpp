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
    
    int n; cin>>n;
    ll a[n], mx = 1;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(a[i]>mx) mx = a[i];
    }
    ll cnt[mx+1] = {};
    for(auto x : a) cnt[x]++;
    
    ll dp[100010] = {};
    
    dp[1] = cnt[1];
    for(ll i = 2; i<=100000; i++){    
        dp[i] = max(dp[i-1], (cnt[i]*i) + dp[i-2]);
    }
    cout<<dp[mx];
    return 0;
}