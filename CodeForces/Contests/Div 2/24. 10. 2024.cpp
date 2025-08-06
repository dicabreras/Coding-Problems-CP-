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
        ll a[n+1], pfx_sum[n+1]={};
        for(int i = 1; i<=n; i++){
            cin>> a[i];
            pfx_sum[i] = a[i]+pfx_sum[i-1];
      
        }
    
        int ans = 0;
        set<ll> S; 
        for(int i = 0; i<=n; i++){
            if(S.count(pfx_sum[i])){
                ans++;
                S.clear();
                
            }
            S.insert(pfx_sum[i]);
        }
        cout<<ans<<ln;
    }    
    return 0;
}