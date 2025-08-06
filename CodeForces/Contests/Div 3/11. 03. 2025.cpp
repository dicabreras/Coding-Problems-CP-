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


ll f_sqrt(ll x){
    ll l = 0, r = 1e9;
    while(l+1<r){
        ll mid = l + (r-l)/2;
        if(mid*mid<=x) l = mid;
        else r = mid;
    }
    return l;
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
        int n, m; 
        cin >> n >> m;
        ll x[n], r[n];
        for(int i = 0; i<n; i++) cin >> x[i];
        for(int i = 0; i<n; i++) cin >> r[i];
        map<ll, ll> values;
        
        for(int i = 0; i<n; i++){
            ll xi = x[i], ri = r[i];
            for(ll j = xi-ri; j<=xi+ri; j++){
                ll z = ri*ri-(j-xi)*(j-xi);
                ll y = sqrt(z);
                //if(!values.count(j)) values[j] = y;
                values[j] = max(values[j], y);
            }
        }
        ll pnts = 0;
        for(auto i : values){
            // the 1 is added to regard de point on the x axis
            pnts+=(i.ss*2 + 1);
        }
        cout<<pnts<<ln;
    }
    return 0;
}