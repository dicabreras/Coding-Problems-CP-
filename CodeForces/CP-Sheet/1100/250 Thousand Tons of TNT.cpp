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
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll a[n], pfx_sum[n+1] = {}; 
        for(int i = 0; i<n; i++){
            cin >> a[i];
            pfx_sum[i+1] = pfx_sum[i] + a[i];
        }
        vector<ll> d;
        for(ll i = 1; i<=n/2; i++){
            if(n%i == 0) d.pb(i);
        }
        ll ans = 0;
        for(auto k : d){
            ll mx = 0, mn = 1e16;
            for(int i = 1; i<=n; i+=k){
                mx = max(mx, pfx_sum[i+k-1] - pfx_sum[i-1]);
                mn = min(mn, pfx_sum[i+k-1] - pfx_sum[i-1]);
            }
            ans = max(ans, mx-mn);
        }
        cout<<ans<<ln;
        
    }    
    return 0;
}