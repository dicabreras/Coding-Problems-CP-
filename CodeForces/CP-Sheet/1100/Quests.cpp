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

int f(int* a, int i, int b){
    if(a[i-1]<=b-a[i]) return 1;
    return 0;
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
        int n, m; cin >> n >> m;
        int a[n], b[n], pfx_sum[n+1] = {}; 
        for(int i = 0; i<n; i++){
            cin >> a[i];
            pfx_sum[i+1] = pfx_sum[i] + a[i];
        }
        for(int i = 0; i<n; i++) cin >> b[i];

        int mx = 0, mxb = 0;
        for(int i = 0; i<min(m,n); i++){
            mxb = max(mxb, b[i]);
            int x = m-i-1;
            mx = max(mx, pfx_sum[i+1] + mxb*x);
        }
        cout<<mx<<ln;
    }    
    return 0;
}