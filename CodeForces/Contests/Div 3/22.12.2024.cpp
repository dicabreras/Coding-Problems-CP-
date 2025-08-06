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
        ll n, x, y; cin >> n >> x >> y; 
        ll total = 0;
        ll a[n];
        map<ll, pi> m;
        for(int i = 0; i<n; i++) {
            ll x; cin >> x;
            a[i] = x;
            total+=x;
        }
        sort(a, a+n);
        for(ll i = 0; i<n; i++){
            if(!m.count(a[i])){
                m[a[i]] = {i, i};
            }
            else{
                ll p1 = m[a[i]].ff, p2 = m[a[i]].ss;
                m[a[i]] = {min(p1, i), max(p2, i)};
            }
        }

        ll ans = 0;

        for(int i = 0; i<n; i++){
            ll c = total-a[i], l, r, p = 0;
            r = abs(c-x);
            if(c<=y) l = 1;
            else{
                 l = abs(y-c);
            }
            while(r>=l){
                if(m.count(r)){
                    ll h = m[r].ss, k = m[l].ff;
                    p = m[r].ss - m[l].ff;
                    m[r].ss--;
                    break;
                }
                r--;
            }
            
            ans+=p;
        }
        
        cout<<ans<<ln;

    }
    return 0;
}