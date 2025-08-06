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
    freopen("output.txt", "w", stdout);
    #endif
    */
    
    int n, q; cin >> n >> q; 
    ll a[n], b[n+1] = {}; 
    for(int i = 0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    while(q--){
        int l, r; cin >> l >> r; 
        l--;
        b[l]++;
        if(r+1>n) continue;
        b[r]--;
    }
    for(int i = 1; i<n; i++){
        b[i]+=b[i-1];
    }
    sort(b, b+n);
    ll sum = 0; 
    for(int i = 0; i<n; i++){
        sum+=(b[i]*a[i]);
    }
    cout<<sum;
    
    return 0;
}