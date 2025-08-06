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
        ll a[n]; 
        for(int i = 0; i<n; i++) cin >> a[i];
        ll d1 = a[0], d2 = a[1];
        for(int i = 0; i<n; i+=2){
            d1 = gcd(a[i], d1);
        }
        for(int i = 1; i<n; i+=2){
            d2 = gcd(a[i], d2);
        }
        int f1 = 1, f2 = 1;
        for(int i = 0; i<n; i+=2){
            if(a[i]%d2 == 0) f1 = 0;
        }
        for(int i = 1; i<n; i+=2){
            if(a[i]%d1 == 0) f2 = 0;
        }
        if(f1 && f2){
            cout<<max(d1, d2)<<ln;
        }
        else if(f1){
            cout<<d2<<ln;
        }
        else if(f2){
            cout<<d1<<ln;
        }
        else cout<<0<<ln;
    }
    return 0;
}