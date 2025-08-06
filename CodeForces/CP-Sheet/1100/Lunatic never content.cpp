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
        int a[n];
        vi v;
        for(int i = 0; i<n; i++) cin >> a[i];
        
        for(int i = 0; i<n/2; i++){
            if(a[i]!=a[n-i-1]) v.pb(max(a[i], a[n-i-1])-min(a[i], a[n-i-1]));
        }
        int d = 0;
        if(!v.empty()){
            d = v[0];
            for(auto i : v){
                d = gcd(d,i);
            }
        }
        cout<<d<<ln;
    }
    return 0;
}

