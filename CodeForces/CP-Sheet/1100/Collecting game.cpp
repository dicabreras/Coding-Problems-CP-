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

int f(ll m, ll score, ll *a){
    if(a[m]<=score) return 1;
    return 0;
}

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
        ll a[n]; 
        map<ll, vi> m;
        for(int i = 0; i<n; i++){
            cin >> a[i];
            m[a[i]].pb(i);
        }
        
        sort(a, a+n);
        ll pfx_sum[n+1] = {}, ans[n]; 
        for(int i = 0; i<n; i++){
            pfx_sum[i+1] = pfx_sum[i] + a[i];
        }
        for(ll i = 1; i<=n; i++){
            ll score = pfx_sum[i], idx = i-1;    
            ll l = idx, r = n;
            while(l+1<r){
                ll mid = l + (r-l)/2;
                if(f(mid, score, a)){
                    l = mid;
                    score = pfx_sum[l+1];
                    r = n;
                }
                else r = mid;
            }
            int current = m[a[i-1]].back();
            ans[current] = l;
            m[a[i-1]].pop_back();
        }   
        for(auto i : ans) cout<<i<<" ";
        cout<<ln;
    }
    return 0;
}