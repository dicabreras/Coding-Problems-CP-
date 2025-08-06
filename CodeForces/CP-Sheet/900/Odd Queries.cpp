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
    
    int t; cin>>t;
    while(t--){
        int n, q; cin>> n >> q;
        ll pfx_sums[n+1]={}; 
        for(int i = 1; i<=n; i++){
            ll a; cin>> a;
            pfx_sums[i] = pfx_sums[i-1] + a;
        }
        ll sum = pfx_sums[n];
        while(q--){
            ll l, r, k; 
            cin>> l >> r >> k;
            ll x = (r-l+1)*k;
            ll y = pfx_sums[r]-pfx_sums[l-1];
            ll result = sum-y;
            result+=x;
            if(result%2==1) cout<<yes<<ln;
            else cout<<no<<ln;
        }    
    }
    return 0;
}