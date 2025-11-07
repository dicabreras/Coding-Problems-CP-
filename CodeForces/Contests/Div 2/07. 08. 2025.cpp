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
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<pair<ll, ll>> v (n);
        for(int i = 0; i<n; i++){
            cin >> v[i].ff;
        }
        for(int i = 0; i<n; i++){
            cin >> v[i].ss;
            if(v[i].ss<v[i].ff){
                ll temp = v[i].ss;
                v[i].ss = v[i].ff;
                v[i].ff = temp;
            }
        }
        sort(v.begin(), v.end());
        int f = 0;
        for(int i = 0; i+1<n; i++){
            if(v[i+1].ff<=v[i].ss) f = 1;
        }
        ll ans = 0;
        if(!f){
            ll mn = 1e9+7;
            for(int i = 0; i+1<n; i++){
                mn = min(abs(v[i].ss-v[i+1].ff), mn);
            }
            ans+=2*mn;
        }
        for(int i = 0; i<n; i++){
            ans+=(abs(v[i].ff-v[i].ss));
        }
        cout<<ans<<ln;
    }
    return 0;
}