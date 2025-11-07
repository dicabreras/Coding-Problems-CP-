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

    int t; 
    cin >>t;
    while(t--){
        int n, k; 
        cin >> n >> k; 
        ll a[n];
        map<ll, ll> m; 
        for(int i = 0; i<n; i++){
            cin >> a[i];
            m[a[i]]++;
        }
        sort(a, a+n);
        ll num = 0, mx = -1, f = 1, mn = 1e6, g  = 0; 
        for(auto [x, cnt]: m){
            if(x!=num && f){
                mx = num;
                f = 0;
            }
            else{
                num++;
            }
            if(cnt>1){
                mn = min(mn, x);
                g = 1;
            }
        }
        if(mx == -1) mx = a[n-1]+1;
        if(!g) mn = mx+1;

       // mn = min(mn, mx);
        ll ans = 0;
        if(k == 1){
            for(int i = 0; i<n; i++){
                if(a[i]<mx && m[a[i]] == 1) ans+=a[i];
                else ans+=mx;
            }
        }
        else{
            if(mn<mx) mx = mn+1;
            ll x = mx;
            if(k%2 == 0) x = mn;
            mn = min(mn, mx);            
            for(int i = 0; i<n; i++){
                if(a[i]<mn) ans+=a[i];
                else ans+=x;
            }
        }
        cout<<ans<<ln;

    }
    

    return 0;
}
