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
        string s; cin >> s;
        int a[n], pfx_sum[n+1] = {};
        for(int i = 0; i<n; i++){
            if(s[i]=='B') a[i] = 0;
            else a[i] = 1;
            pfx_sum[i+1] = pfx_sum[i] + a[i];
        }
        int mn = 1e6, l = 0, r = l+k;
        while(r<=n){
            mn = min(pfx_sum[r]-pfx_sum[l], mn);
            l++;
            r++;
        }
        
        cout<<mn<<ln;
    }
    return 0;
}