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

int dp[100007][3] = {};
vector<vector<int>> a(100007, vector<int> (3)); // it can be an array as well 

int f(int d, int n, int k){
    int mx = 0;
    if(k == n){
        for(int i = 0; i<3; i++){
            if(i==d) continue;
            mx = max(mx, a[k][i]);
        }
        return mx;
    }
    if(dp[k][d] > 0) return dp[k][d];

    for(int i = 0; i<3; i++){
        if(i == d) continue;
        mx = max(a[k][i]+f(i, n, k+1), mx);
    }
    dp[k][d] = mx;
    return dp[k][d];

}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<3; j++){
            cin >> a[i][j];
        }
    }   
    int mx = 0;
    for(int i = 0; i<3; i++){
        mx = max(mx, f( i, n-1, 0));
    }
    cout<<mx;
    return 0;
}
