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

ll f(ll* a, int n){
    ll k = 4;
    while(true){
        set<ll> s;
        s.insert(a[0]%k);
        int f = 1;
        for(int i = 1; i<n; i++){
            s.insert(a[i]%k);
            if(s.size()>2){
                k*=2;
                f = 0;
                break;
            }
        }
        if(s.size()==1){
            k*=2;
            f = 0;
        }
        if(f) return k;
    }
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
        int n, odd = 0, even = 0; cin >> n;
        ll a[n];
        for(int i = 0; i<n; i++){
            cin >> a[i];
            if(a[i]%2) odd = 1;
            else even = 1;
        }
        if(odd && even) cout<<2<<ln;
        else{
            ll k = f(a, n);
            cout<<k<<ln;
        }
    }
    return 0;
}