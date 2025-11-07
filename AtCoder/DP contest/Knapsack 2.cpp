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

int a[101][2], dp[100007][101]; 
int n, mx = 0, sum_values = 0;
 

int f(int v, int i, int w){
    if(w==0 || i == n){
        mx = max(mx, sum_values-v);
        return 0;
    }
    if(dp[v][i] != -1) return dp[v][i];

    dp[v][i] = 1e9+7;

    if(w-a[i][0]>=0){
        dp[v][i] = min(dp[v][i], f(v-a[i][1], i+1, w-a[i][0]) + a[i][0]);
    }
    dp[v][i] = min(dp[v][i], f(v, i+1, w));
    
    return dp[v][i];
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
    int w;
    cin >> n >> w;

    for(int i = 0; i<n; i++){
        cin >> a[i][0];
        cin >> a[i][1];
        sum_values+=a[i][1];
    }

    f(sum_values, 0, w);
    cout<<mx; 

    return 0;
}

