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

template <typename TT>
using min_heap = priority_queue<TT, vector<TT>, greater<TT>>;

const int M = 1e9+7;

ll a[101][2]; 
ll dp[100007][101];
int n; 

ll f(ll w, int i){
    if(w == 0 || i == n) return 0;
    if(dp[w][i]!=-1) return dp[w][i];
    //dp[w][i] = -1;
    
    if(w-a[i][0]>=0){
        dp[w][i] = max(dp[w][i], f(w-a[i][0], i+1) + a[i][1]);
    }
    dp[w][i]= max(dp[w][i], f(w, i+1));
    //dp[w][i] = mx;
    return dp[w][i];
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    memset(dp, -1, sizeof(dp));
    cin >> n; 
    ll w; cin >> w;
    for(int i = 0; i<n; i++){
        cin >> a[i][0];
        cin >> a[i][1];
    }
    ll ans = f(w, 0);
    cout<<ans;

    return 0;
}
