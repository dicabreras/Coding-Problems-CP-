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
    
    int t; cin>>t;
    while(t--){
        int n; cin>> n;
        int a[n];
        for(int i = 0; i<n; i++) cin>> a[i];
        int mx = 0, mxl = 0, mxr = 0;
        for(int i = 0, j = 1; j<n; i++, j++){
            if(a[i]-a[j] > mx) mx = a[i]-a[j];
            if(a[j]-a[0] > mxl) mxl = a[j]-a[0];
            if(a[n-1]-a[i] > mxr) mxr = a[n-1]-a[i];
        } 
        int ans = max(mx, max(mxl, mxr));
        cout<<ans<<ln;
        
    }
    return 0;
}