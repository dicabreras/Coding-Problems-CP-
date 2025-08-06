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
        int n, k; cin >> n >> k;
        ll a[n], pfx_sum[n+1] = {};
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        sort(a, a+n); 
        for(int i = 0; i<n; i++) pfx_sum[i+1] = pfx_sum[i] + a[i];
        int l = 2*k, r = n;
        ll sum = pfx_sum[r] - pfx_sum[l];
        for(int i = 0; i<k; i++){
            sum = max(pfx_sum[r-1] - pfx_sum[l-2], sum);
            r--;
            l-=2;
        }
        cout<<sum<<ln;
    }
    return 0;
}
