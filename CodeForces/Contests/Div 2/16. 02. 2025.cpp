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
        int n; cin >> n;
        ll a[n], vn[n] = {}, vp[n] = {}, mx = -1;
        for(int i = 0; i<n; i++){
            cin >> a[i];
            if(a[i]<0) vn[i] = -a[i];
            else vp[i] = a[i];
        }
        ll pfx_sumN[n+1] = {}, pfx_sumP[n+1] = {};
        for(int i = n-1; i>=0; i--){
            pfx_sumN[i] = pfx_sumN[i+1] + vn[i];
        }
        for(int i = 0; i<n; i++){
            pfx_sumP[i+1] = pfx_sumP[i] + vp[i];
        }
        for(int i = 0; i<=n; i++){
            mx = max(pfx_sumP[i] + pfx_sumN[i], mx);
        }
        cout<<mx<<ln;
    }
        
    return 0;
}