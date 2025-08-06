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

ll f(int n){
    ll t = 1;
    for(int i = 0; i<n; i++) t*=2;
    return t;
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
        ll x, y; cin >> x >> y;
        ll a[60], b[60];
        memset(a, -1, sizeof(a));
        memset(b, -1, sizeof(b));
        if(x == 0)a[0] = 0;
        if(y == 0) b[0] = 0;
        for(int i = 0, j = 1; x/j>=0; i++){
            a[i] = x/j;
            j*=2;
            if(a[i]==0)break;
        }
        for(int i = 0, j = 1; y/j>=0; i++){
            b[i] = y/j;
            j*=2;
            if(b[i] == 0) break;
        }
        if(x==y){
            cout<<0<<ln;
            continue;
        }
        ll mn = LONG_LONG_MAX;
        for(int i = 0; i<60; i++){
            for(int j = 0; j<60; j++){
                if(a[i] == b[j] && a[i]>=0){
                    mn = min(mn, f(i)*(x>0) + f(j)*(y>0));
                }
            }
        }
        cout<<mn<<ln;
        
    }
    return 0;
}