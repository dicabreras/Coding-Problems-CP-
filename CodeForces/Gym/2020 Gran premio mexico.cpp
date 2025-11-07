/*
Coded by Diego Cabrera
Codeforces username : GAL1LEO-DC
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

int main(){
   // ios::sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */

    ll n, b; cin >> n >> b;
    ll a[n], ans[n]; 
    memset(ans, -1, sizeof(a));
    map<ll, vector<ll>> m; 
    for(ll i = 0; i<n; i++){
        cin >> a[i];
        m[a[i]].pb(i);
    }

    for(auto [i, v]: m){
        while(!v.empty()){
            if(i == 0){
                //cout<<"im 0"<<ln;
                for(auto h : v) ans[h] = 0;
                v.clear();
                continue;
            }
            ll j = v.back(), l = j-1, r = j+1;;
            //cout<<j<<ln;
            v.pop_back();
            if(l == -1) l = n-1;
            if(r == n) r = 0;
            ll mn = min(ans[l], ans[r]), mx = max(ans[l], ans[r]);
            if(mn == -1 && mx == -1){
                ans[j] = b;
                //cout<<"no adj"<<ln;
            }
            else{
                ans[j] = mx + b - (a[l] == a[j] || a[r] == a[j])*b;
            }
        }
    }
    for(int i = 0; i<n-1; i++) cout<<ans[i]<<" ";
    cout<<ans[n-1];

    return 0;
}