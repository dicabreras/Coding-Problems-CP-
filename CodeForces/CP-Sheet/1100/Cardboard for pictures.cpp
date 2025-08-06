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
 
const int M = 1e9+7;

int f(ll* a, int n, int m, ll c){
    ll sum = 0;
    for(int i = 0; i<n; i++){
        sum+=((a[i]+2*m)*(a[i]+2*m));
        if(sum > c) return 0;
    }
    return 1;
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
        int n; 
        ll c; 
        cin >> n >> c;
        ll a[n];
        for(int i = 0; i<n; i++) cin >> a[i];
        int l = 0, r = 1e9+7;
        while(l+1<r){
            int mid = l + (r-l)/2;
            if(f(a, n, mid, c)) l = mid;
            else r = mid;
        }
        cout<<l<<ln;
    }
    return 0;
}