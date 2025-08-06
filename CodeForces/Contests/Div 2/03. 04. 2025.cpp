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
        ll n, k, x; cin >> n >> k >> x;
        ll a[n], sum = 0; 
        for(int i = 0; i<n; i++){
            cin >> a[i];
            sum += a[i];
        }
        ll q = x/sum, r = 0, y = sum*q;
        if(q>k || (q == k && y<x)){
            cout<<0<<ln;
            continue;
        }
        for(int i = 0; i<n && y<x; i++){
            y+=a[n-i-1];
            r++;
            if(y>=x) break;
        }
        r--;
        ll ans = n*k - n*q - r;
        cout<<ans<<ln;
    }
    return 0;
}